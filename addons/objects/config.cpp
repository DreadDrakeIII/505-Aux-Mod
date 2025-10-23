#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QCLASS(main),
            "OPTRE_UNSC_Structure_Signs",
            "TKE_Props",
            "OPTRE_BW_Locker",
            "A3_Structures_F_Mil_Flags"
        };
        units[] = {
            QCLASS(AFB_Sign_1),
            QCLASS(OP_Sign_1),
            QCLASS(Flag_505th_Pole),
            QCLASS(Flag_505th_Damaged_Pole),
            QCLASS(Console_Base),
            QCLASS(Console_Permissions),
            QCLASS(Utility_Arsenal),
            QCLASS(Utility_FullHeal_Small),
            QCLASS(Utility_FullHeal_Large)
        };
        weapons[] = {};
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
#include "CfgEventHandlers.hpp"
