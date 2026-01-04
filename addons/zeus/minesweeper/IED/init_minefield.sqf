/*
	Author: Shoter
	Modified: 505th

	Description:
	Initialize minesweeper GUI

	Parameter(s):
		0 : OBJECT - IED object

	Returns: N/A
*/
disableSerialization;
#include "defines.def"
private [ "_ied, _difficulty" ];
_ied = _this select 0;
ShoterIed_FirstClick = true;

if( (_ied getVariable ["ShoterIed_Difuser",objNull]) isEqualTo objNull OR DEBUG) then
{

	player setVariable ["ShoterIed_disarmingObj", _ied, false];
	_ied setVariable ["ShoterIed_Difuser", player, true];

	_ok = createDialog "ShoterIed_Minesweeper";

	_gui = uiNamespace getVariable "ShoterIed_Minesweeper";

	_mineCount = _ied getVariable ["ShoterIed_mineCount", 12];
	_mines = _mineCount;

	_time = _ied getVariable ["ShoterIed_customTimer", 120];

	ctrlSetText [ TIMER_ID, format ["%1", _time ] ];
	ctrlSetText [ MINECOUNT_ID, format ["%1", _mines ] ];

	_ied setVariable [ "ShoterIed_Timer", _time, false ];
	_ied setVariable [ "ShoterIed_left", 81 - _mines, false ];

	if( _ok ) then
	{

	for [ {_X = 1}, {_X < 10}, {_X = _X + 1} ] do
	{
		for [ {_Y = 1}, {_Y < 10}, {_Y = _Y + 1} ] do
		{
			_field = [_X, _Y] call ShoterIed_GetField;
			_field ctrlSetEventHandler ["MouseButtonDown", format ["nic = _this spawn ShoterIed_TileClick"]];
			_ied setVariable ["ShoterIed_Value" + format ["%1%2", _X, _Y],  "E", false];
		};
	};
		for [ {_B = 0}, {_B < _mines}, {true} ] do
		{
			_X = 1 + floor (random 10);
			_Y = 1 + floor (random 10);
			_field = [_X, _Y] call ShoterIed_GetField;
			if( (_ied getVariable "ShoterIed_Value" + format ["%1%2", _X, _Y]) isEqualTo "E" ) then {
				_ied setVariable ["ShoterIed_Value" + format ["%1%2", _X, _Y], "B"];
				_B = _B + 1;
			};
		};

		for [ {_X = 1}, {_X < 10}, {_X = _X + 1} ] do
		{
			for [ {_Y = 1}, {_Y < 10}, {_Y = _Y + 1} ] do
			{
				_field = [_X, _Y] call ShoterIed_GetField;
				_count = [_ied, _X, _Y] call ShoterIed_BombCount;
				if(_count != 0) then
				{
					_ied setVariable ["ShoterIed_Value" + format ["%1%2", _X, _Y], _count];
				};
			};
		};
		_tests = 0;

	};

	nic = [_ied] spawn ShoterIed_SweeperTick;
	playSound3D ["\BLU\OLI\addons\zeus\minesweeper\sounds\start_defusing.ogg", _ied, false, getPosASL _ied, 5, 1, 200];
} else
{
	//someone is disarming the bomb.
};
