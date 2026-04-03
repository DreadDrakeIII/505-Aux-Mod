#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_executeSupplyDrop
 * Spawns a supply pallet or crate at 1000m altitude.
 * Freefalls to 300m AGL, then deploys parachute.
 * Wind affects drift during chute phase.
 * Orange smoke particle effect + IR strobe on landing.
 *
 * Arguments:
 *   0: Drop position (ground level) <ARRAY>
 *   1: Drop type — "pallet" or "crate" <STRING>
 *
 * Called from: fnc_zeusSupplyDrop (Zeus module) or directly via script
 */

params [
    ["_groundPos", [0, 0, 0], [[]]],
    ["_type", "pallet", [""]]
];

if (_groundPos isEqualTo [0, 0, 0]) exitWith {};

// ── Configuration ────────────────────────────────────────────────────────────
private _startAltitude = 1000;   // Start height AGL
private _chuteAltitude = 300;    // Deploy parachute at this AGL
private _classname = switch (_type) do {
    case "pallet": { QCLASS(EngineerSupplyPallet) };
    case "crate":  { QCLASS(EngineerSupplyCrate)  };
    default        { QCLASS(EngineerSupplyPallet) };
};

private _dropLabel = switch (_type) do {
    case "pallet": { "Engineer Supply Pallet" };
    case "crate":  { "Engineer Supply Crate"  };
    default        { "Engineer Supply Pallet" };
};

// ── Execute on server ────────────────────────────────────────────────────────
if (!isServer) exitWith {
    [_groundPos, _type] remoteExec [QFUNC(executeSupplyDrop), 2];
};

// ── Spawn the drop ───────────────────────────────────────────────────────────
[_groundPos, _startAltitude, _chuteAltitude, _classname, _dropLabel, _type] spawn {
    params ["_groundPos", "_startAlt", "_chuteAlt", "_classname", "_dropLabel", "_type"];

    // Calculate start position at altitude
    private _terrainH = getTerrainHeightASL _groundPos;
    private _startPos = +_groundPos;
    _startPos set [2, _terrainH + _startAlt];

    // Create the supply object
    private _supply = createVehicle [_classname, ASLToAGL _startPos, [], 0, "CAN_COLLIDE"];
    if (isNull _supply) exitWith {
        diag_log format ["OLI_engtools: Supply drop FAILED — could not create %1", _classname];
    };
    _supply allowDamage false;
    _supply setPosASL _startPos;

    // Mark as airdrop (so initSupplyPallet doesn't also attach a chute)
    _supply setVariable [QGVAR(isAirdrop), true, true];

    // Notify Zeus
    hint parseText format [
        "<t color='#FFA500'>%1 INBOUND</t><br/><t color='#AAAAAA'>Dropping from %2m — chute deploys at %3m</t>",
        toUpper _dropLabel, _startAlt, _chuteAlt
    ];

    diag_log format ["OLI_engtools: Supply drop — %1 at %2, start %3m, chute %4m",
        _dropLabel, _groundPos, _startAlt, _chuteAlt];

    // ── PHASE 1: Freefall from 1000m to 300m AGL ────────────────────────────
    // Give it downward velocity — no parachute yet
    _supply setVelocity [0, 0, -80];

    waitUntil {
        sleep 0.1;
        if (isNull _supply) exitWith { true };
        private _pos = getPosASL _supply;
        private _agl = (_pos select 2) - (getTerrainHeightASL _pos);

        // Keep pushing down if velocity slows (drag)
        if (_agl > _chuteAlt + 50) then {
            private _vel = velocity _supply;
            if ((_vel select 2) > -30) then {
                _supply setVelocity [_vel select 0, _vel select 1, -60];
            };
        };

        _agl <= _chuteAlt
    };

    if (isNull _supply) exitWith {};

    // ── PHASE 2: Deploy parachute at 300m AGL ───────────────────────────────
    // Liberation pattern: create chute with "NONE", setDir, setVelocity, attachTo
    _supply setVelocity [0, 0, 0];

    private _chute = createVehicle ["B_Parachute_02_F", _supply, [], 0, "NONE"];
    _chute setDir getDir _supply;
    _chute setVelocity [0, 0, -1];
    _supply attachTo [_chute, [0, 0, 1]];

    if (isNull _chute) exitWith {
        diag_log "OLI_engtools: Supply drop FAILED — could not create parachute";
    };

    // ── PHASE 3: Drift down with wind until near ground ─────────────────────
    // Use CBA waitUntilAndExecute pattern from Liberation for reliability
    [{
        params ["_supply", "_chute"];
        isNull _supply || isNull _chute
        || { (isTouchingGround _supply) || ((getPosATL _supply select 2) < 3) }
    }, {
        params ["_supply", "_chute", "_dropLabel"];

        if (isNull _supply) exitWith {};

        // ── PHASE 4: Landing sequence ───────────────────────────────────────
        detach _supply;

        // Level and ground the object
        _supply setVectorUp [0, 0, 1];
        private _landPos = getPos _supply;
        _landPos set [2, 0];
        _supply setPos _landPos;
        _supply allowDamage true;

        // Delete parachute
        if (!isNull _chute) then { deleteVehicle _chute };

        // ── Orange smoke — Liberation pattern: create + attachTo ─────────────
        private _smoke = createVehicle ["SmokeShellOrange", getPosATL _supply];
        _smoke attachTo [_supply];

        // ── IR Strobe for night visibility ───────────────────────────────────
        private _strobe = createVehicle ["PortableHelipadLight_01_white_F", getPos _supply, [], 0, "CAN_COLLIDE"];

        // ── Notify players within 3km ────────────────────────────────────────
        {
            if (isPlayer _x && { _x distance (getPos _supply) < 3000 }) then {
                [parseText format [
                    "<t color='#FFA500'>SUPPLY DROP LANDED</t><br/>" +
                    "<t color='#55CC66'>%1 on the ground</t><br/>" +
                    "<t color='#AAAAAA'>Orange smoke marks the position</t>",
                    _dropLabel
                ]] remoteExec ["hintSilent", _x];
            };
        } forEach allPlayers;

        diag_log format ["OLI_engtools: Supply drop landed at %1", getPos _supply];

    }, [_supply, _chute, _dropLabel], 120, {
        // Timeout fallback (120s) — force land if something goes wrong
        params ["_supply", "_chute"];
        if (!isNull _supply) then {
            detach _supply;
            private _smoke = createVehicle ["SmokeShellOrange", getPosATL _supply];
            _smoke attachTo [_supply];
        };
        if (!isNull _chute) then { deleteVehicle _chute };
    }] call CBA_fnc_waitUntilAndExecute;
};
