/*
 * OLI_fnc_canNecroClear
 * Condition: KAT loaded, no dose already active, and (optionally) an
 * established IV/IO line on the selected part (KAT pharma).
 *
 * 0: Patient <OBJECT>, 1: Body part <STRING>
 * Return: BOOL
 */
params ["_patient", "_bodyPart"];

if (!OLI_hasKAT) exitWith {false};
if (_patient getVariable ["OLI_necroClearActive", false]) exitWith {false};

if (missionNamespace getVariable ["OLI_NecroClear_requireIV", true] && {OLI_hasKATPharma}) then {
    private _partIndex = ["head", "body", "leftarm", "rightarm", "leftleg", "rightleg"] find (toLower _bodyPart);
    private _ivArray = _patient getVariable ["kat_pharma_IV", [0, 0, 0, 0, 0, 0]];
    _partIndex != -1 && {(_ivArray select _partIndex) > 0}
} else {
    true
}
