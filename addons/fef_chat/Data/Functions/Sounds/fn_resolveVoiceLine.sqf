params ["_voiceKey"];

private _profile = missionNamespace getVariable ["FEF_Voice_Profile", "en_US"];
private _result = "";

switch (_profile) do {
    case "en_GB": {
        switch (_voiceKey) do {
            case "NeedMedic": {
                _result = selectRandom [
                    "FEF_UK_NeedMedic_ImHitMedic",
                    "FEF_UK_NeedMedic_ImHit",
                    "FEF_UK_NeedMedic_ImWounded",
                    "FEF_UK_NeedMedic_ImWoundedMedic",
                    "FEF_UK_NeedMedic_NeedMedic"
                ];
            };
            case "NeedAmmo": {
                _result = selectRandom [
                    "FEF_UK_NeedAmmo_INeedAmmo"
                ];
            };
            case "EnemyInfantry": {
                _result = selectRandom [
                    "FEF_UK_EnemyInfantry_EnemyInfantry"
                ];
            };
            case "EnemyVehicle": {
                _result = selectRandom [
                    "FEF_UK_EnemyVehicle_EnemyVehicle"
                ];
            };
            case "EnemyAir": {
                _result = selectRandom [
                    "FEF_UK_EnemyAir_EnemyAir"
                ];
            };
            case "MedicalCheckReady": {
                _result = selectRandom [
                    "FEF_UK_MedicalCheckReady_CombatReady"
                ];
            };
            case "MedicalCheckWounded": {
                _result = selectRandom [
                    "FEF_UK_MedicalCheckWounded_ImWounded"
                ];
            };
            case "MedicalCheckCasualties": {
                _result = selectRandom [
                    "FEF_UK_MedicalCheckCasualties_WeHaveACasualty"
                ];
            };
            case "ThrowGrenade": {
                _result = selectRandom [
                    "FEF_UK_ThrowGrenade_GrenadeDeployed"
                ];
            };
            case "ThrowSmoke": {
                _result = selectRandom [
                    "FEF_UK_ThrowSmoke_SmokeCoverIncoming"
                ];
            };
            case "Unconscious": {
                _result = selectRandom [
                    "FEF_UK_Unconscious_FriendlyDown"
                ];
            };
        };
    };

    default {
        switch (_voiceKey) do {
            case "NeedMedic": {
                _result = selectRandom [
                    "FEF_US_NeedMedic_HitMedic",
                    "FEF_US_NeedMedic_ImHit",
                    "FEF_US_NeedMedic_ImHurtBad",
                    "FEF_US_NeedMedic_ImWounded",
                    "FEF_US_NeedMedic_NeedMedic"
                ];
            };
            case "NeedAmmo": {
                _result = selectRandom [
                    "FEF_US_NeedAmmo_INeedAmmo",
                    "FEF_US_NeedAmmo_LowOnAmmo",
                    "FEF_US_NeedAmmo_RunningLow",
                    "FEF_US_NeedAmmo_NeedResupply",
                    "FEF_US_NeedAmmo_OutOfAmmo"
                ];
            };
            case "EnemyInfantry": {
                _result = selectRandom [
                    "FEF_US_EnemyInfantry_EnemyInfantry",
                    "FEF_US_EnemyInfantry_HostileInfantry",
                    "FEF_US_EnemyInfantry_ContactInfantry",
                    "FEF_US_EnemyInfantry_EnemyTroopsSpotted"
                ];
            };
            case "EnemyVehicle": {
                _result = selectRandom [
                    "FEF_US_EnemyVehicle_EnemyVehicle",
                    "FEF_US_EnemyVehicle_HostileVehicle",
                    "FEF_US_EnemyVehicle_ContactVehicle",
                    "FEF_US_EnemyVehicle_EnemyArmorSpotted"
                ];
            };
            case "EnemyAir": {
                _result = selectRandom [
                    "FEF_US_EnemyAir_EnemyAir",
                    "FEF_US_EnemyAir_HostileAircraft",
                    "FEF_US_EnemyAir_ContactAir",
                    "FEF_US_EnemyAir_EnemyBirdInbound"
                ];
            };
            case "MedicalCheckReady": {
                _result = selectRandom [
                    "FEF_US_MedicalCheckReady_CombatReady",
                    "FEF_US_MedicalCheckReady_ImGood",
                    "FEF_US_MedicalCheckReady_ReadyToFight",
                    "FEF_US_MedicalCheckReady_AllGoodHere"
                ];
            };
            case "MedicalCheckWounded": {
                _result = selectRandom [
                    "FEF_US_MedicalCheckWounded_ImWounded",
                    "FEF_US_MedicalCheckWounded_ImHit",
                    "FEF_US_MedicalCheckWounded_TookDamage",
                    "FEF_US_MedicalCheckWounded_NeedTreatment"
                ];
            };
            case "MedicalCheckCasualties": {
                _result = selectRandom [
                    "FEF_US_MedicalCheckCasualties_WeHaveACasualty",
                    "FEF_US_MedicalCheckCasualties_ManDown",
                    "FEF_US_MedicalCheckCasualties_CasualtyHere",
                    "FEF_US_MedicalCheckCasualties_NeedMedicAtMyPosition"
                ];
            };
            case "ThrowGrenade": {
                _result = selectRandom [
                    "FEF_US_ThrowGrenade_GrenadeDeployed",
                    "FEF_US_ThrowGrenade_GrenadeOutTakeThis",
                    "FEF_US_ThrowGrenade_MakeRoomGrenade"
                ];
            };
            case "ThrowSmoke": {
                _result = selectRandom [
                    "FEF_US_ThrowSmoke_SmokeCoverIncoming",
                    "FEF_US_ThrowSmoke_SmokeGetReady",
                    "FEF_US_ThrowSmoke_SmokeGrenade"
                ];
            };
            case "Unconscious": {
                _result = selectRandom [
                    "FEF_US_Unconscious_AGoodDeathFriendlyDown",
                    "FEF_US_Unconscious_LostOneFriendlyDown",
                    "FEF_US_Unconscious_FriendlyDown",
                    "FEF_US_Unconscious_ManDownStayTogether"
                ];
            };
        };
    };
};

_result
