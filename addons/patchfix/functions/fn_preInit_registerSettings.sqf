// ============================================================================
//  preInit_registerSettings.sqf
//  Registers the player-mode CBA setting.
//
//  gokobi_var_playerMode:
//     0 = Full effect on players  (original behavior)
//     1 = AI only                 (players get nothing)
//     2 = Helmet only             (players: helmet still breaks/flies off,
//                                   but no facewear/NVG stripping, no gore/blood)
// ============================================================================

[
    "gokobi_var_playerMode",                 
    "LIST",                                 
    [
        "Player effect mode",                
        "Controls how the GOKO ballistic head-impact effects apply to PLAYERS. AI are always affected."
    ],
    ["GOKO Patch", "Player Behavior"],      
    [
        [0, 1, 2],                           
        ["Full effect", "No effect to players", "Helmet only"], 
        0                                    
    ],
    true                                     
] call CBA_settings_fnc_init;
