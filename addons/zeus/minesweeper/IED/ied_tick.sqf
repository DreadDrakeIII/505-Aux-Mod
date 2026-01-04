/*
	Author: Shoter
	Modified: 505th

	Description:
	IED tick, server side - Motion sensor detection

	Parameter(s):
		0 : OBJECT - IED object

	Returns: N/A
*/
private [ "_ied", "_timer" ];
if(isServer) then
{
	_ied = [_this, 0 ] call BIS_fnc_param;

	_side = _ied getVariable "ShoterIed_Side";

	// If side is sideEmpty, motion sensor is disabled
	if (_side isEqualTo sideEmpty) exitWith {};

	while {true} do {

		if ((_ied getVariable "ShoterIed_Detonated" isEqualTo true) OR ( _ied getVariable "ShoterIed_Difused" isEqualTo true)) exitWith {};

		_nearObjects = _ied nearObjects 8;
		{

			if((side _x) isEqualTo _side OR (_side isEqualTo "everyone" AND ((side _x) isEqualTo civilian OR (side _x) isEqualTo west OR (side _x) isEqualTo east)) ) then
				{

					if(speed _x > 4.9) exitWith { [_ied] call ShoterIed_Detonate; };
				};

		} forEach _nearObjects;

		sleep 1;
	};
};
