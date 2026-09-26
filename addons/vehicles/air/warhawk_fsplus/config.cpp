#include "script_component.hpp"

// Optional compat: lets the Warhawk carry Fire Support PLUS thermobaric bombs.
// Kept separate from the warhawk sub-addon on purpose - if Fire Support PLUS
// (Workshop 2699465073) is not loaded, ONLY this sub-addon is skipped and the
// jets still load. Do NOT move PHAN_FAE_Bombs into warhawk's requiredAddons.
class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            QUOTE(DOUBLES(ADDON,warhawk)),
            "PHAN_FAE_Bombs"
        };
        units[] = {};
        weapons[] = {};
        skipWhenMissingDependencies = 1;
        VERSION_CONFIG;
    };
};

#include "CfgMagazines.hpp"
#include "CfgVehicles.hpp"
