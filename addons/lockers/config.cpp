#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QCLASS(main),
            QCLASS(objects)
        };
        units[] = {
            QCLASS(Locker_Uniforms),
            QCLASS(Locker_Loadouts)
        };
        weapons[] = {};
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
#include "CfgEventHandlers.hpp"
