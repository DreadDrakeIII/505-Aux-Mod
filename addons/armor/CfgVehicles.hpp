class CfgVehicles {
    class Rogue_CEUniform_inf_B;
    class CLASS(Marine_CE_Base): Rogue_CEUniform_inf_B {
        SCOPE_PRIVATE;
        author = AUTHOR;

        faction = QFACTION(505th);

        displayName = "Marine (Base)";
        uniformClass = QCLASS(Uniform_CE);
        modelSides[] = {BLUFOR};
        hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEUniformP_co.paa","\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"};

        linkedItems[] = {QCLASS(CE_HELMETV2), QCLASS(CE_Armour_Vest),"","",MARINE_LINKED_ITEMS_RADIO};
        respawnLinkedItems[] = {QCLASS(CE_HELMETV2), QCLASS(CE_Armour_Vest),"","",MARINE_LINKED_ITEMS_RADIO};
        backpack = "";
    };

    class Rogue_CEUniformRolled_inf_B;
    class CLASS(Marine_CE_Rolled_Base): Rogue_CEUniformRolled_inf_B {
        SCOPE_PRIVATE;
        author = AUTHOR;

        faction = QFACTION(505th);

        displayName = "Marine Rolled (Base)";
        uniformClass = QCLASS(Uniform_CE_Rolled);
        modelSides[] = {BLUFOR};
        hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEUniformP_co.paa","\Rogue_CEMarine\data\Rogue_CEUniformRolled_co.paa"};
    };

    class TKE_Rogue_UniformNCCamo_inf_B;
    class CLASS(Pilot_Base): TKE_Rogue_UniformNCCamo_inf_B {
        SCOPE_PRIVATE;
        author = AUTHOR;

        faction = QFACTION(505th);

        displayName = "Pilot (Base)";
        uniformClass = QCLASS(Uniform_Pilot);
        modelSides[] = {BLUFOR};
        linkedItems[] = {};
        respawnLinkedItems[] = {};
    };
    class CLASS(BlackOps_Base): TKE_Rogue_UniformNCCamo_inf_B {
        SCOPE_PRIVATE;
        author = AUTHOR;

        faction = QFACTION(ONI);
        uniformClass = QCLASS(Uniform_BlackOps);
        modelSides[] = {BLUFOR};
        linkedItems[] = {};
        respawnLinkedItems[] = {};
    };

class TCP_B_CBUU_FieldTop_Full_Gloves_Bloused_Kneepads_Base;
class TCP_B_CBUU_FieldTop_HalfRoll_Gloves_Bloused_Base;

class CLASS(Marine_TCP_Woodland_1_Base): TCP_B_CBUU_FieldTop_Full_Gloves_Bloused_Kneepads_Base {
    SCOPE_PRIVATE;
    author = AUTHOR;
    faction = QFACTION(505th);
    displayName = "TCP Marine Woodland 1 (Base)";
    uniformClass = QCLASS(CBUU_Woodland_1);
    modelSides[] = {BLUFOR};
    weapons[] = {};
    respawnWeapons[] = {};
    magazines[] = {};
    respawnMagazines[] = {};
    items[] = {};
    respawnItems[] = {};
    linkedItems[] = {};
    respawnLinkedItems[] = {};
};

class CLASS(Marine_TCP_Woodland_2_Base): TCP_B_CBUU_FieldTop_HalfRoll_Gloves_Bloused_Base {
    SCOPE_PRIVATE;
    author = AUTHOR;
    faction = QFACTION(505th);
    displayName = "TCP Marine Woodland 2 (Base)";
    uniformClass = QCLASS(CBUU_Woodland_2);
    modelSides[] = {BLUFOR};
    weapons[] = {};
    respawnWeapons[] = {};
    magazines[] = {};
    respawnMagazines[] = {};
    items[] = {};
    respawnItems[] = {};
    linkedItems[] = {};
    respawnLinkedItems[] = {};
};

class CLASS(Marine_TCP_Urban_1_Base): TCP_B_CBUU_FieldTop_Full_Gloves_Bloused_Kneepads_Base {
    SCOPE_PRIVATE;
    author = AUTHOR;
    faction = QFACTION(505th);
    displayName = "TCP Marine Urban 1 (Base)";
    uniformClass = QCLASS(CBUU_Urban_1);
    modelSides[] = {BLUFOR};
    weapons[] = {};
    respawnWeapons[] = {};
    magazines[] = {};
    respawnMagazines[] = {};
    items[] = {};
    respawnItems[] = {};
    linkedItems[] = {};
    respawnLinkedItems[] = {};
};

    #include "configs\Units.hpp"

    class TKE_CamelBakUCN;
    class Rogue_CEBackpack;
    class Rogue_CEBackpackTFAR;
    class Rogue_CEInvisibleBackpack;
    class Rogue_CEBackpackLR;
    class Rogue_CEBackpackScout;
    class 19thMD_Backpack_Standard_Med;
    class TKE_AlicePackUCN;
    class Halo_LR;
    class Halo_Hardcase;
    class Halo_Rucksack_01;
    class Halo_Rucksack_02;

    class CLASS(Backpack_Base): Rogue_CEBackpack {
        SCOPE_PRIVATE;
        displayName = "Combat Backpack (Base)";
    };
    class CLASS(BackpackLR_Base): Rogue_CEBackpackTFAR {
        SCOPE_PRIVATE;
        displayName = "Combat Backpack LR (Base)";
    };
    class CLASS(Backpack_Invis_Base): Rogue_CEInvisibleBackpack {
        SCOPE_PRIVATE;
        displayName = "Invisible Backpack (Base)";
    };
    class CLASS(LR_Antenna_Base): Rogue_CEBackpackLR {
        SCOPE_PRIVATE;
        displayName = "LR Antenna (Base)";
    };
    class CLASS(Scout_Backpack_Base): Rogue_CEBackpackScout {
        SCOPE_PRIVATE;
        displayName = "Scout Backpack (Base)";
    };
    class CLASS(Medical_Backpack_Base): 19thMD_Backpack_Standard_Med {
        SCOPE_PRIVATE;
        displayName = "Medical Backpack (Base)";
    };
    class CLASS(Pilot_Backpack_Base): TKE_CamelBakUCN {
        SCOPE_PRIVATE;
        displayName = "Pilot Backpack (Base)";
    };
    class CLASS(BlackOps_Backpack_Base): TKE_AlicePackUCN {
        SCOPE_PRIVATE;
        displayName = "Black Ops Backpack (Base)";
    };
    // class CLASS(CH252_LR_Base): Halo_LR {
    //     SCOPE_PRIVATE;
    //     displayName = "CH252 LR (Base)";
    // };
    // class CLASS(CH252_Hardcase_Base): Halo_Hardcase {
    //     SCOPE_PRIVATE;
    //     displayName = "CH252 Hardcase (Base)";
    // };
    // class CLASS(CH252_Rucksack_Light_Base): Halo_Rucksack_01 {
    //     SCOPE_PRIVATE;
    //     displayName = "CH252 Rucksack Light (Base)";
    // };
    // class CLASS(CH252_Rucksack_Heavy_Base): Halo_Rucksack_02 {
    //     SCOPE_PRIVATE;
    //     displayName = "CH252 Rucksack Heavy (Base)";
    // };


    #include "configs\Backpacks.hpp"
};
