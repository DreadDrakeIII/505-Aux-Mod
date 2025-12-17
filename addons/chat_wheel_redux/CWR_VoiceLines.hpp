// Multi-Language Voice Lines Configuration
// Added: NeedAmmo, EnemyInfantry, EnemyVehicle, EnemyAir, MedicalCheckReady, MedicalCheckWounded, MedicalCheckCasualties

class CWR_VoiceLines {

    // ============================================================================
    // AMERICAN ENGLISH (en_US)
    // ============================================================================
    class en_US {
        displayName = "American English";

        class NeedMedic {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_US\NeedMedic\AM_HitMedic.ogg",
                "ChatWheelRedux\Data\Audio\en_US\NeedMedic\AM_ImHit.ogg",
                "ChatWheelRedux\Data\Audio\en_US\NeedMedic\AM_ImHurtBad.ogg",
                "ChatWheelRedux\Data\Audio\en_US\NeedMedic\AM_ImWounded.ogg",
                "ChatWheelRedux\Data\Audio\en_US\NeedMedic\AM_NeedMedic.ogg"
            };
        };

        // NEW: Need Ammo
        class NeedAmmo {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_US\NeedAmmo\INeedAmmo.ogg",
                "ChatWheelRedux\Data\Audio\en_US\NeedAmmo\LowOnAmmo.ogg",
                "ChatWheelRedux\Data\Audio\en_US\NeedAmmo\RunningLow.ogg",
                "ChatWheelRedux\Data\Audio\en_US\NeedAmmo\NeedResupply.ogg",
                "ChatWheelRedux\Data\Audio\en_US\NeedAmmo\OutOfAmmo.ogg"
            };
        };

        // NEW: Enemy Infantry Contact
        class EnemyInfantry {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_US\EnemyContact\EnemyInfantry.ogg",
                "ChatWheelRedux\Data\Audio\en_US\EnemyContact\HostileInfantry.ogg",
                "ChatWheelRedux\Data\Audio\en_US\EnemyContact\ContactInfantry.ogg",
                "ChatWheelRedux\Data\Audio\en_US\EnemyContact\EnemyTroopsSpotted.ogg"
            };
        };

        // NEW: Enemy Vehicle Contact
        class EnemyVehicle {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_US\EnemyContact\EnemyVehicle.ogg",
                "ChatWheelRedux\Data\Audio\en_US\EnemyContact\HostileVehicle.ogg",
                "ChatWheelRedux\Data\Audio\en_US\EnemyContact\ContactVehicle.ogg",
                "ChatWheelRedux\Data\Audio\en_US\EnemyContact\EnemyArmorSpotted.ogg"
            };
        };

        // NEW: Enemy Air Contact
        class EnemyAir {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_US\EnemyContact\EnemyAir.ogg",
                "ChatWheelRedux\Data\Audio\en_US\EnemyContact\HostileAircraft.ogg",
                "ChatWheelRedux\Data\Audio\en_US\EnemyContact\ContactAir.ogg",
                "ChatWheelRedux\Data\Audio\en_US\EnemyContact\EnemyBirdInbound.ogg"
            };
        };

        // NEW: Medical Check - Combat Ready
        class MedicalCheckReady {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_US\MedicalCheck\CombatReady.ogg",
                "ChatWheelRedux\Data\Audio\en_US\MedicalCheck\ImGood.ogg",
                "ChatWheelRedux\Data\Audio\en_US\MedicalCheck\ReadyToFight.ogg",
                "ChatWheelRedux\Data\Audio\en_US\MedicalCheck\AllGoodHere.ogg"
            };
        };

        // NEW: Medical Check - Wounded
        class MedicalCheckWounded {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_US\MedicalCheck\ImWounded.ogg",
                "ChatWheelRedux\Data\Audio\en_US\MedicalCheck\ImHit.ogg",
                "ChatWheelRedux\Data\Audio\en_US\MedicalCheck\TookDamage.ogg",
                "ChatWheelRedux\Data\Audio\en_US\MedicalCheck\NeedTreatment.ogg"
            };
        };

        // NEW: Medical Check - Casualties
        class MedicalCheckCasualties {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_US\MedicalCheck\WehaveaCasualty.ogg",
                "ChatWheelRedux\Data\Audio\en_US\MedicalCheck\ManDown.ogg",
                "ChatWheelRedux\Data\Audio\en_US\MedicalCheck\CasualtyHere.ogg",
                "ChatWheelRedux\Data\Audio\en_US\MedicalCheck\NeedMedicAtMyPosition.ogg"
            };
        };

        class ThrowGrenade {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_US\Throw\GrenadeDeployed.ogg",
                "ChatWheelRedux\Data\Audio\en_US\Throw\GrenadeOutTakeThis.ogg",
                "ChatWheelRedux\Data\Audio\en_US\Throw\MakeRoomGrenade.ogg"
            };
        };

        class ThrowSmoke {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_US\Throw\SmokeCoverIncoming.ogg",
                "ChatWheelRedux\Data\Audio\en_US\Throw\SmokeGetReady.ogg",
                "ChatWheelRedux\Data\Audio\en_US\Throw\SmokeGrenade.ogg"
            };
        };

        class Unconscious {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_US\Unconscious\AGoodDeathFriendlyDown.ogg",
                "ChatWheelRedux\Data\Audio\en_US\Unconscious\LostOneFriendlyDown.ogg",
                "ChatWheelRedux\Data\Audio\en_US\Unconscious\FriendlyDown.ogg",
                "ChatWheelRedux\Data\Audio\en_US\Unconscious\ManDownStayTogether.ogg"
            };
        };
    };

    // ============================================================================
    // BRITISH ENGLISH (en_GB)
    // ============================================================================
    class en_GB {
        displayName = "British English";

        class NeedMedic {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_GB\NeedMedic\UK_HitMedic.ogg",
                "ChatWheelRedux\Data\Audio\en_GB\NeedMedic\UK_ImHit.ogg",
                "ChatWheelRedux\Data\Audio\en_GB\NeedMedic\UK_ImHurtBad.ogg",
                "ChatWheelRedux\Data\Audio\en_GB\NeedMedic\UK_ImWounded.ogg",
                "ChatWheelRedux\Data\Audio\en_GB\NeedMedic\UK_NeedMedic.ogg"
            };
        };

        class NeedAmmo {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_GB\NeedAmmo\INeedAmmo.wss"
            };
        };

        class EnemyInfantry {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_GB\EnemyContact\EnemyInfantry.wss"
            };
        };

        class EnemyVehicle {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_GB\EnemyContact\EnemyVehicle.wss"
            };
        };

        class EnemyAir {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_GB\EnemyContact\EnemyAir.wss"
            };
        };

        class MedicalCheckReady {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_GB\MedicalCheck\CombatReady.wss"
            };
        };

        class MedicalCheckWounded {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_GB\MedicalCheck\ImWounded.wss"
            };
        };

        class MedicalCheckCasualties {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_GB\MedicalCheck\WehaveaCasualty.wss"
            };
        };

        class ThrowGrenade {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_GB\Throw\GrenadeDeployed.wss"
            };
        };

        class ThrowSmoke {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_GB\Throw\SmokeCoverIncoming.wss"
            };
        };

        class Unconscious {
            voiceLines[] = {
                "ChatWheelRedux\Data\Audio\en_GB\Unconscious\FriendlyDown.wss"
            };
        };
    };
};
