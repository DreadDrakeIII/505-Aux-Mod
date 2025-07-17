#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QCLASS(main),
            "OPTRE_UNSC_Structure_Signs",
            "A3_Structures_F_Mil_Flags"
        };
        units[] = {
            QCLASS(AFB_Sign_1),
            QCLASS(Flag_505th_Pole),
            QCLASS(Flag_505th_Damaged_Pole)
        };
        weapons[] = {};
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
#include "CfgEditorSubcategories.hpp"
#include "CfgEventHandlers.hpp"
