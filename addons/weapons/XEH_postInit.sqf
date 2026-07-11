#include "script_component.hpp"

// Auto-remove used Lykoi tube after CBA disposable swap
[QCLASS(M44_Lykoi_Used_Grey), "Init", {
    params ["_unit"];
    if (!local _unit) exitWith {};
    _unit removeWeapon QCLASS(M44_Lykoi_Used_Grey);
}] call CBA_fnc_addClassEventHandler;
