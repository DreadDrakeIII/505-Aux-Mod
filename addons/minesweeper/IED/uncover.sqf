#include "defines.def"
private ["_X", "_Y", "_ied", "_soft", "_type", "_left"];
_ied = _this select 0;
_X = _this select 1;
_Y = _this select 2;
_soft = false;
if(count _this isEqualTo 4) then { _soft = true; };
_type = _ied getVariable "ShoterIed_Value" + format ["%1%2", _X, _Y];
if( (ctrlText (_X*10+_Y) ) isEqualTo (PATH_IMG+"tile.paa") AND not (_type isEqualTo "B") ) then
{
		_left = _ied getVariable "ShoterIed_left";
		_ied setVariable [ "ShoterIed_left", _left - 1, false ];
		if(_left < 2) then
		{
			nic = [_ied] call ShoterIed_Complete;
		};

	if(typeName _type isEqualTo "SCALAR") then
	{
		ctrlSetText [ _X*10+_Y, PATH_IMG+format["%1",_type]+".paa" ];


	};
	if(_type isEqualTo "E" ) then
	{
		ctrlSetText [ _X*10+_Y, PATH_IMG+"empty.paa" ];


		if(_X != 1) then
		{
			[_ied, _X - 1,_Y, true] call ShoterIed_Uncover;
		};

		if(_Y != 1) then
		{
			[_ied, _X,_Y - 1, true] call ShoterIed_Uncover;
		};

		if(_X != 9) then
		{
			[_ied, _X + 1,_Y, true] call ShoterIed_Uncover;
		};

		if(_Y != 9) then
		{
			[_ied, _X,_Y + 1, true] call ShoterIed_Uncover;
		};

		if(_X != 1 AND _Y != 1) then
		{
			[_ied, _X - 1,_Y - 1, true] call ShoterIed_Uncover;
		};

		if(_X != 1 AND _Y != 9) then
		{
			[_ied, _X - 1,_Y + 1, true] call ShoterIed_Uncover;
		};

		if(_X != 9 AND _Y != 1) then
		{
			[_ied, _X + 1,_Y - 1, true] call ShoterIed_Uncover;
		};

		if(_X != 9 AND _Y != 9) then
		{
			[_ied, _X + 1,_Y + 1, true] call ShoterIed_Uncover;
		};
	};


};

if(_type isEqualTo "B" AND _soft isEqualTo false) then
{		[_ied] call ShoterIed_Detonate;
		//player globalchat "BOOM";
};
