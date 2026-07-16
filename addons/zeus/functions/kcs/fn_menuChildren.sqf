// OLI_KCS - CLIENT: build the full "Casualty Spawner" menu tree.
// Called by the ACE insertChildren of the root action every time the
// interact menu opens, so everything (incl. per-patient heal entries)
// is always current. Entries are [action, childrenArray, targetObject].
//
// Arguments: 0: computer <OBJECT>, 1: player (unused) <OBJECT>
// Returns: children entries <ARRAY>

params ["_computer"];

private _tree = [];

// ---------------- Spawn Casualty (single) ----------------
private _sevNodes = [];
{
    _x params ["_sev", "_sevName"];
    private _mechNodes = [];
    {
        private _mech = _x;
        (OLI_KCS_MechanismTable get _mech) params ["_mechName"];
        _mechNodes pushBack [
            [
                format ["OLI_KCS_Spawn_%1_%2", _sev, _mech], _mechName, "",
                {
                    params ["_target", "", "_args"];
                    _args params ["_sev", "_mech"];
                    ["OLI_KCS_spawn", [_target, _sev, _mech, 1]] call CBA_fnc_serverEvent;
                },
                {true}, {}, [_sev, _mech]
            ] call ace_interact_menu_fnc_createAction,
            [], _computer
        ];
    } forEach (OLI_KCS_MechanismsBySeverity select (_sev - 1));

    _sevNodes pushBack [
        [
            format ["OLI_KCS_Spawn_%1", _sev], _sevName, "",
            {
                params ["_target", "", "_args"];
                _args params ["_sev"];
                ["OLI_KCS_spawn", [_target, _sev, 0, 1]] call CBA_fnc_serverEvent;
            },
            {true}, {}, [_sev]
        ] call ace_interact_menu_fnc_createAction,
        _mechNodes, _computer
    ];
} forEach [[1, "Routine"], [2, "Priority"], [3, "Expectant"]];

_tree pushBack [
    [
        "OLI_KCS_Spawn", "Spawn Casualty", "",
        { params ["_target"]; ["OLI_KCS_spawn", [_target, 0, 0, 1]] call CBA_fnc_serverEvent; },
        {true}
    ] call ace_interact_menu_fnc_createAction,
    _sevNodes, _computer
];

// ---------------- Spawn Multiple (MASCAL) ----------------
private _countNodes = [];
for "_n" from 2 to 8 do {
    private _sevSub = [];
    {
        _x params ["_sev", "_sevName"];
        _sevSub pushBack [
            [
                format ["OLI_KCS_Multi_%1_%2", _n, _sev], _sevName, "",
                {
                    params ["_target", "", "_args"];
                    _args params ["_n", "_sev"];
                    ["OLI_KCS_spawn", [_target, _sev, 0, _n]] call CBA_fnc_serverEvent;
                },
                {true}, {}, [_n, _sev]
            ] call ace_interact_menu_fnc_createAction,
            [], _computer
        ];
    } forEach [[0, "Mixed"], [1, "Routine"], [2, "Priority"], [3, "Expectant"]];

    _countNodes pushBack [
        [
            format ["OLI_KCS_Multi_%1", _n], format ["%1 Casualties", _n], "",
            {
                params ["_target", "", "_args"];
                _args params ["_n"];
                ["OLI_KCS_spawn", [_target, 0, 0, _n]] call CBA_fnc_serverEvent;
            },
            {true}, {}, [_n]
        ] call ace_interact_menu_fnc_createAction,
        _sevSub, _computer
    ];
};

_tree pushBack [
    [
        "OLI_KCS_Multi", "Spawn Multiple", "",
        { params ["_target"]; ["OLI_KCS_spawn", [_target, 0, 0, 0]] call CBA_fnc_serverEvent; },
        {true}
    ] call ace_interact_menu_fnc_createAction,
    _countNodes, _computer
];

// ---------------- Spawn Scenario (presets, KAT only) ----------------
if (OLI_KCS_KatLoaded) then {
    private _presetNodes = [];
    {
        _x params ["_id", "_label"];
        _presetNodes pushBack [
            [
                format ["OLI_KCS_Preset_%1", _id], _label, "",
                {
                    params ["_target", "", "_args"];
                    _args params ["_idx"];
                    ["OLI_KCS_preset", [_target, _idx]] call CBA_fnc_serverEvent;
                },
                {true}, {}, [_forEachIndex]
            ] call ace_interact_menu_fnc_createAction,
            [], _computer
        ];
    } forEach OLI_KCS_Presets;

    _tree pushBack [
        ["OLI_KCS_Scenario", "Spawn Scenario", "", {}, {true}] call ace_interact_menu_fnc_createAction,
        _presetNodes, _computer
    ];
};

// ---------------- Heal ----------------
private _healNodes = [];
{
    _healNodes pushBack [
        [
            format ["OLI_KCS_Heal_%1", _forEachIndex], name _x, "",
            {
                params ["", "", "_args"];
                _args params ["_p"];
                ["ace_medical_treatment_fullHealLocal", [_p], _p] call CBA_fnc_targetEvent;
            },
            {true}, {}, [_x]
        ] call ace_interact_menu_fnc_createAction,
        [], _computer
    ];
} forEach ([_computer] call OLI_KCS_fnc_livePatients);

_tree pushBack [
    [
        "OLI_KCS_Heal", "Heal Casualties", "",
        {
            params ["_target"];
            {
                ["ace_medical_treatment_fullHealLocal", [_x], _x] call CBA_fnc_targetEvent;
            } forEach ([_target] call OLI_KCS_fnc_livePatients);
        },
        { params ["_target"]; ([_target] call OLI_KCS_fnc_livePatients) isNotEqualTo [] }
    ] call ace_interact_menu_fnc_createAction,
    _healNodes, _computer
];

// ---------------- Delete ----------------
_tree pushBack [
    [
        "OLI_KCS_Clear", "Delete Casualties", "",
        { params ["_target"]; ["OLI_KCS_clear", [_target]] call CBA_fnc_serverEvent; },
        {
            params ["_target"];
            ((_target getVariable ["OLI_KCS_ActivePatients", []]) findIf {!isNull _x}) > -1
        }
    ] call ace_interact_menu_fnc_createAction,
    [], _computer
];

_tree
