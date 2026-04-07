if (!hasInterface) exitWith {};

call FEF_fnc_attachGrenadeEH;

player addEventHandler ["Respawn", {
    call FEF_fnc_attachGrenadeEH;
}];
