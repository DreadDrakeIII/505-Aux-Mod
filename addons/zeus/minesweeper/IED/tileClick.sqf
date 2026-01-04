#include "defines.def"
private ["_X", "_Y", "_button", "_ied", "_index", "_mines", "_tile" ];
disableSerialization;

_tile = _this select 0;
_button = _this select 1;


// Right click for flags
if(_button isEqualTo 1)then
{
	if( ctrlText (ctrlIDC _tile) isEqualTo PATH_IMG + "tile.paa" ) then
	{
		_mines = parseNumber ctrlText MINECOUNT_ID;
		if(_mines > 0) then
			{
				ctrlSetText [ MINECOUNT_ID, format ["%1", _mines - 1 ] ];
				ctrlSetText [ ctrlIDC _tile, PATH_IMG + "tileFlag.paa" ];
			};
	} else {
		if( ctrlText (ctrlIDC _tile) isEqualTo PATH_IMG + "tileFlag.paa" ) then
		{
			_mines = parseNumber ctrlText MINECOUNT_ID;
			ctrlSetText [ MINECOUNT_ID, format ["%1", _mines + 1 ] ];
			ctrlSetText [ ctrlIDC _tile, PATH_IMG + "tile.paa" ];
		};
	};
};

// Left click for discovering, also includes safe first click logic
if(_button isEqualTo 0) then
{
	_ied = player getVariable "ShoterIed_disarmingObj";
	_index = ctrlIDC _tile;
	_Y = (_index % 10);
	_X = floor(_index / 10);

	if (ShoterIED_FirstClick) then {
		ShoterIED_FirstClick = false;
		[_ied, _X, _Y] call ShoterIED_EnsureSafeFirstClick
	};

	[_ied, _X, _Y] call ShoterIed_Uncover;
};
