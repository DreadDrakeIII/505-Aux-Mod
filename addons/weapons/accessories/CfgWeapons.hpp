class CfgWeapons
{
    // Parent classes
    class acc_pointer_IR;
    class optic_Aco;
    class muzzle_snds_acp;
    class InventoryFlashLightItem_Base_F;
    class InventoryMuzzleItem_Base_F;

    // Scope base classes
    class OPTRE_SRS99C_Scope: optic_Aco {
        class ItemInfo;
    };

    class OPTRE_SRS99_Scope: optic_Aco {
        class ItemInfo;
    };

    // ============================================
    // === 505th MEQ7 Attachments
    // ============================================
    class CLASS(MEQ7): acc_pointer_IR
    {
        author = AUTHOR;
        SCOPE_PUBLIC;
        baseWeapon = QCLASS(MEQ7);

        displayName = "[505th] MEQ7 Attachment";
        descriptionShort = "MEQ7 IR, Visible Red Laser Pointer and Flashlight - Compatible with all weapons";
        descriptionUse = "<t color='#9cf953'>Use: </t>[505th] Infrared laser pointer";

        picture = "\OPTRE_Weapons\br\icons\laser.paa";
        model = "\OPTRE_weapons\br\BMR_Laser.p3d";

        inertia = 0.1;

        MRT_SwitchItemNextClass = QCLASS(FL_MEQ7_ATTACHMENT);
        MRT_SwitchItemPrevClass = QCLASS(LR_MEQ7_ATTACHMENT);
        MRT_switchItemHintText = "IR Laser";

        class ItemInfo: InventoryFlashLightItem_Base_F
        {
            mass = 4;
            type = 301;

            class Pointer
            {
                irLaserPos = "laser";
                irLaserEnd = "laser_dir";
                irDistance = 5;
            };
        };
    };

    class CLASS(FL_MEQ7_ATTACHMENT): acc_pointer_IR
    {
        author = AUTHOR;
        SCOPE_HIDDEN;
        baseWeapon = QCLASS(FL_MEQ7_ATTACHMENT);

        displayName = "[505th] MEQ7 Flashlight Attachment";
        descriptionShort = "Tactical flashlight - Compatible with all weapons";
        descriptionUse = "<t color='#9cf953'>Use: </t>[505th] Tactical flashlight";

        picture = "\OPTRE_Weapons\br\icons\laser.paa";
        model = "\OPTRE_weapons\br\BMR_Laser.p3d";

        inertia = 0.1;

        MRT_SwitchItemNextClass = QCLASS(LR_MEQ7_ATTACHMENT);
        MRT_SwitchItemPrevClass = QCLASS(MEQ7);
        MRT_switchItemHintText = "Flashlight";

        class ItemInfo: InventoryFlashLightItem_Base_F
        {
            mass = 6;
            type = 301;

            class FlashLight
            {
                color[] = {180, 160, 130};
                ambient[] = {0.9, 0.81, 0.7};
                intensity = 100;
                size = 1;
                innerAngle = 5;
                outerAngle = 100;
                coneFadeCoef = 8;
                position = "laser";
                direction = "laser_dir";
                useFlare = 1;
                flareSize = 1.4;
                flareMaxDistance = 200;
                dayLight = 0;

                class Attenuation
                {
                    start = 0;
                    constant = 0.5;
                    linear = 0.1;
                    quadratic = 0.2;
                    hardLimitStart = 27;
                    hardLimitEnd = 34;
                };

                scale[] = {0};
            };
        };
    };

    class CLASS(LR_MEQ7_ATTACHMENT): acc_pointer_IR
    {
        author = AUTHOR;
        SCOPE_HIDDEN;
        baseWeapon = QCLASS(LR_MEQ7_ATTACHMENT);

        displayName = "[505th] MEQ7 Red Laser Attachment";
        descriptionShort = "Visible red laser sight - Compatible with all weapons";
        descriptionUse = "<t color='#9cf953'>Use: </t>[505th] Visible red laser";

        picture = "\OPTRE_Weapons\br\icons\laser.paa";
        model = "\OPTRE_weapons\br\BMR_Laser.p3d";

        inertia = 0.1;

        MRT_SwitchItemNextClass = QCLASS(MEQ7);
        MRT_SwitchItemPrevClass = QCLASS(FL_MEQ7_ATTACHMENT);
        MRT_switchItemHintText = "Red Laser";

        class ItemInfo: InventoryFlashLightItem_Base_F
        {
            mass = 4;
            type = 301;

            class Pointer
            {
                irLaserPos = "laser";
                irLaserEnd = "laser_dir";
                irDistance = 5;
                beamColor[] = {15, 0, 0};
                beamMaxLength = 3000;
                beamThickness = 0.25;
                dotColor[] = {1000, 0, 0};
                dotSize = 1;
                isIR = 0;
            };
        };
    };

    // ============================================
    // === 505th Suppressors
    // ============================================
    class CLASS(M98H_Suppressor): muzzle_snds_acp
    {
        author = AUTHOR;
        SCOPE_PUBLIC;
        baseWeapon = QCLASS(M98H_Suppressor);

        displayName = "[505th] M98H Suppressor";
        descriptionShort = "M98H Anti-Material Rifle Suppressor";
        picture = "\OPTRE_weapons\smg\icons\silencer.paa";
        model = "\OPTRE_Weapons\Sniper\SRS99D_Sup.p3d";

        inertia = 0.2;

        class ItemInfo: InventoryMuzzleItem_Base_F
        {
            mass = 20;

            class MagazineCoef
            {
                initSpeed = 1;
            };

            class AmmoCoef
            {
                hit = 1;
                typicalSpeed = 1;
                airFriction = 1;
                visibleFire = 0.5;
                audibleFire = 0.3;
                visibleFireTime = 0.5;
                audibleFireTime = 0.5;
                cost = 1;
            };

            muzzleEnd = "zaslehPoint";
            alternativeFire = "OPTRE_muzzleFlash_suppressed";
            soundTypeIndex = 1;

            class MuzzleCoef
            {
                dispersionCoef = 0.9;
                artilleryDispersionCoef = 1;
                fireLightCoef = 0.1;
                recoilCoef = 0.85;
                recoilProneCoef = 0.85;
                minRangeCoef = 1; minRangeProbabCoef = 1;
                midRangeCoef = 1; midRangeProbabCoef = 1;
                maxRangeCoef = 1; maxRangeProbabCoef = 1;
            };
        };
    };

    // ============================================
    // === 505th Scopes
    // ============================================
    class CLASS(VTR_Scope): OPTRE_SRS99C_Scope
    {
        author = AUTHOR;
        SCOPE_PUBLIC;
        baseWeapon = QCLASS(VTR_Scope);

        displayName = "[505th] VTR Scope";

        weaponInfoType = "CBA_ScriptedOptic_zooming";

        class CBA_ScriptedOptic
        {
            minMagnificationReticleScale[] = {5, 0.9};
            maxMagnificationReticleScale[] = {25, 4.5};
            reticleDetailTextures[] =
            {
                {0, QPATHTOF(accessories\data\CBA_Optic\Tremor3\Tremor3_5_bar_ca.paa), 1, QPATHTOF(accessories\data\CBA_Optic\Tremor3\Tremor3_5_illum_ca.paa)},
                {10, QPATHTOF(accessories\data\CBA_Optic\Tremor3\Tremor3_10_bar_ca.paa), 0.5, QPATHTOF(accessories\data\CBA_Optic\Tremor3\Tremor3_10_illum_ca.paa)},
                {15, QPATHTOF(accessories\data\CBA_Optic\Tremor3\Tremor3_15_bar_ca.paa), 0.33333334, QPATHTOF(accessories\data\CBA_Optic\Tremor3\Tremor3_15_illum_ca.paa)},
                {20, QPATHTOF(accessories\data\CBA_Optic\Tremor3\Tremor3_20_bar_ca.paa), 0.25, QPATHTOF(accessories\data\CBA_Optic\Tremor3\Tremor3_20_illum_ca.paa)},
                {25, QPATHTOF(accessories\data\CBA_Optic\Tremor3\Tremor3_25_bar_ca.paa), 0.2, QPATHTOF(accessories\data\CBA_Optic\Tremor3\Tremor3_25_illum_ca.paa)}
            };

            bodyTexture = QPATHTOF(accessories\data\CBA_Optic\ScopeBody_Leup_B_N_ca.paa);
            bodyTextureSize=1.0700001;
            manualReticleNightSwitch = 1;
            reticleSafezoneSize = 0.8;
        };

        class ItemInfo: ItemInfo
        {
            mass = 14;
            optics = 1;
            opticType = 2;
            modelOptics = "\x\cba\addons\optics\cba_optic_big_pip.p3d";

            class OpticsModes
            {
                class Sniper
                {
                    opticsID = 1;
                    useModelOptics = 1;

                    opticsZoomInit = "5 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomMax = "5 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomMin = "25 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";

                    discreteDistance[] = {100,125,150,175,200,225,250,275,300,325,350,375,400,425,450,475,500,525,550,575,600,625,650,675,700,725,750,775,800,825,850,875,900,925,950,975,1000,1025,1050,1075,1100,1125,1150,1175,1200,1225,1250,1275,1300,1325,1350,1375,1400,1425,1450,1475,1500,1525,1550,1575,1600,1625,1650,1675,1700,1725,1750,1775,1800,1825,1850,1875,1900,1925,1950,1975,2000,2025,2050,2075,2100,2125,2150,2175,2200,2225,2250,2275,2300,2325,2350,2375,2400,2425,2450,2475,2500};
                    discreteDistanceInitIndex = "2 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelperZeroing')";
                    distanceZoomMin = 100;
                    distanceZoomMax = 2000;

                    memoryPointCamera = "opticView";
                    cameraDir = "";

                    opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
                    opticsFlare = 1;
                    opticsDisablePeripherialVision = 0;

                    visionMode[] = {};
                };
            };
        };
    };

    class CLASS(M98HA_Scope): OPTRE_SRS99_Scope
    {
        author = AUTHOR;
        SCOPE_PUBLIC;
        baseWeapon = QCLASS(M98HA_Scope);

        displayName = "[505th] M98H Argus Scope";
        model = "\OPTRE_Weapons\Sniper\SRS99D_Scope.p3d";
        picture = "\OPTRE_weapons\sniper\icons\scope.paa";

        weaponInfoType = "RscOptics_nightstalker";
        modelOptics = "\OPTRE_Weapons\Sniper\SRS99D_Scope.p3d";

        selectionFireAnim = "";
        fireAnim = "";

        class ItemInfo: ItemInfo
        {
            mass = 14;
            optics = 1;
            opticType = 1;
            modelOptics = "\OPTRE_Weapons\Sniper\SRS99D_Scope.p3d";

            class OpticsModes
            {
                class SRS99_Scope_View
                {
                    opticsID = 1;
                    useModelOptics = 1;

                    opticsZoomMin = 0.005;
                    opticsZoomMax = 0.25;
                    opticsZoomInit = 0.25;

                    discretefov[] = {0.25, 0.05, 0.025, 0.01, 0.005};
                    discreteinitIndex = 0;

                    discreteDistance[] = {100,125,150,175,200,225,250,275,300,325,350,375,400,425,450,475,500,525,550,575,600,625,650,675,700,725,750,775,800,825,850,875,900,925,950,975,1000,1025,1050,1075,1100,1125,1150,1175,1200,1225,1250,1275,1300,1325,1350,1375,1400,1425,1450,1475,1500,1525,1550,1575,1600,1625,1650,1675,1700,1725,1750,1775,1800,1825,1850,1875,1900,1925,1950,1975,2000,2025,2050,2075,2100,2125,2150,2175,2200,2225,2250,2275,2300,2325,2350,2375,2400,2425,2450,2475,2500};
                    discreteDistanceInitIndex = "0 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelperZeroing')";
                    distanceZoomMin = 100;
                    distanceZoomMax = 2000;

                    memoryPointCamera = "opticView";
                    modelOptics[] = {"\OPTRE_Weapons\Sniper\Sniper_Oracle10_Optic"};
                    opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};

                    visionMode[] = {"Normal", "NVG", "TI"};
                    thermalMode[] = {0, 1};
                    opticsFlare = 1;
                    opticsDisablePeripherialVision = 1;
                };
            };
        };
    };

    // Mode 1: IR Laser (default)
    class CLASS(ANPEQ6G): acc_pointer_IR
    {
        author = AUTHOR;
        SCOPE_PUBLIC;
        baseWeapon = QCLASS(ANPEQ6G);

        displayName = "[505th] AN/PEQ-6G (IR)";
        descriptionShort = "[505th] AN/PEQ-6G Laser Aiming Module - IR Mode";
        descriptionUse = "<t color='#9cf953'>Use: </t>[505th] Infrared laser pointer";

        model = "\TCP\Weapons\Acc\Rail\LAM_M6G\accv_pointer_lam_M6G.p3d";
        picture = "\TCP\Weapons\Acc\Rail\LAM_M6G\data\ui\icon_rail_lam_M6G_CA.paa";

        inertia = 0.1;

        MRT_SwitchItemNextClass = QCLASS(ANPEQ6G_VL);
        MRT_SwitchItemPrevClass = QCLASS(ANPEQ6G_VL);
        MRT_switchItemHintText = "IR Laser";

        class ItemInfo: InventoryFlashLightItem_Base_F
        {
            mass = 4;
            type = 301;

            class Pointer
            {
                irLaserPos = "laser pos";
                irLaserEnd = "laser dir";
                irDistance = 5;
            };
        };
    };

    // Mode 2: Visible Red Laser
    class CLASS(ANPEQ6G_VL): acc_pointer_IR
    {
        author = AUTHOR;
        SCOPE_HIDDEN;
        baseWeapon = QCLASS(ANPEQ6G_VL);

        displayName = "[505th] AN/PEQ-6G (VL)";
        descriptionShort = "[505th] AN/PEQ-6G Laser Aiming Module - Visible Laser Mode";
        descriptionUse = "<t color='#9cf953'>Use: </t>[505th] Visible red laser";

        model = "\TCP\Weapons\Acc\Rail\LAM_M6G\accv_pointer_lam_M6G.p3d";
        picture = "\TCP\Weapons\Acc\Rail\LAM_M6G\data\ui\icon_rail_lam_M6G_CA.paa";

        inertia = 0.1;

        MRT_SwitchItemNextClass = QCLASS(ANPEQ6G);
        MRT_SwitchItemPrevClass = QCLASS(ANPEQ6G);
        MRT_switchItemHintText = "Visible Laser";

        class ItemInfo: InventoryFlashLightItem_Base_F
        {
            mass = 4;
            type = 301;

            class Pointer
            {
                irLaserPos = "laser pos";
                irLaserEnd = "laser dir";
                irDistance = 5;
                beamColor[] = {15, 0, 0};
                beamMaxLength = 3000;
                beamThickness = 0.25;
                dotColor[] = {1000, 0, 0};
                dotSize = 1;
                isIR = 0;
            };
        };
    };
    // ============================================
    // === 505th MA37 LAM
    // ============================================

    // Mode 1: Visible Laser (default)
    class CLASS(MA37_LAM): acc_pointer_IR
    {
        author = AUTHOR;
        SCOPE_PUBLIC;
        baseWeapon = QCLASS(MA37_LAM);

        displayName = "[505th] MA37 LAM";
        descriptionShort = "[505th] MA37 Laser Aiming Module - Visible Laser";
        descriptionUse = "<t color='#9cf953'>Use: </t>[505th] Visible red laser";

        model = "\TCP\Weapons\Acc\Rail\LAM_MA37\accv_pointer_lam_MA37.p3d";
        picture = "\TCP\Weapons\Acc\Rail\LAM_MA37\data\ui\icon_lam_MA37_CA.paa";

        inertia = 0.1;

        MRT_SwitchItemNextClass = QCLASS(MA37_LAM_IR);
        MRT_SwitchItemPrevClass = QCLASS(MA37_LAM_IR);
        MRT_switchItemHintText = "Visible Laser";

        class ItemInfo: InventoryFlashLightItem_Base_F
        {
            mass = 4;
            type = 301;

            class Pointer
            {
                irLaserPos = "laser pos";
                irLaserEnd = "laser dir";
                irDistance = 5;
                beamColor[] = {15, 0, 0};
                beamMaxLength = 3000;
                beamThickness = 0.25;
                dotColor[] = {1000, 0, 0};
                dotSize = 1;
                isIR = 0;
            };
        };
    };

    // Mode 2: IR Laser
    class CLASS(MA37_LAM_IR): acc_pointer_IR
    {
        author = AUTHOR;
        SCOPE_HIDDEN;
        baseWeapon = QCLASS(MA37_LAM_IR);

        displayName = "[505th] MA37 LAM (IR)";
        descriptionShort = "[505th] MA37 Laser Aiming Module - IR Mode";
        descriptionUse = "<t color='#9cf953'>Use: </t>[505th] Infrared laser";

        model = "\TCP\Weapons\Acc\Rail\LAM_MA37\accv_pointer_lam_MA37.p3d";
        picture = "\TCP\Weapons\Acc\Rail\LAM_MA37\data\ui\icon_lam_MA37_CA.paa";

        inertia = 0.1;

        MRT_SwitchItemNextClass = QCLASS(MA37_LAM);
        MRT_SwitchItemPrevClass = QCLASS(MA37_LAM);
        MRT_switchItemHintText = "IR Laser";

        class ItemInfo: InventoryFlashLightItem_Base_F
        {
            mass = 4;
            type = 301;

            class Pointer
            {
                irLaserPos = "laser pos";
                irLaserEnd = "laser dir";
                irDistance = 5;
            };
        };
    };
};
