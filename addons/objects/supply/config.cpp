#include "script_component.hpp"

// ===========================================================================
// Supply Console sub-component - ported from the standalone oli_supply_main
// package (built by the other developer, HEMTT-based) into addons/objects.
//
// This sub-component does NOT use this mod's PREP()/FUNC()/GVAR() macro
// system. It uses the vanilla Arma CfgFunctions auto-compile convention
// instead (tag "OLI_Supply", file naming fn_*.sqf), exactly as it was
// authored in the original package - every function it defines is called
// directly as OLI_Supply_fnc_<name>, and fn_preInit.sqf / fn_postInit.sqf
// are marked preInit/postInit below so they run automatically without an
// XEH_preInit.sqf/XEH_postInit.sqf hookup.
// ===========================================================================

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "cba_xeh",
            "cba_events",
            "cba_settings",
            "ace_common",
            "ace_dragging",
            "OPTRE_BW_DoorConsole"
        };
        units[] = {
            QCLASS(Supply_Console)
        };
        weapons[] = {};
        VERSION_CONFIG;
    };
};

class CfgFunctions {
    class OLI_Supply {
        tag = "OLI_Supply";
        class main {
            file = QPATHTOF(supply\functions);
            class preInit { preInit = 1; };
            class postInit { postInit = 1; };
            class wireConsoles {};
            class addActions {};
            class registerConsole {};
            class removeActions {};
            class actionTitle {};
            class cooldownVar {};
            class formatTime {};
            class requestCrate {};
            class spawnCrate {};
            class startCarry {};
            class titleLoop {};
        };
    };
};

#include "CfgVehicles.hpp"
