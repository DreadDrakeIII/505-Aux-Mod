class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_Actions {
            class ACE_MainActions {
                class GVAR(eject) {
                    displayName = "Eject";
                    exceptions[] = {"isNotSitting", "isNotInside"};
                    condition = QUOTE(call FUNC(canEjectUnit));
                    statement = QUOTE(moveOut _target);
                };
            };
        };
    };

    class LandVehicle;
    class Car: LandVehicle {
        class ACE_Actions {
            class ACE_MainActions {
                UNFLIP_VEHICLE;
            };
        };
        class ACE_SelfActions {
            SKIN_SWITCHER;
        };
    };
    class Tank: LandVehicle {
        class ACE_Actions {
            class ACE_MainActions {
                UNFLIP_VEHICLE;
            };
        };
        class ACE_SelfActions {
            SKIN_SWITCHER;
        };
    };
    class StaticWeapon: LandVehicle {
        class ACE_SelfActions {
            SKIN_SWITCHER;
        };
    };

    class Air;
    class Helicopter: Air {
        class ACE_Actions {
            class ACE_MainActions {
                UNFLIP_VEHICLE;
            };
        };
        class ACE_SelfActions {
            SKIN_SWITCHER;
        };
    };
    class Plane: Air {
        class ACE_Actions {
            class ACE_MainActions {
                UNFLIP_VEHICLE;
            };
        };
        class ACE_SelfActions {
            SKIN_SWITCHER;
        };
    };

    class Ship;
    class Ship_F: Ship {
        class ACE_Actions {
            class ACE_MainActions {
                UNFLIP_VEHICLE;
            };
        };
        class ACE_SelfActions {
            SKIN_SWITCHER;
        };
    };
};