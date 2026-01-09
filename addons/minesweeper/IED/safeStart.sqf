disableSerialization;
#include "defines.def"

params ["_ied", "_x", "_y"];

// -----------------------------------------------------
// 1) Clear bombs from the 3x3 zone and count them
// -----------------------------------------------------
private _removedBombs = [];

for "_xx" from (_x - 1) to (_x + 1) do {
    for "_yy" from (_y - 1) to (_y + 1) do {

        if (_xx >= 1 && _xx <= 9 && _yy >= 1 && _yy <= 9) then {
            private _vn  = format ["ShoterIed_Value%1%2", _xx, _yy];
            private _val = _ied getVariable [_vn, "E"];

            if (_val isEqualTo "B") then {
                _removedBombs pushBack [_xx, _yy];      // remember we removed a bomb
                _ied setVariable [_vn, "E", false];     // clear it to empty
            };
        };
    };
};

private _bombsToReposition = count _removedBombs;
if (_bombsToReposition == 0) exitWith {
    // No bombs were in the 3x3; the board is already consistent.
    // Numbers are already correct; nothing to recompute.
};

// -----------------------------------------------------
// 2) Collect all possible tiles OUTSIDE the 3x3 that are empty
// -----------------------------------------------------
private _candidates = [];

for "_xx" from 1 to 9 do {
    for "_yy" from 1 to 9 do {

        // skip the safe 3x3 zone
        private _inSafeZone = (
            _xx >= (_x - 1) && _xx <= (_x + 1) &&
            _yy >= (_y - 1) && _yy <= (_y + 1)
        );

        if (!_inSafeZone) then {
            private _vn  = format ["ShoterIed_Value%1%2", _xx, _yy];
            private _val = _ied getVariable [_vn, "E"];

            // only empty tiles are valid for new bombs
            if (_val isEqualTo "E") then {
                _candidates pushBack [_xx, _yy];
            };
        };
    };
};

// -----------------------------------------------------
// 3) Reposition exactly that many bombs to random candidate tiles
// -----------------------------------------------------
for "_i" from 1 to _bombsToReposition do {
    if (_candidates isEqualTo []) exitWith {};  // nowhere left to place, oh well

    private _idx = floor (random (count _candidates));
    private _pos = _candidates deleteAt _idx;   // remove so we don’t reuse same tile

    private _newX = _pos select 0;
    private _newY = _pos select 1;
    private _vn   = format ["ShoterIed_Value%1%2", _newX, _newY];

    _ied setVariable [_vn, "B", false];
};

// -----------------------------------------------------
// 4) Recompute numbers for all non-bomb tiles
// -----------------------------------------------------
for "_xx" from 1 to 9 do {
    for "_yy" from 1 to 9 do {
        private _vn  = format ["ShoterIed_Value%1%2", _xx, _yy];
        private _val = _ied getVariable [_vn, "E"];

        if (_val != "B") then {
            private _cnt = [_ied, _xx, _yy] call ShoterIed_BombCount;
            if (_cnt == 0) then {
                _ied setVariable [_vn, "E", false];
            } else {
                _ied setVariable [_vn, _cnt, false];
            };
        };
    };
};
