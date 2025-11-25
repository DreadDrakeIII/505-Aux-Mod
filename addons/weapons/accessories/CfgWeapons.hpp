class CfgWeapons
{
    // Parent classes from OPTRE
    class acc_pointer_IR;
    class ItemCore;
    class InventoryFlashLightItem_Base_F;

    // === EHB MEQ7 Attachment ===
    class OPTRE_BMR_Laser: acc_pointer_IR {};

    class CLASS(MEQ7): acc_pointer_IR
    {
        author = AUTHOR;
        SCOPE_PUBLIC;
        baseWeapon = QCLASS(MEQ7);

        displayName = "[505th] MEQ7 Attachment";
        descriptionShort = "MEQ7 IR, Visible Red Laser Pointer and Flashlight- Compatible with all weapons";
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

    // === Flashlight ===
    class OPTRE_BMR_MEQ_Flashlight: acc_pointer_IR {};

    class CLASS(FL_MEQ7_ATTACHMENT): ItemCore
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
                position = "laser";           // Uses "laser" memory point
                direction = "laser_dir";      // Uses "laser_dir" memory point
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

    // === Red Laser (from OPTRE config) ===
    class OPTRE_BMR_Vis_Red_Laser: acc_pointer_IR {};

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
                irLaserPos = "laser";         // Uses "laser" memory point
                irLaserEnd = "laser_dir";     // Uses "laser_dir" memory point
                irDistance = 5;

                // Red visible laser beam (from OPTRE config)
                beamColor[] = {15, 0, 0};     // Red beam color
                beamMaxLength = 3000;
                beamThickness = 0.25;
                dotColor[] = {1000, 0, 0};    // Red dot color (very bright)
                dotSize = 1;
                isIR = 0;                     // NOT infrared, visible!
            };
        };
    };
};
