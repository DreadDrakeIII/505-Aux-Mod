// Check if ZEN is loaded
if (!isClass (configFile >> "CfgPatches" >> "zen_main")) exitWith {
    diag_log "MSIED: ZEN not detected, module will not be available";
    false
};

// Register the custom module
[
    "505th Zeus",
    "Place Minesweeper IED",
    {
        params ["_pos", "_attachedObject"];

        // Only execute for the Zeus who placed it (local to curator)
        if (!isNull (getAssignedCuratorLogic player)) then {
            [_pos, _attachedObject] call MSIED_fnc_zenModule;
        };
    },
    "\a3\modules_f\data\iconexplosive_ca.paa"
] call zen_custom_modules_fnc_register;

diag_log "MSIED: ZEN custom module registered successfully";

true
