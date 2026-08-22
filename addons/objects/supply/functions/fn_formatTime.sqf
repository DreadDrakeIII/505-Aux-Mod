// OLI_SUPPLY - seconds -> "m:ss" for the cooldown counter.
// Arguments: 0: seconds <NUMBER>
// Return: <STRING>  e.g. 7 -> "0:07", 95 -> "1:35"

params [["_seconds", 0]];

private _total = ceil (_seconds max 0);
private _m = floor (_total / 60);
private _s = _total - (_m * 60);

if (_s < 10) then {
    format ["%1:0%2", _m, _s]
} else {
    format ["%1:%2", _m, _s]
};
