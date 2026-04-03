#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_initSupplyPallet
 * Server-side init for the Engineer Supply Pallet.
 * Pre-loads 4x Engineer Supply Crates into the pallet via ACE cargo.
 * Watches for unloaded crates and calls initSupplyCrate on each.
 *
 * Features:
 * - Instant cargo loading (no waiting for ACE API — direct variable manipulation)
 * - If pallet is in the air (Zeus airdrop / sling load), attaches a parachute
 *   and triggers orange smoke on landing
 *
 * Notes:
 * - ACE cargo API (setSpace/loadItem) does not work on OPTRE/TCP-derived classes
 *   so we bypass it entirely and set the cargo variables directly
 * - Crate classname uses QCLASS macro to match actual compiled class prefix
 */

params [["_pallet", objNull, [objNull]]];
if (isNull _pallet) exitWith {};
if (!isServer) exitWith {};

if (_pallet getVariable [QGVAR(palletInit), false]) exitWith {};
_pallet setVariable [QGVAR(palletInit), true, true];

[_pallet] spawn {
    params ["_pallet"];

    // ── STEP 0: Wait for ACE Cargo functions to exist ────────────────────────
    private _timeout = diag_tickTime + 10;
    waitUntil {
        sleep 0.1;
        isNull _pallet
        || { !isNil "ace_cargo_fnc_setSize" }
        || { diag_tickTime > _timeout }
    };
    if (isNull _pallet) exitWith {};

    // ── STEP 1: Force cargo space directly (ACE API fails on TCP classes) ────
    _pallet setVariable ["ace_cargo_loaded", [], true];
    _pallet setVariable ["ace_cargo_space", 24, true];
    _pallet setVariable ["ace_cargo_hasCargo", true, true];

    // ── STEP 2: Create & load 4 small supply crates (instant) ────────────────
    private _crates = [];
    for "_i" from 1 to 4 do {
        if (isNull _pallet) exitWith {};
        private _crate = QCLASS(EngineerSupplyCrate) createVehicle [0, 0, 0];
        if (isNull _crate) then { continue };
        _crate allowDamage false;

        // Set ACE cargo variables directly
        _crate setVariable ["ace_cargo_size", 6, true];
        _crate setVariable ["ace_cargo_canLoad", true, true];

        // Push into pallet cargo array
        private _loaded = _pallet getVariable ["ace_cargo_loaded", []];
        _loaded pushBack _crate;
        _pallet setVariable ["ace_cargo_loaded", _loaded, true];

        // Deduct cargo space
        private _space = _pallet getVariable ["ace_cargo_space", 24];
        _pallet setVariable ["ace_cargo_space", (_space - 6) max 0, true];

        // Hide crate inside pallet
        _crate attachTo [_pallet, [0, 0, -100]];
        hideObjectGlobal _crate;

        _crates pushBack _crate;
    };

    diag_log format ["OLI_engtools: Pallet %1 loaded with %2 crates, space left: %3",
        _pallet, count _crates, _pallet getVariable ["ace_cargo_space", 0]];

    // ── STEP 3: Parachute & smoke if pallet is airborne ──────────────────────
    // Skip if this pallet was spawned by the airdrop module (already has a chute)
    private _isAirdrop = _pallet getVariable [QGVAR(isAirdrop), false];

    if (!_isAirdrop) then {
    // Detects if pallet was placed in the air (Zeus manual placement, sling load release, etc.)
    private _posASL = getPosASL _pallet;
    private _altitude = (_posASL select 2) - (getTerrainHeightASL _posASL);

    if (_altitude > 5) then {
        // Attach a steerable parachute
        private _chute = createVehicle ["B_Parachute_02_F", getPos _pallet, [], 0, "FLY"];
        _pallet attachTo [_chute, [0, 0, 0]];

        // Wait until pallet is near ground
        waitUntil {
            sleep 0.5;
            isNull _pallet || isNull _chute || {
                private _pos = getPosASL _pallet;
                ((_pos select 2) - (getTerrainHeightASL _pos)) < 3
            }
        };

        if (!isNull _pallet) then {
            // Detach from chute
            detach _pallet;
            _pallet setVectorUp [0, 0, 1];

            // Set pallet on ground properly
            private _pos = getPos _pallet;
            _pos set [2, 0];
            _pallet setPos _pos;

            // Delete parachute
            if (!isNull _chute) then { deleteVehicle _chute };

            // Spawn orange smoke — Liberation pattern: create + attachTo
            private _smoke = createVehicle ["SmokeShellOrange", getPosATL _pallet];
            _smoke attachTo [_pallet];

            // Notify nearby players
            [[_pallet], {
                params ["_pallet"];
                if (player distance _pallet < 2000) then {
                    hint parseText "<t color='#FFA500'>Engineer Supply Pallet</t><br/><t color='#AAAAAA'>Supply drop has landed!</t>";
                };
            }] remoteExec ["call", 0];
        };
    };
    }; // end !_isAirdrop guard

    // ── STEP 4: Poll — when a crate is unloaded from pallet, init it ─────────
    private _initiated = [];
    while { !isNull _pallet && { count _initiated < count _crates } } do {
        sleep 1;
        if (isNull _pallet) exitWith {};

        private _loaded = _pallet getVariable ["ace_cargo_loaded", []];

        {
            private _crate = _x;
            if (!(_crate in _initiated) && { !isNull _crate } && { !(_crate in _loaded) }) then {
                [_crate] call FUNC(initSupplyCrate);
                _initiated pushBack _crate;
            };
        } forEach _crates;
    };
};
