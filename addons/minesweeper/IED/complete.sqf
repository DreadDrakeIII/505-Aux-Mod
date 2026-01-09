#include "defines.def"

_ied = _this select 0;

playSound3D ["A3\Sounds_F\sfx\ui\vehicles\vehicle_status.wss", _ied, false, getPosASL _ied, 3, 1, 100];

_ied setVariable [ "ShoterIed_Difuser", objNull , true];
_ied setVariable [ "ShoterIed_Difused", true , true];
_ied setVariable [ "ShoterIed_Detonated", true , true];

playSound3D ["\BLU\OLI\addons\minesweeper\sounds\success.ogg", _ied, false, getPosASL _ied, 5, 1, 200];

closeDialog 123;
