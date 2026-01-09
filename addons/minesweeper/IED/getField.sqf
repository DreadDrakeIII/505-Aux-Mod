/*
	Author: Shoter

	Description:
	Get control field with x/y positon

	Parameter(s):
		0 : INT - X
		1 : INT - Y

	Returns: Control with field
*/
disableSerialization;
private [ "_gui", "_x", "_y", "_field", "_fieldNumber" ];
_x = _this select 0;
_y = _this select 1;

_gui = uiNamespace getVariable "ShoterIed_Minesweeper";

_fieldNumber = _x*10 + _y;
diag_log format ["Index %1" , _fieldNumber ];
(_gui displayCtrl _fieldNumber)
