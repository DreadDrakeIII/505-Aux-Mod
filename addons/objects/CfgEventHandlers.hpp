class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_preInit));
    };
};

class Extended_InitPost_EventHandlers {
    class CLASS(Marine_Loadout) {
        class GVAR(Init) {
            clientInit = QUOTE(_this call FUNC(Init));
        };
    };

    class CLASS(CE_Locker) {
        class GVAR(Init) {
            clientInit = QUOTE(_this call FUNC(Init));
        };
    };
};
