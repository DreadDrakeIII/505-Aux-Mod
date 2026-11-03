class CfgWeapons {
    class TKE_CSTRHelmVUDigi;
    class CLASS(SOSE_Helmet): TKE_CSTRHelmVUDigi {
        SCOPE_PUBLIC;
        author = AUTHOR;
        displayName = "[Sosei] CSTR Helmet (Visor Up)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(sosei\data\textures\infantry\SOSE_Helmet_co.paa),
            "\TKE_Kuiper_Engagements\TKE_SpecOPS\data\TKE_CSTRHelm_ca.paa"
        };
    };


    class CLASS(SOSE_Helmet_Officer): CLASS(SOSE_Helmet) {
        displayName = "[Sosei] CSTR Helmet (Officer)";
        hiddenSelectionsTextures[] = {
            QPATHTOF(sosei\data\textures\infantry\SOSE_Helmet_Officer_co.paa),
            "\TKE_Kuiper_Engagements\TKE_SpecOPS\data\TKE_CSTRHelm_ca.paa"
        };
    };

    class TKE_CSTRArmourDigi;
    class CLASS(SOSE_Armour): TKE_CSTRArmourDigi {
        SCOPE_PUBLIC;
        author = AUTHOR;
        displayName = "[Sosei] CSTR Armour";
        hiddenSelectionsTextures[] = {
            QPATHTOF(sosei\data\textures\infantry\SOSE_Armour_co.paa),
            QPATHTOF(sosei\data\textures\infantry\SOSE_Pouches_co.paa)
        };
    };

    class TKE_CSTRUni_U_OP;
    class TKE_CSTRUni_U_B: TKE_CSTRUni_U_OP {
        class ItemInfo;
    };
    class CLASS(SOSE_Uniform): TKE_CSTRUni_U_B {
        SCOPE_PUBLIC;
        author = AUTHOR;
        displayName = "[Sosei] CSTR Undersuit";
        class ItemInfo: ItemInfo {
            uniformClass = QCLASS(SOSE_Unit_Base);
        };
    };

    class OLI_MA37;
    class CLASS(SOSE_MA37): OLI_MA37 {
        SCOPE_HIDDEN;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "TCP_muzzle_brake_762_01";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "OLI_MA37_LAM";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "TCP_optic_EVOSJ";
            };
        };
    };

    class OLI_M73;
    class CLASS(SOSE_M73): OLI_M73 {
        SCOPE_HIDDEN;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "TCP_muzzle_brake_762_01";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "TCP_acc_carryHandle_M731";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "TCP_optic_EVOSM";
            };
        };
    };

    class OLI_VK78_COMMANDO;
    class CLASS(SOSE_VK78): OLI_VK78_COMMANDO {
        SCOPE_HIDDEN;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "TCP_optic_EVOSJ";
            };
        };
    };
};
