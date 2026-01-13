disableSerialization;

params [
    ["_x", 0, [0]],
    ["_y", 0, [0]]
];

private _display = findDisplay 55500;
if (isNull _display) exitWith {controlNull};

// IDC scheme: 1000 + (x * 100) + y
// Supports grids up to 99x99
private _fieldNumber = 1000 + (_x * 100) + _y;
_display displayCtrl _fieldNumber
