// OLI_SUPPLY - build the HTML title for one console action.
//
// Vanilla action titles accept a small subset of HTML: <img image='...'/> for
// the icon and <t color='#RRGGBB'> for the text colour. That is the whole
// trick - there is no icon parameter on addAction.
//
// The same builder makes the on-screen "default action" text (the prompt that
// appears when you just look at the console, no scrolling) - that one uses a
// bigger icon, the way vanilla doors do.
//
// Arguments:
//   0: action key <STRING>
//   1: on cooldown? <BOOL> (default false)
//   2: seconds remaining <NUMBER> (default 0)
//   3: icon size <NUMBER> (default 1.5; use 2.5 for the on-screen prompt)
// Return: title <STRING>

params ["_key", ["_onCooldown", false], ["_remaining", 0], ["_iconSize", 1.5]];

private _idx = OLI_Supply_Actions findIf {(_x select 0) == _key};
if (_idx < 0) exitWith {""};

(OLI_Supply_Actions select _idx) params ["", "", "_label", "_color", "_icon"];

if (_onCooldown) then {
    _color = OLI_Supply_ColorCooldown;
    _label = format ["%1  [%2]", _label, [_remaining] call OLI_Supply_fnc_formatTime];
};

format ["<img image='%1' size='%2' shadow=2 /> <t color='%3'>%4</t>", _icon, _iconSize, _color, _label]
