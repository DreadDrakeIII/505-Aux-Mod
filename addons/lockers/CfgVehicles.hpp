class CfgVehicles {
    class CLASS(Console_Base);
    class CLASS(Locker_Uniforms): CLASS(Console_Base) {
        SCOPE_PUBLIC;
        displayName = "Uniform Locker";

        class UserActions {
            class Arsenal_Customization {
                displayName = "<t color='#FFFFFF'>Customize Loadout<\t>";

                position = "camera";
                radius = 3;
                onlyForPlayers = TRUE;

                hideOnUse = TRUE;
                priority = 0;

                condition = QUOTE(GVAR(rankPage) == MENU_PAGE_HOME);
                statement = QUOTE('customize' call FUNC(openArsenal));
            };
        };
    };

    class CLASS(Locker_Loadouts): CLASS(Console_Base) {
        SCOPE_PUBLIC;
        displayName = "Loadout Locker";

        class UserActions {
            class Arsenal_Attachments {
                displayName = "<t color='#FFFFFF'>Weapon Attachments<\t>";

                position = "camera";
                radius = 3;
                onlyForPlayers = TRUE;

                hideOnUse = FALSE;
                priority = 1;

                condition = QUOTE(GVAR(loadoutPage) == MENU_PAGE_HOME);
                statement = QUOTE('attachments' call FUNC(openArsenal));
            };

            class Add_Radio: Arsenal_Attachments {
                displayName = "<t color='#FFFFFF'>Add Radio</t>";
                priority = 0;

                statement = QUOTE(ace_player linkItem 'TFAR_anprc152');
            };
        };
    };
};
