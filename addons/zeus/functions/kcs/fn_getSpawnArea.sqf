// OLI_KCS - resolve the spawn area for a training computer.
//
// Spot resolution priority:
//   1. Explicit link:  computer setVariable ["OLI_KCS_Spot", someObject]
//      (set by the legacy scan / OLI_KCS_fnc_addComputer)
//   2. Nearest OLI_KCS_TrainingSpot within the pairing range (live lookup,
//      so dragging the spot around in Zeus just works)
//   3. Fallback: centred a few metres in front of the computer
//
// Area size ("Spawning radius" setting):
//   - Training Spot Bounding Box: the spot's footprint (min area floor)
//   - Custom: a circle of "Custom spawning radius" metres around the centre
//
// Arguments: 0: computer <OBJECT>
// Returns: [center ATL <ARRAY>, halfX <NUMBER>, halfY <NUMBER>,
//           reference object <OBJECT>, maxRadius (0 = box mode) <NUMBER>]

params ["_computer"];

private _minExtent = missionNamespace getVariable ["OLI_KCS_MinSpawnExtent", 2];

private _spot = _computer getVariable ["OLI_KCS_Spot", objNull];
if (isNull _spot) then {
    private _range = missionNamespace getVariable ["OLI_KCS_PairRange", 30];
    private _near = nearestObjects [_computer, ["OLI_KCS_TrainingSpot"], _range];
    if (_near isNotEqualTo []) then { _spot = _near select 0; };
};

// centre: the spot if present, else a point in front of the computer
private _center = if (!isNull _spot) then {
    getPosATL _spot
} else {
    private _c = getPosATL _computer;
    private _v = vectorDir _computer;
    _c vectorAdd [(_v select 0) * (_minExtent + 2), (_v select 1) * (_minExtent + 2), 0]
};

// custom radius mode: circular area around the centre
if ((missionNamespace getVariable ["OLI_KCS_SpawnAreaMode", 0]) == 1) exitWith {
    private _r = missionNamespace getVariable ["OLI_KCS_CustomSpawnRadius", 6];
    [_center, _r, _r, [_computer, _spot] select (!isNull _spot), _r]
};

// bounding-box mode
if (!isNull _spot) exitWith {
    (boundingBoxReal _spot) params ["_bbMin", "_bbMax"];
    [
        _center,
        ((((_bbMax select 0) - (_bbMin select 0)) / 2) max _minExtent),
        ((((_bbMax select 1) - (_bbMin select 1)) / 2) max _minExtent),
        _spot,
        0
    ]
};

// no spot: minimum-size box in front of the computer
[_center, _minExtent, _minExtent, _computer, 0]
