#include "..\script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;

        requiredAddons[] = {
            QUOTE(ADDON),
            "OPTRE_Weapons_AR",
            "OPTRE_JSRS_Sounds"
            };

        units[] = {};
        weapons[] = { QCLASS(MA5CGL) };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
// #include "CfgMagazines.hpp"
#include "CfgSoundShaders.hpp"
#include "CfgSoundSets.hpp"
