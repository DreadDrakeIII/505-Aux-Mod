#include "script_component.hpp"

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
            class openMenu {};
            class closeMenu {};
            class renderMenu {};
            class onMouseWheel {};
            class onKeyDown {};
            class onSelect {};
        };
    };
};

#include "CfgVehicles.hpp"
