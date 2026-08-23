/*
 * OLI_fnc_getTTKTime
 * Treatment time resolver for the Tactical Trauma Kit. ACE calls this
 * via the action's treatmentTime entry with _this = [medic, patient,
 * bodyPart, classname] (same contract as ACE's own getStitchTime).
 *
 * Behavior setting:
 *   0 = ACE Stitch Time — delegates to ace getStitchTime (bandaged wound
 *       count on the part x ace woundStitchTime setting), floored at one
 *       wound-equivalent so contusion-only treatments (0 bandaged wounds)
 *       don't resolve to 0s, which ACE treats as "abort".
 *   1 = Custom Slider  — flat OLI_TTK_treatmentTime.
 *
 * Return: Treatment time <NUMBER>
 */
if ((missionNamespace getVariable ["OLI_TTK_timeBehavior", 0]) == 0) then {
    private _oneWound = (missionNamespace getVariable ["ace_medical_treatment_woundStitchTime", 4]) max 1;
    (_this call ace_medical_treatment_fnc_getStitchTime) max _oneWound
} else {
    missionNamespace getVariable ["OLI_TTK_treatmentTime", 3]
}
