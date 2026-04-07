params ["_source", "_find", "_replace"];

private _result = _source;
private _findLength = count _find;
private _pos = _result find _find;

while {_pos >= 0} do {
    _result = (_result select [0, _pos]) + _replace + (_result select [_pos + _findLength]);
    _pos = _result find _find;
};

_result
