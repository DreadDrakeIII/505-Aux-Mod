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
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\NeedMedic\AM_HitMedic.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\NeedMedic\AM_ImHit.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\NeedMedic\AM_ImHurtBad.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\NeedMedic\AM_ImWounded.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\NeedMedic\AM_NeedMedic.ogg"
            };
        };

        class NeedAmmo {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\NeedAmmo\INeedAmmo.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\NeedAmmo\LowOnAmmo.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\NeedAmmo\RunningLow.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\NeedAmmo\NeedResupply.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\NeedAmmo\OutOfAmmo.ogg"
            };
        };

        class EnemyInfantry {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\EnemyContact\EnemyInfantry.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\EnemyContact\HostileInfantry.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\EnemyContact\ContactInfantry.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\EnemyContact\EnemyTroopsSpotted.ogg"
            };
        };

        class EnemyVehicle {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\EnemyContact\EnemyVehicle.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\EnemyContact\HostileVehicle.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\EnemyContact\ContactVehicle.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\EnemyContact\EnemyArmorSpotted.ogg"
            };
        };

        class EnemyAir {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\EnemyContact\EnemyAir.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\EnemyContact\HostileAircraft.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\EnemyContact\ContactAir.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\EnemyContact\EnemyBirdInbound.ogg"
            };
        };

        class MedicalCheckReady {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\MedicalCheck\CombatReady.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\MedicalCheck\ImGood.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\MedicalCheck\ReadyToFight.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\MedicalCheck\AllGoodHere.ogg"
            };
        };

        class MedicalCheckWounded {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\MedicalCheck\ImWounded.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\MedicalCheck\ImHit.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\MedicalCheck\TookDamage.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\MedicalCheck\NeedTreatment.ogg"
            };
        };

        class MedicalCheckCasualties {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\MedicalCheck\WehaveaCasualty.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\MedicalCheck\ManDown.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\MedicalCheck\CasualtyHere.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\MedicalCheck\NeedMedicAtMyPosition.ogg"
            };
        };

        class ThrowGrenade {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\Throw\GrenadeDeployed.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\Throw\GrenadeOutTakeThis.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\Throw\MakeRoomGrenade.ogg"
            };
        };

        class ThrowSmoke {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\Throw\SmokeCoverIncoming.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\Throw\SmokeGetReady.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\Throw\SmokeGrenade.ogg"
            };
        };

        class Unconscious {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\Unconscious\AGoodDeathFriendlyDown.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\Unconscious\LostOneFriendlyDown.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\Unconscious\FriendlyDown.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_US\Unconscious\ManDownStayTogether.ogg"
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
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_GB\NeedMedic\UK_HitMedic.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_GB\NeedMedic\UK_ImHit.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_GB\NeedMedic\UK_ImHurtBad.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_GB\NeedMedic\UK_ImWounded.ogg",
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_GB\NeedMedic\UK_NeedMedic.ogg"
            };
        };

        class NeedAmmo {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_GB\NeedAmmo\INeedAmmo.wss"
            };
        };

        class EnemyInfantry {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_GB\EnemyContact\EnemyInfantry.wss"
            };
        };

        class EnemyVehicle {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_GB\EnemyContact\EnemyVehicle.wss"
            };
        };

        class EnemyAir {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_GB\EnemyContact\EnemyAir.wss"
            };
        };

        class MedicalCheckReady {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_GB\MedicalCheck\CombatReady.wss"
            };
        };

        class MedicalCheckWounded {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_GB\MedicalCheck\ImWounded.wss"
            };
        };

        class MedicalCheckCasualties {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_GB\MedicalCheck\WehaveaCasualty.wss"
            };
        };

        class ThrowGrenade {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_GB\Throw\GrenadeDeployed.wss"
            };
        };

        class ThrowSmoke {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_GB\Throw\SmokeCoverIncoming.wss"
            };
        };

        class Unconscious {
            voiceLines[] = {
                "BLU\OLI\addons\chat_wheel_redux\Data\Audio\en_GB\Unconscious\FriendlyDown.wss"
            };
        };
    };
};
