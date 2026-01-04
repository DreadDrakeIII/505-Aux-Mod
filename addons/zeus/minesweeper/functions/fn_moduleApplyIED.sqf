params ["_logic", "_units", "_activated"];
if (!_activated) exitWith { true };

private _targets = [];

// Zeus + Eden: if the module is attached to an object, use that first
private _attached = attachedTo _logic;
if (!isNull _attached) then {
    _targets pushBackUnique _attached;
};

// Eden case if needed
{
    if (!isNull _x && { _x != _logic }) then {
        _targets pushBackUnique _x;
    };
} forEach _units;

// Fallback to nearby objects
if (_targets isEqualTo []) then {
    private _pos = getPosWorld _logic;

    private _candidates = nearestObjects [
        _pos,
        ["AllVehicles", "CAManBase", "Thing"],
        3
    ];

    _candidates = _candidates select { _x != _logic && {!isNull _x} };

    if (_candidates isNotEqualTo []) then {
        _targets pushBackUnique (_candidates select 0);
    };
};

// No valid targets at all
if (_targets isEqualTo []) exitWith {
    ["505th: No valid targets for Minesweeper IED module"]
        remoteExec ["systemChat", 0, false];
    deleteVehicle _logic;
    true
};

// Create ZEN dialog for configuration
[
    "Minesweeper IED Configuration",
    [
        [
            "COMBO",
            ["Difficulty Preset", "Select a preset difficulty or choose Custom to use sliders below"],
            [
                [0, 1, 2, 3, 4],
                ["Easy (10 mines, 55s)", "Medium (12 mines, 70s)", "Hard (14 mines, 105s)", "Extreme (17 mines, 140s)", "Custom (Use Sliders)"],
                1
            ]
        ],
        [
            "SLIDER",
            ["Custom Bomb Count", "Number of bombs in the grid"],
            [1, 80, 12, 0]
        ],
        [
            "SLIDER",
            ["Custom Timer (seconds)", "Time to defuse in seconds"],
            [10, 240, 90, 0]
        ],
        [
            "COMBO",
            ["Explosion Size", "Select the size of the explosion when IED detonates"],
            [
                ["SmallSecondary", "ammo_Bomb_SDB", "HelicopterExploSmall", "Bo_GBU12_LGB"],
                ["Small (Hand Grenade)", "Medium (Small Bomb)", "Large (Helicopter Explosion)", "Huge (GBU-12)"],
                1
            ]
        ],
        [
            "CHECKBOX",
            ["Enable Motion Sensor", "If enabled, IED will explode when units move near it at speed"],
            false
        ],
        [
            "CHECKBOX",
            ["Audible Before Defusal", "If enabled, IED beeps before anyone starts defusing"],
            false
        ]
    ],
    {
        // On Confirm
        params ["_values", "_args"];
        _values params ["_presetIndex", "_customBombs", "_customTimer", "_explosionType", "_proximityEnabled", "_audibleBeforeDefusal"];
        _args params ["_targets", "_logic"];
        
        private _mineCount = 12;
        private _timer = 120;
        
        // Check if Custom is selected
        if (_presetIndex == 4) then {
            _mineCount = round _customBombs;
            _timer = round _customTimer;
        } else {
            switch (_presetIndex) do {
                case 0: { _mineCount = 10; _timer = 55; };
                case 1: { _mineCount = 12; _timer = 70; };
                case 2: { _mineCount = 15; _timer = 105; };
                case 3: { _mineCount = 17; _timer = 140; };
            };
        };

        // Motion sensor: sideEmpty = disabled, west = enabled for BLUFOR
        private _side = if (_proximityEnabled) then { west } else { sideEmpty };
        
        // Apply to all targets
        {
            [_x, _mineCount, _timer, _explosionType, _side, _audibleBeforeDefusal] remoteExec ["505th_fnc_Minesweeper", 0, true];
        } forEach _targets;
        
        deleteVehicle _logic;
    },
    {
        // On Cancel
        params ["_values", "_args"];
        _args params ["_targets", "_logic"];
        
        ["505th: Minesweeper IED module cancelled"] remoteExec ["systemChat", 0, false];
        deleteVehicle _logic;
    },
    [_targets, _logic]
] call zen_dialog_fnc_create;

true
