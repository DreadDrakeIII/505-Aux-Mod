// ============================================================================
// Objects Event Handlers
// Author: 505th Dev Team
// ============================================================================

// ---------------------------------------------------------------
// PreStart
// ---------------------------------------------------------------
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
    // CE Locker
    class CLASS(CELoadout_Arsenal) {
        class GVAR(InitCE) {
            init = QUOTE(_this call FUNC(InitCE));
        };
    };

    // FR Locker
    class CLASS(FRLoadout_Arsenal) {
        class GVAR(InitFR) {
            init = QUOTE(_this call FUNC(InitFR));
        };
    };

    // AF Locker
    class CLASS(AFLoadout_Arsenal) {
        class GVAR(InitAF) {
            init = QUOTE(_this call FUNC(InitAF));
        };
    };

    // HM Locker
    class CLASS(HMLoadout_Arsenal) {
        class GVAR(InitHM) {
            init = QUOTE(_this call FUNC(InitHM));
        };
    };
};
