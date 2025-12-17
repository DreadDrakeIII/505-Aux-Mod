// Patch OPTRE's HUD schemes to recognize our mask
class CfgOptreHudSchemes {
    class Glasses {
        class MainDialogs {
            // Register our mask with OPTRE HUD system
            CLASS(Stealth_Balaclava) = "OPTRE_MarrineGlasses_black";
            CLASS(DAVY_MASK) = "OPTRE_MarrineGlasses_black";
        };
    };
};
