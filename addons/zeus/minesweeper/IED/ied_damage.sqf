/*
	Author: Shoter

	Description:
	Handle dammages done to IED

	Parameter(s):
		unit: Object - Object the event handler is assigned to
		selectionName: String - Name of the selection where the unit was damaged
		damage: Number - Resulting level of damage

	Returns: Control with field
*/

_ied = [_this , 0 ] call BIS_fnc_param;
_damage = [_this, 2 ] call BIS_fnc_param;

_ied setDamage ((damage _ied) + _damage);

if( (random 1) < damage _ied) then
{
	[_ied] call ShoterIed_Detonate;
};
0
