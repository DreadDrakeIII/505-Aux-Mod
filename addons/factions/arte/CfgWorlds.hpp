class CfgWorlds {
    class GenericNames {
        class CLASS(Wolf_Soldier) {
            class FirstNames {
                Wolf = "Wolf";
            };
            class LastNames {
                Soldier = "Soldier";
            };
        };
        class CLASS(Jager_Soldier): CLASS(Wolf_Soldier) {
            class FirstNames {
                Jager = "Jager";
            };
            class LastNames {
                Soldier = "Soldier";
            };
        };
    };
};
