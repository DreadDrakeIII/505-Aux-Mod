#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_syncBuiltPos
 *
 * DEDICATED-SERVER HARDENED — runs on every machine (remoteExec target
 * -2 with JIP) after a built object is created. Each client independently
 * corrects the object's visible position to match the server's ghost
 * snapshot.
 *
 * Why this is non-trivial on a dedicated server:
 *
 *   When the server creates an object with createVehicle, the engine
 *   streams the new object to each client as a network entity. The
 *   *position* that arrives at the client is whatever the server's
 *   network tick last captured — which may be the raw createVehicle
 *   position, BEFORE the server's setPosASL re-applies landed.
 *
 *   Result on the client: the object appears at position A. The server
 *   has it at position B (a few cm different). Over time, network sync
 *   may or may not reconcile this — BI's engine does not guarantee
 *   sync for static simulation-disabled objects.
 *
 *   This function is the reconciliation: on each client, forcibly snap
 *   the visible transform to match the authoritative ghost snapshot.
 *
 * Retry strategy:
 *
 *   An early problem: remoteExec runs on the server 0s after creation,
 *   but a client may not have received the object yet — isNull returns
 *   true. The old version silently no-op'd. This version retries at
 *   50ms / 150ms / 400ms / 1s to catch slow-to-arrive clients without
 *   blowing up JIP. Beyond 1s we assume the object will never arrive
 *   on this client and stop trying.
 *
 *   Once the object is present, position/vectors are applied three
 *   times across 0.5s to defeat any late network corrections the
 *   engine tries to push. setPosWorld ensures each re-apply is a
 *   committed, rendered transform.
 *
 * Parameters:
 *   _obj    - the built object (may be objNull briefly on arrival) [OBJECT]
 *   _pos    - ASL position (ghost snapshot)                         [ARRAY]
 *   _vecDir - ghost vectorDir                                        [ARRAY]
 *   _vecUp  - ghost vectorUp                                         [ARRAY]
 */

params ["_obj", "_pos", "_vecDir", "_vecUp"];

// Quick path: if the object is already present, apply immediately.
// The spawned retry loop handles the slow-arrival case separately.
if (!isNull _obj) then {
    _obj setVectorDirAndUp [_vecDir, _vecUp];
    _obj setPosASL _pos;
    _obj setPosWorld getPosWorld _obj;
    _obj setVelocity [0,0,0];
};

// ── Arrival retry + settle loop ───────────────────────────────────────────
[_obj, _pos, _vecDir, _vecUp] spawn {
    params ["_o", "_p", "_vd", "_vu"];

    // Phase 1: wait for the object to arrive on this client if it hasn't
    // already. Retry at 50ms, 150ms, 400ms, 1s. After 1s give up —
    // something is broken if it hasn't arrived by then.
    private _retryAt = [0.05, 0.10, 0.25, 0.60];
    {
        if (!isNull _o) exitWith {};
        sleep _x;
    } forEach _retryAt;

    if (isNull _o) exitWith {
        diag_log "[OLI_engtools] syncBuiltPos: object never arrived on this client, giving up";
    };

    // Phase 2: settle loop. Three re-applies across 0.5s total.
    // Each one forces a broadcast-quality transform commit via setPosWorld.
    _o setVectorDirAndUp [_vd, _vu];
    _o setPosASL _p;
    _o setPosWorld getPosWorld _o;
    _o setVelocity [0,0,0];

    sleep 0.1;
    if (isNull _o) exitWith {};
    _o setVectorDirAndUp [_vd, _vu];
    _o setPosASL _p;
    _o setPosWorld getPosWorld _o;
    _o setVelocity [0,0,0];

    sleep 0.4;  // cumulative 0.5s
    if (isNull _o) exitWith {};
    _o setVectorDirAndUp [_vd, _vu];
    _o setPosASL _p;
    _o setPosWorld getPosWorld _o;
    _o setVelocity [0,0,0];
};
