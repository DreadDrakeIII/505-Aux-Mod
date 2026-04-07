#include "script_component.hpp"
#include "FEF_Sounds.hpp"
#include "ui\defines.hpp"
#include "ui\FEF_ChatDisplay.hpp"

class CfgPatches {
    class FEFChat {
        author = "RevGamer / OpenAI";
        weapons[] = {};
        units[] = {};
        requiredVersion = 2.14;
        requiredAddons[] = {
            "cba_events",
            "cba_settings",
            "cba_keybinding"
        };
    };
};

class CfgFunctions {
    class FEF {
        class Settings {
            file = "BLU\OLI\addons\fef_chat\Data\Functions\Settings";
            class configureAddonKeybinds {};
            class configureAddonOptions {};
        };

        class Chat {
            file = "BLU\OLI\addons\fef_chat\Data\Functions\Chat";
            class configureMenus {};
            class executeMenuSelection {};
            class openChatWheel {};
            class openMenuById {};
            class resolveText {};
            class sendFriendlyDownAlert {};
            class sendGroupMessage {};
            class sendLocalMessage {};
            class sendLocalSideMessage {};
            class createFriendlyDownMarkerLocal {};
            class sendReinsertRequest {};
            class createReinsertMarkerLocal {};
            class createCasualtyPingLocal {};
        };

        class Sounds {
            file = "BLU\OLI\addons\fef_chat\Data\Functions\Sounds";
            class resolveVoiceLine {};
            class playLocalVoiceLine {};
        };

        class Utils {
            file = "BLU\OLI\addons\fef_chat\Data\Functions\Utils";
            class devLog {};
            class getDirFromBearing {};
            class getNearbyPlayers {};
            class isPlayer {};
            class stringReplace {};
        };

        class EventHandlers {
            file = "BLU\OLI\addons\fef_chat\Data\Functions\EventHandlers";
            class attachGrenadeEH {};
            class throwGrenadeEH {};
            class throwGrenadeEHACE {};
            class throwGrenadeMain {};
            class unconsciousEH {};
        };

        class UI {
            file = "BLU\OLI\addons\fef_chat\Data\Functions\UI";
            class openUI {};
            class closeUI {};
            class renderMenu {};
            class onButtonClick {};
            class onMouseWheel {};
            class onKeyDown {};
        };
    };
};

#define QUOTE(CODE) #CODE

class Extended_PreInit_EventHandlers {
    class FEF_ConfigureKeybinds {
        init = QUOTE(call FEF_fnc_configureAddonKeybinds;);
    };
    class FEF_ConfigureOptions {
        init = QUOTE(call FEF_fnc_configureAddonOptions;);
    };
    class FEF_ConfigureMenus {
        init = QUOTE(call FEF_fnc_configureMenus;);
    };
};

class Extended_PostInit_EventHandlers {
    class FEF_ThrowGrenadeEH {
        clientInit = QUOTE(if (isClass (configFile >> 'CfgPatches' >> 'ace_common')) then { call FEF_fnc_throwGrenadeEHACE; } else { call FEF_fnc_throwGrenadeEH; };);
    };
    class FEF_UnconsciousEH {
        clientInit = QUOTE(call FEF_fnc_unconsciousEH;);
    };
};
