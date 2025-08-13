class CBA_Extended_EventHandlers;

class CfgVehicles {
    class B_Soldier_base_F;
    class B_Soldier_02_F: B_Soldier_base_F {
        class EventHandlers;
    };
    class CLASS(BLUFOR_Unit_Base): B_Soldier_02_F {
        SCOPE_PRIVATE;
        author = "505th Aux Team";
        displayName = "BLUFOR Unit Base";
        uniformClass = QCLASS(BLUFOR_Uniform_Base);

        editorSubcategory = QEDSUBCAT(Infantry);

        modelSides[] = {BLUFOR};

        weapons[] = {"Throw", "Put"};
        respawnWeapons[] = {"Throw", "Put"};
        magazines[] = {};
        respawnMagazines[] = {};
        items[] = {};
        respawnItems[] = {};
        linkedItems[] = {};
        respawnLinkedItems[] = {};
        backpack = "";

        class EventHandlers: EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        };
    };

    class O_Soldier_base_F;
    class O_Soldier_02_F: O_Soldier_base_F {
        class EventHandlers;
    };
    class CLASS(OPFOR_Unit_Base): O_Soldier_02_F {
        SCOPE_PRIVATE;
        author = AUTHOR;
        displayName = "OPFOR Unit Base";
        uniformClass = "OPFOR_Uniform_Base";

        editorSubcategory = QEDSUBCAT(Infantry);

        modelSides[] = {OPFOR};

        weapons[] = {"Throw", "Put"};
        respawnWeapons[] = {"Throw", "Put"};
        magazines[] = {};
        respawnMagazines[] = {};
        items[] = {};
        respawnItems[] = {};
        linkedItems[] = {};
        respawnLinkedItems[] = {};
        backpack = "";

        class EventHandlers: EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        };
    };

    class I_Soldier_base_F;
    class I_Soldier_02_F: I_Soldier_base_F {
        class EventHandlers;
    };
    class CLASS(INDEP_Unit_Base): I_Soldier_02_F {
        SCOPE_PRIVATE;
        displayName = "INDEP Unit Base";
        uniformClass = "INDEP_Uniform_Base";

        modelSides[] = {INDEP};

        weapons[] = {"Throw", "Put"};
        respawnWeapons[] = {"Throw", "Put"};
        magazines[] = {};
        respawnMagazines[] = {};
        items[] = {};
        respawnItems[] = {};
        linkedItems[] = {};
        respawnLinkedItems[] = {};
        backpack = "";

        class EventHandlers: EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        };
    };

    class Bag_Base;
    class B_FieldPack_Base: Bag_Base {
        class EventHandlers;
    };
    class CLASS(Backpack_Base): B_FieldPack_Base {
        SCOPE_PRIVATE;
        displayName = "Backpack Base";
        modelSides[] = {ALL_SIDES};

        class EventHandlers: EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        };
    };
};
