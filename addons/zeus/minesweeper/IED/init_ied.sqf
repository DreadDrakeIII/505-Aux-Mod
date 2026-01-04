#include "defines.def"
private [ "_ied", "_mineCount", "_side" ];

waitUntil {isNil "ShoterIed_InitDone" isEqualTo false};
waitUntil {ShoterIed_InitDone isEqualTo true};
sleep 2;

_ied = _this select 0;
_mineCount = _this select 1;
_timer = _this select 2;
_explosionType = _this select 3;
_side = _this select 4;
_audibleBeforeDefusal = _this select 5;

if(_side isEqualTo "west") then { _side = west; };
if(_side isEqualTo "east") then { _side = east; };
if(_side isEqualTo "civilian") then { _side = civilian; };

// Store settings on the IED object
_ied setVariable [ "ShoterIed_mineCount", _mineCount, true ];
_ied setVariable [ "ShoterIed_customTimer", _timer, true ];
_ied setVariable [ "ShoterIed_explosionType", _explosionType, true ];
_ied setVariable [ "ShoterIed_Difuser", objNull , true];
_ied setVariable [ "ShoterIed_Difused", false , true];
_ied setVariable [ "ShoterIed_Detonated", false , true];
_ied setVariable [ "ShoterIed_Side", _side, true];

_actionText = "defuse";
if(player getVariable ["ShoterIed_Specialist",false] isEqualTo true) then
{
    _actionText = COLOR_GREEN("defuse");
    
    // Color code based on mine count
    if (_mineCount >= 14) then {
        _actionText = COLOR_RED("defuse");
    } else {
        if (_mineCount >= 12) then {
            _actionText = COLOR_YELLOW("defuse");
        };
    };
};

_condition = format ["
_difuser = _target getVariable ""ShoterIed_Difuser"";
_difused = _target getVariable ""ShoterIed_Difused"";
_detonated = _target getVariable ""ShoterIed_Detonated"";
(player distance _target < 4) AND (((_difuser isEqualTo objNull) AND (_difused isEqualTo false) AND ( _detonated isEqualTo false)) OR %1 )", DEBUG];

_ied addAction [ _actionText, { [_this select 0] call ShoterIed_InitMinefield }, "", 5, true, true, "", _condition  ];
nic = [_ied] spawn ShoterIed_IedTick;
_ied addEventHandler ["HandleDamage", {_this call ShoterIed_HandleDamage;} ];

if (_audibleBeforeDefusal) then {
    [_ied] spawn {
        _ied = _this select 0;
        
        while {true} do {
            // Check if someone started defusing
            if (!isNull (_ied getVariable ["ShoterIed_Difuser", objNull])) exitWith {};
            
            // Check if detonated or defused
            if ((_ied getVariable ["ShoterIed_Detonated", false]) || (_ied getVariable ["ShoterIed_Difused", false])) exitWith {};
            
            // Play beep
            playSound3D ["\BLU\OLI\addons\zeus\minesweeper\sounds\standard_beep.ogg", _ied, false, getPosASL _ied, 5, 1, 100];
            
            sleep 2;
        };
    };
};
