#define FEF_SOUND(CLASS, PATH) \
    class CLASS { \
        name = #CLASS; \
        sound[] = {PATH, 1, 1}; \
        titles[] = {}; \
    }

class CfgSounds {
    sounds[] = {
        // en_US - NeedMedic
        "FEF_US_NeedMedic_HitMedic",
        "FEF_US_NeedMedic_ImHit",
        "FEF_US_NeedMedic_ImHurtBad",
        "FEF_US_NeedMedic_ImWounded",
        "FEF_US_NeedMedic_NeedMedic",

        // en_US - NeedAmmo
        "FEF_US_NeedAmmo_INeedAmmo",
        "FEF_US_NeedAmmo_LowOnAmmo",
        "FEF_US_NeedAmmo_RunningLow",
        "FEF_US_NeedAmmo_NeedResupply",
        "FEF_US_NeedAmmo_OutOfAmmo",

        // en_US - EnemyContact
        "FEF_US_EnemyInfantry_EnemyInfantry",
        "FEF_US_EnemyInfantry_HostileInfantry",
        "FEF_US_EnemyInfantry_ContactInfantry",
        "FEF_US_EnemyInfantry_EnemyTroopsSpotted",
        "FEF_US_EnemyVehicle_EnemyVehicle",
        "FEF_US_EnemyVehicle_HostileVehicle",
        "FEF_US_EnemyVehicle_ContactVehicle",
        "FEF_US_EnemyVehicle_EnemyArmorSpotted",
        "FEF_US_EnemyAir_EnemyAir",
        "FEF_US_EnemyAir_HostileAircraft",
        "FEF_US_EnemyAir_ContactAir",
        "FEF_US_EnemyAir_EnemyBirdInbound",

        // en_US - MedicalCheck
        "FEF_US_MedicalCheckReady_CombatReady",
        "FEF_US_MedicalCheckReady_ImGood",
        "FEF_US_MedicalCheckReady_ReadyToFight",
        "FEF_US_MedicalCheckReady_AllGoodHere",
        "FEF_US_MedicalCheckWounded_ImWounded",
        "FEF_US_MedicalCheckWounded_ImHit",
        "FEF_US_MedicalCheckWounded_TookDamage",
        "FEF_US_MedicalCheckWounded_NeedTreatment",
        "FEF_US_MedicalCheckCasualties_WeHaveACasualty",
        "FEF_US_MedicalCheckCasualties_ManDown",
        "FEF_US_MedicalCheckCasualties_CasualtyHere",
        "FEF_US_MedicalCheckCasualties_NeedMedicAtMyPosition",

        // en_US - Throw
        "FEF_US_ThrowGrenade_GrenadeDeployed",
        "FEF_US_ThrowGrenade_GrenadeOutTakeThis",
        "FEF_US_ThrowGrenade_MakeRoomGrenade",
        "FEF_US_ThrowSmoke_SmokeCoverIncoming",
        "FEF_US_ThrowSmoke_SmokeGetReady",
        "FEF_US_ThrowSmoke_SmokeGrenade",

        // en_US - Unconscious
        "FEF_US_Unconscious_AGoodDeathFriendlyDown",
        "FEF_US_Unconscious_LostOneFriendlyDown",
        "FEF_US_Unconscious_FriendlyDown",
        "FEF_US_Unconscious_ManDownStayTogether",

        // en_GB - NeedMedic
        "FEF_UK_NeedMedic_ImHitMedic",
        "FEF_UK_NeedMedic_ImHit",
        "FEF_UK_NeedMedic_ImWounded",
        "FEF_UK_NeedMedic_ImWoundedMedic",
        "FEF_UK_NeedMedic_NeedMedic",

        // en_GB - NeedAmmo
        "FEF_UK_NeedAmmo_INeedAmmo",

        // en_GB - EnemyContact
        "FEF_UK_EnemyInfantry_EnemyInfantry",
        "FEF_UK_EnemyVehicle_EnemyVehicle",
        "FEF_UK_EnemyAir_EnemyAir",

        // en_GB - MedicalCheck
        "FEF_UK_MedicalCheckReady_CombatReady",
        "FEF_UK_MedicalCheckWounded_ImWounded",
        "FEF_UK_MedicalCheckCasualties_WeHaveACasualty",

        // en_GB - Throw
        "FEF_UK_ThrowGrenade_GrenadeDeployed",
        "FEF_UK_ThrowSmoke_SmokeCoverIncoming",

        // en_GB - Unconscious
        "FEF_UK_Unconscious_FriendlyDown"
    };

