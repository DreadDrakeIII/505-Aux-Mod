// Patch OPTRE's HUD schemes to recognize our mask
class CfgOptreHudSchemes {
    class Glasses {
        class MainDialogs {
            // Register our mask with OPTRE HUD system
            CLASS(Stealth_Mask_Goggle) = "OPTRE_MarrineGlasses_black";
            CLASS(Davy_Mask_Goggle) = "OPTRE_MarrineGlasses_black";
            CLASS(Stealth_Mask) = "OPTRE_MarrineGlasses_black";
        };
    };
};
