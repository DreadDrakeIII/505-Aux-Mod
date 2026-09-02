class CBA_Extended_EventHandlers;

class CfgVehicles {
    class Land_OPTRE_AFB_sign;
    class CLASS(AFB_Sign_1): Land_OPTRE_AFB_sign {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "505th Airbase Sign (BJL)";

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Signs);

        hiddenSelections[] = {"Sign"};
        hiddenSelectionsMaterials[] = {QPATHTOF(data\signs\AirbaseSign_NOHQ.paa)};
        hiddenSelectionsTextures[] = {QPATHTOF(data\signs\AirbaseSign1_CO.paa)};
    };

    class CLASS(OP_Sign_1): Land_OPTRE_AFB_sign {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "505th Outpost Sign (NS)";

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Signs);

        hiddenSelections[] = {"Sign"};
        hiddenSelectionsMaterials[] = {QPATHTOF(data\signs\AirbaseSign_NOHQ.paa)};
        hiddenSelectionsTextures[] = {QPATHTOF(data\signs\AirbaseSign2_CO.paa)};
    };

    class Banner_01_F;
    class CLASS(Banner_505th): Banner_01_F {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "505th Banner";

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Flags);

        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\flags\505th_co.paa)};
    };

    class Flag_White_F;
    class CLASS(Flag_505th_Pole): Flag_White_F {
        SCOPE_PUBLIC;
        author = AUTHOR;

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Flags);

        displayName = "505th Flag (Pole)";

        class EventHandlers {
            init = QUOTE((_this select 0) setFlagTexture QQPATHTOF(data\flags\505th_co.paa));
        };
    };
    class CLASS(Flag_505th_Damaged_Pole): CLASS(Flag_505th_Pole) {
        displayName = "505th Damaged Flag (Pole)";
        class EventHandlers {
            init = QUOTE((_this select 0) setFlagTexture QQPATHTOF(data\flags\505th_Damaged_co.paa));
        };
    };

    class OPTRE_RS_ConsoleDoor;
    class CLASS(Console_Base): OPTRE_RS_ConsoleDoor {
        SCOPE_PRIVATE;
        author = AUTHOR;

        // Editor Attributes
        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Utility);
        editorPreview = "OPTRE_Misc\Image\OPTRE\Corvette\OPTRE_RS_ConsoleDoor.jpg";

        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        };
    };

    class CLASS(Console_Permissions): CLASS(Console_Base) {
        SCOPE_PUBLIC;
        displayName = "Permissions Terminal";

        class UserActions {
            class Assign_Medic {
                displayName = QUOTE(<t color='#c40000'><img image=QQPATHTOEF(main,data\ui\Medic_White_ca.paa)/> Assign Medic Permissions</t>);

                position = "camera";
                radius = 3;
                onlyForPlayer = TRUE;

                hideOnUse = TRUE;
                priority = 100;

                condition = QUOTE(!(ace_player call EFUNC(main,isMedic)));
                statement = QUOTE([ARR_2(ace_player,1)] call EFUNC(main,setMedic));
            };
            class Unassign_Medic: Assign_Medic {
                displayName = QUOTE(<t color='#c40000'><img image=QQPATHTOEF(main,data\ui\Medic_White_ca.paa)/> Unassign Medic Permissions</t>);
                condition = QUOTE(ace_player call EFUNC(main,isMedic));
                statement = QUOTE([ARR_2(ace_player,0)] call EFUNC(main,setMedic));
            };
            class Assign_Engineer: Assign_Medic {
                displayName = QUOTE(<t color='#f0be00'><img image=QQPATHTOEF(main,data\ui\EOD_White_ca.paa)/> Assign Engineer Permissions</t>);
                condition = QUOTE(!(ace_player call EFUNC(main,isEngineer)));
                statement = QUOTE([ARR_2(ace_player,2)] call EFUNC(main,setEngineer));
            };
            class Unassign_Engineer: Assign_Engineer {
                displayName = QUOTE(<t color='#f0be00'><img image=QQPATHTOEF(main,data\ui\EOD_White_ca.paa)/> Unassign Engineer Permissions</t>);
                condition = QUOTE(ace_player call EFUNC(main,isEngineer));
                statement = QUOTE([ARR_2(ace_player,0)] call EFUNC(main,setEngineer));
            };
        };
    };
    class CLASS(SideSwapper): CLASS(Console_Base) {
        SCOPE_PUBLIC;
        author = AUTHOR;

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Utility);

        displayName = "Side Swap Terminal";
        class UserActions {
            class Swap_Bluefor
            {
                displayName = "<t color='#003cff'> Swap to BluFor</t>";
				position = "pos cano";
				radius = 15;
                condition = "True";
				statement = QUOTE([ARR_1(player)] joinSilent (createGroup [ARR_2(west,true)]); hint 'Swapped to BluFor';);
				onlyforplayer = "false";
				hideOnUse = 0;
            };
            class Swap_Redfor
            {
                displayName = "<t color='#ff2600'> Swap to OpFor</t>";
				position = "pos cano";
				radius = 15;
                condition = "True";
				statement = QUOTE([ARR_1(player)] joinSilent (createGroup [ARR_2(east,true)]); hint 'Swapped to OpFor';);
				onlyforplayer = "false";
				hideOnUse = 0;
            };
            class Side_Indie
            {
                displayName = "<t color='#009919'> Swap to Independant</t>";
				position = "pos cano";
				radius = 15;
                condition = "True";
				statement = QUOTE([ARR_1(player)] joinSilent (createGroup [ARR_2(resistance,true)]); hint 'Swapped to Independant';);
				onlyforplayer = "false";
				hideOnUse = 0;
            };
            class Side_Civ
            {
                displayName = "<t color='#8200ba'> Swap to Civilian</t>";
				position = "pos cano";
				radius = 15;
                condition = "True";
				statement = QUOTE([ARR_1(player)] joinSilent (createGroup [ARR_2(civilian,true)]); hint 'Swapped to Civilian';);
				onlyforplayer = "false";
				hideOnUse = 0;
            };
        };
    };

    class Land_Optican_Kiosk_sm;
    class CLASS(Utility_FullHeal_Small): Land_Optican_Kiosk_sm {
        SCOPE_PUBLIC;
        displayName = "Full Heal Station (Small)";
        model = "\OPTRE_Buildings\CityObjects\Optican_Kiosk_sm";
        editorPreview = "OPTRE_Misc\Image\OPTRE\Building\Land_Optican_Kiosk_sm.jpg";

        // Editor Attributes
        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Utility);

        class UserActions {
            class FullHeal {
                displayName = "<t color='#c40000'><img image='z\ace\addons\zeus\ui\icon_module_zeus_heal_ca.paa'/> Recieve Treatment</t>";

                position = "camera";
                radius = 3;
                onlyForPlayer = TRUE;

                hideOnUse = FALSE;
                priority = 100;

                condition = "true";
            };
        };
    };

    class Land_Optican_Kiosk_lg;
    class CLASS(Utility_FullHeal_Large): Land_Optican_Kiosk_lg {
        SCOPE_PUBLIC;
        displayName = "Full Heal Station (Large)";
        model = "\OPTRE_Buildings\CityObjects\Optican_Kiosk_lg";
        editorPreview = "OPTRE_Misc\Image\OPTRE\Building\Land_Optican_Kiosk_lg.jpg";

        // Editor Attributes
        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Utility);

        class UserActions {
            class FullHeal {
                displayName = "<t color='#c40000'><img image='z\ace\addons\zeus\ui\icon_module_zeus_heal_ca.paa'/> Recieve Treatment</t>";

                position = "camera";
                radius = 3;
                onlyForPlayer = TRUE;

                hideOnUse = FALSE;
                priority = 100;

                condition = "true";
            };
        };
    };

        class OPTRE_Furniture_AmmoRack_BR55;

        // Corpsman Loadout Locker
    class CLASS(HMLoadout_Arsenal): OPTRE_Furniture_AmmoRack_BR55 {
            SCOPE_PUBLIC;
            author = AUTHOR;
            displayName = "[505th] Corpsman Loadout and Arsenal & Kit Locker";
            model = "OPTRE_BW_Buildings\Furniture\WeaponsRack_BR\WeaponsRack_AR";
            editorPreview = "\OPTRE_Misc\Image\OPTRE\BW_Buildings\OPTRE_Furniture_AmmoRack_BR55.jpg";

            hiddenSelections[] = {"Texture_Case","Texture_Inside","Texture_Parts"};
            hiddenSelectionsTextures[] = {
                "\BLU\OLI\addons\objects\data\lockers\corpsman_case_co.paa",
                "\BLU\OLI\addons\objects\data\lockers\corpsman_case_inside_co.paa",
                "OPTRE_BW_Buildings\Furniture\Data\parts_co.paa"
                };

            editorCategory = QEDCAT(Objects);
            editorSubcategory = QEDSUBCAT(Utility);

        // --- ACE / BIS Arsenal ---
        class UserActions {
            class Arsenal_ACE {
                displayName = QUOTE(<t color='#a02116'><img image=QQPATHTOEF(main,data\ui\ACE_logo_small_ca.paa)/> Custom Arsenal Access</t>);
                position = "camera";
                radius = 3;
                onlyForPlayer = TRUE;
                hideOnUse = TRUE;
                priority = 100;
                condition = "true";
                statement = "[cursorObject, player, false] call ace_arsenal_fnc_openBox";
            };

            class Add_Radio: Arsenal_ACE {
                displayName = "<t color='#E6E6E6'><img image='\a3\modules_f_curator\data\portraitradio_ca.paa'/> Add Radio</t>";
                statement = QUOTE(ace_player linkItem 'TFAR_anprc152');
            };
        };

            // CBA Extended Event Handlers - handled by CfgEventHandlers.hpp
            class EventHandlers {
                class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
            };
    };

        // FR Loadout Locker
    class CLASS(FRLoadout_Arsenal): OPTRE_Furniture_AmmoRack_BR55 {
            SCOPE_PUBLIC;
            author = AUTHOR;
            displayName = "[505th] FR Loadout and Arsenal & Kit Locker";
            model = "OPTRE_BW_Buildings\Furniture\WeaponsRack_BR\WeaponsRack_AR";
            editorPreview = "\OPTRE_Misc\Image\OPTRE\BW_Buildings\OPTRE_Furniture_AmmoRack_BR55.jpg";

            hiddenSelections[] = {"Texture_Case","Texture_Inside","Texture_Parts"};
            hiddenSelectionsTextures[] = {
                "\BLU\OLI\addons\objects\data\lockers\fr_case_co.paa",
                "\BLU\OLI\addons\objects\data\lockers\fr_case_inside_co.paa",
                "OPTRE_BW_Buildings\Furniture\Data\parts_co.paa"
                };

            editorCategory = QEDCAT(Objects);
            editorSubcategory = QEDSUBCAT(Utility);
        // --- ACE Arsenal ---
    class UserActions {
        class Arsenal_ACE {
            displayName = QUOTE(<t color='#a02116'><img image=QQPATHTOEF(main,data\ui\ACE_logo_small_ca.paa)/> Custom Arsenal Access</t>);
            position = "camera";
            radius = 3;
            onlyForPlayer = TRUE;
            hideOnUse = TRUE;
            priority = 100;
            condition = "true";
            statement = "[cursorObject, player, false] call ace_arsenal_fnc_openBox";
        };

        class Add_Radio: Arsenal_ACE {
            displayName = "<t color='#E6E6E6'><img image='\a3\modules_f_curator\data\portraitradio_ca.paa'/> Add Radio</t>";
            statement = QUOTE(ace_player linkItem 'TFAR_anprc152');
        };
    };

    // CBA Extended Event Handlers - handled by CfgEventHandlers.hpp
            class EventHandlers {
                class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
            };

    };

        // CE Loadout Locker
    class CLASS(CELoadout_Arsenal): OPTRE_Furniture_AmmoRack_BR55 {
            SCOPE_PUBLIC;
            author = AUTHOR;
            displayName = "[505th] CE Loadout and Arsenal & Kit Locker";
            model = "OPTRE_BW_Buildings\Furniture\WeaponsRack_BR\WeaponsRack_AR";
            editorPreview = "\OPTRE_Misc\Image\OPTRE\BW_Buildings\OPTRE_Furniture_AmmoRack_BR55.jpg";

            hiddenSelections[] = {"Texture_Case","Texture_Inside","Texture_Parts"};
            hiddenSelectionsTextures[] = {
                "\BLU\OLI\addons\objects\data\lockers\marine_case_co.paa",
                "\BLU\OLI\addons\objects\data\lockers\marine_case_inside_co.paa",
                "OPTRE_BW_Buildings\Furniture\Data\parts_co.paa"
                };

            editorCategory = QEDCAT(Objects);
            editorSubcategory = QEDSUBCAT(Utility);

        // --- ACE / BIS Arsenal ---
        class UserActions {
            class Arsenal_ACE {
                displayName = QUOTE(<t color='#a02116'><img image=QQPATHTOEF(main,data\ui\ACE_logo_small_ca.paa)/> Custom Arsenal Access</t>);
                position = "camera";
                radius = 3;
                onlyForPlayer = TRUE;
                hideOnUse = TRUE;
                priority = 100;
                condition = "true";
                statement = "[cursorObject, player, false] call ace_arsenal_fnc_openBox";
            };

                class Add_Radio: Arsenal_ACE {
                displayName = "<t color='#E6E6E6'><img image='\a3\modules_f_curator\data\portraitradio_ca.paa'/> Add Radio</t>";
                statement = QUOTE(ace_player linkItem 'TFAR_anprc152');
            };
        };

            // CBA Extended Event Handlers - handled by CfgEventHandlers.hpp
            class EventHandlers {
                class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
            };
    };

       // Pilot Loadout Locker
    class CLASS(AFLoadout_Arsenal): OPTRE_Furniture_AmmoRack_BR55 {
            SCOPE_PUBLIC;
            author = AUTHOR;
            displayName = "[505th] Pilot Loadout and Arsenal & Kit Locker";
            model = "OPTRE_BW_Buildings\Furniture\WeaponsRack_BR\WeaponsRack_AR";
            editorPreview = "\OPTRE_Misc\Image\OPTRE\BW_Buildings\OPTRE_Furniture_AmmoRack_BR55.jpg";

            hiddenSelections[] = {"Texture_Case","Texture_Inside","Texture_Parts"};
            hiddenSelectionsTextures[] = {
                "\BLU\OLI\addons\objects\data\lockers\pilot_case_co.paa",
                "\BLU\OLI\addons\objects\data\lockers\pilot_case_inside_co.paa",
                "OPTRE_BW_Buildings\Furniture\Data\parts_co.paa"
                };

            editorCategory = QEDCAT(Objects);
            editorSubcategory = QEDSUBCAT(Utility);

        // --- ACE Arsenal ---
        class UserActions {
            class Arsenal_ACE {
                displayName = QUOTE(<t color='#a02116'><img image=QQPATHTOEF(main,data\ui\ACE_logo_small_ca.paa)/> Custom Arsenal Access</t>);
                position = "camera";
                radius = 3;
                onlyForPlayer = TRUE;
                hideOnUse = TRUE;
                priority = 100;
                condition = "true";
                statement = "[cursorObject, player, false] call ace_arsenal_fnc_openBox";
            };

            class Add_Radio: Arsenal_ACE {
                displayName = "<t color='#E6E6E6'><img image='\a3\modules_f_curator\data\portraitradio_ca.paa'/> Add Radio</t>";
                statement = QUOTE(ace_player linkItem 'TFAR_anprc152');
            };
        };

            // CBA Extended Event Handlers - handled by CfgEventHandlers.hpp
            class EventHandlers {
                class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
            };
    };
};
