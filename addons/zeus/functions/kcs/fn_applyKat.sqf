// OLI_KCS - SERVER (patient local): apply one KAT complication.
// Variable names / values verified against KAT 3.1.3 sources:
//   kat_airway:    occluded (bool), obstruction (bool)
//   kat_breathing: pneumothorax (0..4), tensionpneumothorax (bool),
//                  hemopneumothorax (bool), deepPenetratingInjury (bool),
//                  activeChestSeal (bool)
//
// Arguments: 0: patient <OBJECT>,
//            1: type: "occlusion", "obstruction", "pneumothorax",
//               "tension", "hemothorax", "openchest" <STRING>
//            2: (pneumothorax only) stage 1-3 <NUMBER>

params ["_p", "_type", ["_stage", 1]];

if (!OLI_KCS_KatLoaded) exitWith {};

switch (_type) do {

    // blood/vomit in the airway -> suction (Accuvac) drill
    case "occlusion": {
        _p setVariable ["kat_airway_occluded", true, true];
    };

    // airway obstruction -> head tilt / airway adjunct drill
    case "obstruction": {
        _p setVariable ["kat_airway_obstruction", true, true];
    };

    // staged pneumothorax that deteriorates over time, like a natural
    // KAT chest hit (kat_breathing_fnc_woundsHandlerPulmoHit pattern)
    case "pneumothorax": {
        [_p, 0.2] call ace_medical_status_fnc_adjustPainLevel;
        _p setVariable ["kat_breathing_pneumothorax", _stage, true];
        _p setVariable ["kat_breathing_deepPenetratingInjury", true, true];
        _p setVariable ["kat_breathing_activeChestSeal", false, true];
        if (!isNil "kat_breathing_fnc_handlePneumothoraxDeterioration") then {
            [_p, 15] call kat_breathing_fnc_handlePneumothoraxDeterioration;
        };
    };

    // tension pneumothorax -> needle decompression drill
    case "tension": {
        [_p, 0.7] call ace_medical_status_fnc_adjustPainLevel;
        _p setVariable ["kat_breathing_tensionpneumothorax", true, true];
        _p setVariable ["kat_breathing_pneumothorax", 4, true];
        _p setVariable ["kat_breathing_deepPenetratingInjury", true, true];
        _p setVariable ["kat_breathing_activeChestSeal", false, true];
    };

    // hemopneumothorax -> chest tube / surgery drill
    case "hemothorax": {
        [_p, 0.7] call ace_medical_status_fnc_adjustPainLevel;
        _p setVariable ["kat_breathing_hemopneumothorax", true, true];
        _p setVariable ["kat_breathing_pneumothorax", 4, true];
        _p setVariable ["kat_breathing_deepPenetratingInjury", true, true];
        _p setVariable ["kat_breathing_activeChestSeal", false, true];
        if (!isNil "kat_circulation_fnc_updateInternalBleeding") then {
            [_p] call kat_circulation_fnc_updateInternalBleeding;
        };
    };

    // open chest wound only -> chest seal drill, no pneumothorax yet
    case "openchest": {
        _p setVariable ["kat_breathing_deepPenetratingInjury", true, true];
        _p setVariable ["kat_breathing_activeChestSeal", false, true];
    };
};
