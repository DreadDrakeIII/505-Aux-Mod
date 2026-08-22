// OLI_SUPPLY - name of the per-player cooldown variable stored on a console.
//
// Cooldowns are per console AND per player: one player pulling a crate never
// locks anyone else out. The value is a CBA_missionTime stamp, set public by
// the server so the owning client can render its own countdown.
//
// Arguments: 0: unit <OBJECT>
// Return: variable name <STRING>

params [["_unit", objNull]];

private _uid = getPlayerUID _unit;
if (_uid isEqualTo "") then {_uid = netId _unit};   // SP / edge cases

format ["OLI_Supply_CD_%1", _uid]
