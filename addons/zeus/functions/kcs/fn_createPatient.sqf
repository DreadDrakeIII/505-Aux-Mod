// OLI_KCS - SERVER: spawn one bare patient, medically prepped but unwounded.
// The caller's _onReady code runs ~1 s later (after ACE/KAT unit init).
//
// Arguments: 0: position ATL <ARRAY>, 1: on-ready code, receives [patient] <CODE>
// Returns: patient <OBJECT>

params ["_pos", "_onReady"];

if (isNil "OLI_KCS_Group" || {isNull OLI_KCS_Group}) then {
    OLI_KCS_Group = createGroup [civilian, false];
};
if (isNil "OLI_KCS_PatientCounter") then { OLI_KCS_PatientCounter = 0; };
OLI_KCS_PatientCounter = OLI_KCS_PatientCounter + 1;

private _p = OLI_KCS_Group createUnit [OLI_KCS_UnitClass, _pos, [], 0, "CAN_COLLIDE"];
_p setPosATL _pos;
_p setDir random 360;
_p setName format ["Casualty %1", OLI_KCS_PatientCounter];
_p setVariable ["OLI_KCS_IsPatient", true, true];

{_p disableAI _x} forEach ["MOVE", "PATH", "AUTOTARGET", "TARGET", "FSM"];
_p setBehaviour "CARELESS";
_p setCaptive true;              // nobody shoots the training dummy

// civilian clothes, nothing else. BIS_enableRandomization is the official
// switch that stops the (scheduled) unit randomisation from re-adding gear.
_p setVariable ["BIS_enableRandomization", false];
removeAllWeapons _p;
removeAllItems _p;
removeAllAssignedItems _p;
removeUniform _p;
removeVest _p;
removeBackpack _p;
removeHeadgear _p;
removeGoggles _p;
if (OLI_KCS_UniformPool isNotEqualTo []) then {
    _p forceAddUniform (selectRandom OLI_KCS_UniformPool);
};

// --- medical prep ---
// let this AI use the unconsciousness state machine even if the server
// setting only allows it for players (prevents insta-death on spawn)
_p setVariable ["ace_medical_statemachine_AIUnconsciousness", true, true];
// make sure the vitals loop runs on this AI
_p setVariable ["ace_medical_medicalActivity", true];
// death protection during the spawn/wounding window
_p setVariable ["ace_medical_deathBlocked", true, true];
if (missionNamespace getVariable ["OLI_KCS_AllowDeath", true]) then {
    [{
        params ["_p"];
        if (isNull _p || {!alive _p}) exitWith {};
        _p setVariable ["ace_medical_deathBlocked", false, true];
    }, [_p], missionNamespace getVariable ["OLI_KCS_DeathGrace", 25]] call CBA_fnc_waitAndExecute;
};
[_p, true, missionNamespace getVariable ["OLI_KCS_MinUnconTime", 20]] call ace_medical_fnc_setUnconscious;

// Zeus can see/manipulate patients
{ _x addCuratorEditableObjects [[_p], false]; } forEach allCurators;

// wound after ACE has fully initialised the unit
[{
    params ["_p", "_onReady"];
    if (isNull _p || {!alive _p}) exitWith {};
    [_p] call _onReady;
}, [_p, _onReady], 1] call CBA_fnc_waitAndExecute;

_p
