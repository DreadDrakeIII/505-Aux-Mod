_ied = _this select 0;

if( (_ied getVariable "ShoterIed_Detonated" isEqualTo false) AND ( _ied getVariable "ShoterIed_Difused" isEqualTo false) ) then
{
	_shell = _ied getVariable ["ShoterIed_explosionType", "ammo_Bomb_SDB"];

	playSound3D ["\BLU\OLI\addons\zeus\minesweeper\sounds\failure.ogg", _ied, false, getPosASL _ied, 7, 1, 100];
	sleep 1.6;

	_shell createVehicle [ getPos _ied select 0, getPos _ied select 1, 1];

	_ied setVariable [ "ShoterIed_Detonated", true , true];

	closeDialog 123;
};
