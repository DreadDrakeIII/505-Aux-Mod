// OLI_KCS - postInit: server event handlers + legacy variable-name lane scan

// ---------------------------------------------------------------------------
// SERVER: spawn / preset / clear events (all unit creation is server-side)
// ---------------------------------------------------------------------------
if (isServer) then {

    // [computer, severity (0=random), mechanism (0=random),
    //  count (1=single, 0=random 2-8, n=exact)]
    ["OLI_KCS_spawn", {
        params ["_computer", "_severity", "_mechanism", "_count"];
        if (isNull _computer) exitWith {};

        [_computer] call OLI_KCS_fnc_clearPatients;

        if (_count == 0) then { _count = 2 + floor random 7; };   // 2-8

        ([_computer] call OLI_KCS_fnc_getSpawnArea) params ["_center", "_halfX", "_halfY", "_ref", "_maxR"];
        private _minSpacing = missionNamespace getVariable ["OLI_KCS_MinSpacing", 0.5];
        private _used = [];
        private _patients = [];

        for "_i" from 0 to (_count - 1) do {
            // casualty 1 dead centre; the rest random inside the area,
            // >= spacing apart, packing tighter if the area is too small
            private _pos = _center;
            if (_i > 0) then {
                private _best = _center;
                private _bestDist = -1;
                for "_try" from 1 to 40 do {
                    // custom mode: uniform inside a circle; box mode: inside
                    // the (rotated) bounding-box footprint
                    private _cand = if (_maxR > 0) then {
                        private _d = _maxR * sqrt random 1;
                        private _a = random 360;
                        _center vectorAdd [_d * sin _a, _d * cos _a, 0]
                    } else {
                        private _ofs = _ref vectorModelToWorld [
                            -_halfX + random (2 * _halfX),
                            -_halfY + random (2 * _halfY),
                            0
                        ];
                        _center vectorAdd [_ofs select 0, _ofs select 1, 0]
                    };
                    private _nearest = 1e6;
                    { _nearest = _nearest min (_cand distance2D _x); } forEach _used;
                    if (_nearest >= _minSpacing) exitWith { _best = _cand; };
                    if (_nearest > _bestDist) then { _bestDist = _nearest; _best = _cand; };
                };
                _pos = _best;
            };
            _used pushBack _pos;

            private _sev = _severity;
            if (_sev == 0) then { _sev = 1 + floor random 3; };
            private _mech = _mechanism;

            private _p = [_pos, {
                params ["_p"];
                [
                    _p,
                    _p getVariable ["OLI_KCS_PlannedSeverity", 1],
                    _p getVariable ["OLI_KCS_PlannedMechanism", 0]
                ] call OLI_KCS_fnc_applyRandomWounds;
            }] call OLI_KCS_fnc_createPatient;
            _p setVariable ["OLI_KCS_PlannedSeverity", _sev];
            _p setVariable ["OLI_KCS_PlannedMechanism", _mech];
            _patients pushBack _p;
        };

        _computer setVariable ["OLI_KCS_ActivePatients", _patients, true];
    }] call CBA_fnc_addEventHandler;

    // [computer, presetIndex]
    ["OLI_KCS_preset", {
        params ["_computer", "_presetIndex"];
        if (isNull _computer) exitWith {};
        if (_presetIndex < 0 || {_presetIndex >= count OLI_KCS_Presets}) exitWith {};

        [_computer] call OLI_KCS_fnc_clearPatients;

        ([_computer] call OLI_KCS_fnc_getSpawnArea) params ["_center"];
        private _code = (OLI_KCS_Presets select _presetIndex) select 2;
        private _p = [_center, _code] call OLI_KCS_fnc_createPatient;
        _computer setVariable ["OLI_KCS_ActivePatients", [_p], true];
    }] call CBA_fnc_addEventHandler;

    // [computer]
    ["OLI_KCS_clear", {
        params ["_computer"];
        if (isNull _computer) exitWith {};
        [_computer] call OLI_KCS_fnc_clearPatients;
    }] call CBA_fnc_addEventHandler;
};

// ---------------------------------------------------------------------------
// CLIENTS: legacy lane support - objects named KCS_Computer<N> paired with
// KCS_TrainingSpot<N> get the same menu as the placeable computer class.
// Rescans every 15 s so lanes named mid-mission (ZEN etc.) work too.
// ---------------------------------------------------------------------------
if (hasInterface) then {
    private _scanThread = [] spawn {
        // wait for settings replication before reading the toggle
        waitUntil {sleep 1; !isNil "OLI_KCS_LegacyScan"};
        while {missionNamespace getVariable ["OLI_KCS_LegacyScan", true]} do {
            for "_i" from 1 to 99 do {
                private _comp = missionNamespace getVariable [format ["KCS_Computer%1", _i], objNull];
                private _spot = missionNamespace getVariable [format ["KCS_TrainingSpot%1", _i], objNull];
                if (!isNull _comp && {!isNull _spot}) then {
                    [_comp, _spot] call OLI_KCS_fnc_addComputer;
                };
            };
            sleep 15;
        };
    };
};
