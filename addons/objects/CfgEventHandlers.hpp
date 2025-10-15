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
        class GVAR(LockerInit) {
            clientInit = QUOTE(_this call FUNC(LockerInit));
        };
    };
};
