params ["_ied", ["_mineCount", 12], ["_timer", 120], ["_explosionType", "SmallSecondary"], ["_side", sideEmpty], ["_audibleBeforeDefusal", true]];
if (isNull _ied) exitWith {};

[_ied, _mineCount, _timer, _explosionType, _side, _audibleBeforeDefusal] execVM "\BLU\OLI\addons\minesweeper\IED\init_ied.sqf";
