// STK Vector 21 - Custom Reticle Integration
// Original by rat 505, integrated into 505th Aux Mod

class CfgWeapons
{
    // 505th Beret (Black) - TCP beret base
    class TCP_H_Beret_Black;
    class CLASS(Beret_Black): TCP_H_Beret_Black {
        SCOPE_PUBLIC;
        author = AUTHOR;
        displayName = "[505th] Beret (Black)";
    };

    // 505th Boonie Hats - TCP bases
    class TCP_H_boonieHat_Gray;
    class CLASS(Boonie_Gray): TCP_H_boonieHat_Gray {
        SCOPE_PUBLIC;
        author = AUTHOR;
        displayName = "[505th] Boonie Hat (Gray)";
    };
    class TCP_H_boonieHat_Folded_Left_Gray;
    class CLASS(Boonie_Folded_Left_Gray): TCP_H_boonieHat_Folded_Left_Gray {
        SCOPE_PUBLIC;
        author = AUTHOR;
        displayName = "[505th] Boonie Hat (Gray, Folded Left)";
    };
    class TCP_H_boonieHat_Folded_Right_Gray;
    class CLASS(Boonie_Folded_Right_Gray): TCP_H_boonieHat_Folded_Right_Gray {
        SCOPE_PUBLIC;
        author = AUTHOR;
        displayName = "[505th] Boonie Hat (Gray, Folded Right)";
    };

    class ACE_Vector;

    class CLASS(Vector): ACE_Vector
    {
        SCOPE_PUBLIC;
        author = AUTHOR;
        displayName = "[505th] Vector 21";
        baseWeapon = QCLASS(Vector);

        visionMode[] = { "Normal", "NVG", "Ti" };
        thermalMode[] = { 0 };

        // 6-24x zoom (1:4 ratio) - formula: 0.25 / MAGNIFICATION
        opticsZoomMax = 0.0416666667;
        opticsZoomMin = 0.0104166667;

        class CBA_ScriptedOptic
        {
            reticleTexture      = "\BLU\OLI\addons\gears\ui\stk_vector_reticle_ca.paa";
            reticleTextureSize  = 0.907;

            bodyTexture         = "\z\ace\addons\vector\data\reticles\ace_vector_body_co.paa";

            bodyTextureSize = 1.8;
            reticleSafezoneSize = 0.7;
            hidePeripheralVision = 1;

            opticsPPEffects[] = {"ace_vector_OpticsRadBlur1"};

            disableTilt = 1;
        };
    };
};