    // ============================================================================
    // AMERICAN ENGLISH (en_US)
    // ============================================================================
    FEF_SOUND(FEF_US_NeedMedic_HitMedic, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\NeedMedic\AM_HitMedic.ogg");
    FEF_SOUND(FEF_US_NeedMedic_ImHit, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\NeedMedic\AM_ImHit.ogg");
    FEF_SOUND(FEF_US_NeedMedic_ImHurtBad, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\NeedMedic\AM_ImHurtBad.ogg");
    FEF_SOUND(FEF_US_NeedMedic_ImWounded, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\NeedMedic\AM_ImWounded.ogg");
    FEF_SOUND(FEF_US_NeedMedic_NeedMedic, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\NeedMedic\AM_NeedMedic.ogg");

    FEF_SOUND(FEF_US_NeedAmmo_INeedAmmo, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\NeedAmmo\INeedAmmo.ogg");
    FEF_SOUND(FEF_US_NeedAmmo_LowOnAmmo, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\NeedAmmo\LowOnAmmo.ogg");
    FEF_SOUND(FEF_US_NeedAmmo_RunningLow, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\NeedAmmo\RunningLow.ogg");
    FEF_SOUND(FEF_US_NeedAmmo_NeedResupply, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\NeedAmmo\NeedResupply.ogg");
    FEF_SOUND(FEF_US_NeedAmmo_OutOfAmmo, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\NeedAmmo\OutOfAmmo.ogg");

    FEF_SOUND(FEF_US_EnemyInfantry_EnemyInfantry, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\EnemyContact\EnemyInfantry.ogg");
    FEF_SOUND(FEF_US_EnemyInfantry_HostileInfantry, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\EnemyContact\HostileInfantry.ogg");
    FEF_SOUND(FEF_US_EnemyInfantry_ContactInfantry, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\EnemyContact\ContactInfantry.ogg");
    FEF_SOUND(FEF_US_EnemyInfantry_EnemyTroopsSpotted, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\EnemyContact\EnemyTroopsSpotted.ogg");

    FEF_SOUND(FEF_US_EnemyVehicle_EnemyVehicle, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\EnemyContact\EnemyVehicle.ogg");
    FEF_SOUND(FEF_US_EnemyVehicle_HostileVehicle, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\EnemyContact\HostileVehicle.ogg");
    FEF_SOUND(FEF_US_EnemyVehicle_ContactVehicle, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\EnemyContact\ContactVehicle.ogg");
    FEF_SOUND(FEF_US_EnemyVehicle_EnemyArmorSpotted, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\EnemyContact\EnemyArmorSpotted.ogg");

    FEF_SOUND(FEF_US_EnemyAir_EnemyAir, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\EnemyContact\EnemyAir.ogg");
    FEF_SOUND(FEF_US_EnemyAir_HostileAircraft, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\EnemyContact\HostileAircraft.ogg");
    FEF_SOUND(FEF_US_EnemyAir_ContactAir, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\EnemyContact\ContactAir.ogg");
    FEF_SOUND(FEF_US_EnemyAir_EnemyBirdInbound, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\EnemyContact\EnemyBirdInbound.ogg");

    FEF_SOUND(FEF_US_MedicalCheckReady_CombatReady, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\MedicalCheck\CombatReady.ogg");
    FEF_SOUND(FEF_US_MedicalCheckReady_ImGood, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\MedicalCheck\ImGood.ogg");
    FEF_SOUND(FEF_US_MedicalCheckReady_ReadyToFight, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\MedicalCheck\ReadyToFight.ogg");
    FEF_SOUND(FEF_US_MedicalCheckReady_AllGoodHere, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\MedicalCheck\AllGoodHere.ogg");

    FEF_SOUND(FEF_US_MedicalCheckWounded_ImWounded, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\MedicalCheck\ImWounded.ogg");
    FEF_SOUND(FEF_US_MedicalCheckWounded_ImHit, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\MedicalCheck\ImHit.ogg");
    FEF_SOUND(FEF_US_MedicalCheckWounded_TookDamage, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\MedicalCheck\TookDamage.ogg");
    FEF_SOUND(FEF_US_MedicalCheckWounded_NeedTreatment, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\MedicalCheck\NeedTreatment.ogg");

    FEF_SOUND(FEF_US_MedicalCheckCasualties_WeHaveACasualty, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\MedicalCheck\WeHaveACasualty.ogg");
    FEF_SOUND(FEF_US_MedicalCheckCasualties_ManDown, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\MedicalCheck\ManDown.ogg");
    FEF_SOUND(FEF_US_MedicalCheckCasualties_CasualtyHere, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\MedicalCheck\CasualtyHere.ogg");
    FEF_SOUND(FEF_US_MedicalCheckCasualties_NeedMedicAtMyPosition, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\MedicalCheck\NeedMedicAtMyPosition.ogg");

    FEF_SOUND(FEF_US_ThrowGrenade_GrenadeDeployed, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\Throw\GrenadeDeployed.ogg");
    FEF_SOUND(FEF_US_ThrowGrenade_GrenadeOutTakeThis, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\Throw\GrenadeOutTakeThis.ogg");
    FEF_SOUND(FEF_US_ThrowGrenade_MakeRoomGrenade, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\Throw\MakeRoomGrenade.ogg");

    FEF_SOUND(FEF_US_ThrowSmoke_SmokeCoverIncoming, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\Throw\SmokeCoverIncoming.ogg");
    FEF_SOUND(FEF_US_ThrowSmoke_SmokeGetReady, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\Throw\SmokeGetReady.ogg");
    FEF_SOUND(FEF_US_ThrowSmoke_SmokeGrenade, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\Throw\SmokeGrenade.ogg");

    FEF_SOUND(FEF_US_Unconscious_AGoodDeathFriendlyDown, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\Unconscious\AGoodDeathFriendlyDown.ogg");
    FEF_SOUND(FEF_US_Unconscious_LostOneFriendlyDown, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\Unconscious\LostOneFriendlyDown.ogg");
    FEF_SOUND(FEF_US_Unconscious_FriendlyDown, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\Unconscious\FriendlyDown.ogg");
    FEF_SOUND(FEF_US_Unconscious_ManDownStayTogether, "BLU\OLI\addons\fef_chat\Data\Audio\en_US\Unconscious\ManDownStayTogether.ogg");

    // ============================================================================
    // BRITISH ENGLISH (en_GB)
    // ============================================================================
    FEF_SOUND(FEF_UK_NeedMedic_ImHitMedic, "BLU\OLI\addons\fef_chat\Data\Audio\en_GB\NeedMedic\UK_ImHitMedic.ogg");
    FEF_SOUND(FEF_UK_NeedMedic_ImHit, "BLU\OLI\addons\fef_chat\Data\Audio\en_GB\NeedMedic\UK_ImHit.ogg");
    FEF_SOUND(FEF_UK_NeedMedic_ImWounded, "BLU\OLI\addons\fef_chat\Data\Audio\en_GB\NeedMedic\UK_ImWounded.ogg");
    FEF_SOUND(FEF_UK_NeedMedic_ImWoundedMedic, "BLU\OLI\addons\fef_chat\Data\Audio\en_GB\NeedMedic\UK_ImWoundedMedic.ogg");
    FEF_SOUND(FEF_UK_NeedMedic_NeedMedic, "BLU\OLI\addons\fef_chat\Data\Audio\en_GB\NeedMedic\UK_NeedMedic.ogg");

    FEF_SOUND(FEF_UK_NeedAmmo_INeedAmmo, "BLU\OLI\addons\fef_chat\Data\Audio\en_GB\NeedAmmo\INeedAmmo.ogg");

    FEF_SOUND(FEF_UK_EnemyInfantry_EnemyInfantry, "BLU\OLI\addons\fef_chat\Data\Audio\en_GB\EnemyContact\EnemyInfantry.ogg");
    FEF_SOUND(FEF_UK_EnemyVehicle_EnemyVehicle, "BLU\OLI\addons\fef_chat\Data\Audio\en_GB\EnemyContact\EnemyVehicle.ogg");
    FEF_SOUND(FEF_UK_EnemyAir_EnemyAir, "BLU\OLI\addons\fef_chat\Data\Audio\en_GB\EnemyContact\EnemyAir.ogg");

    FEF_SOUND(FEF_UK_MedicalCheckReady_CombatReady, "BLU\OLI\addons\fef_chat\Data\Audio\en_GB\MedicalCheck\CombatReady.ogg");
    FEF_SOUND(FEF_UK_MedicalCheckWounded_ImWounded, "BLU\OLI\addons\fef_chat\Data\Audio\en_GB\MedicalCheck\ImWounded.ogg");
    FEF_SOUND(FEF_UK_MedicalCheckCasualties_WeHaveACasualty, "BLU\OLI\addons\fef_chat\Data\Audio\en_GB\MedicalCheck\WeHaveACasualty.ogg");

    FEF_SOUND(FEF_UK_ThrowGrenade_GrenadeDeployed, "BLU\OLI\addons\fef_chat\Data\Audio\en_GB\Throw\GrenadeDeployed.ogg");
    FEF_SOUND(FEF_UK_ThrowSmoke_SmokeCoverIncoming, "BLU\OLI\addons\fef_chat\Data\Audio\en_GB\Throw\SmokeCoverIncoming.ogg");

    FEF_SOUND(FEF_UK_Unconscious_FriendlyDown, "BLU\OLI\addons\fef_chat\Data\Audio\en_GB\Unconscious\FriendlyDown.ogg");
};

#undef FEF_SOUND
