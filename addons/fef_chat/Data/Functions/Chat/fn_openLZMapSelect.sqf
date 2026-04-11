/*
 * Opens map for LZ position selection.
 * Player clicks to place marker, then sends LZ request.
 */
params [["_type", "pickup"]];

missionNamespace setVariable ["FEF_LZ_PendingType", _type];
missionNamespace setVariable ["FEF_LZ_Selecting", true];

openMap [true, false];

private _hintText = switch (_type) do {
    case "pickup":  { "Click map to mark <t color='#00AAFF'>PICKUP</t> position" };
    case "dropoff": { "Click map to mark <t color='#00FF88'>DROP-OFF</t> position" };
    case "casevac": { "Click map to mark <t color='#FF3333'>CASEVAC</t> position" };
    case "extract": { "Click map to mark <t color='#00AAFF'>EXTRACTION</t> position" };
    case "hot":     { "Click map to mark <t color='#FF6600'>HOT LZ</t> position" };
    case "clear":   { "Click map to mark <t color='#00FF88'>LZ CLEAR</t> position" };
    default         { "Click map to mark LZ position" };
};

hint parseText format [
    "<t size='1.1' color='#FFD700'>— LZ MARKER —</t><br/><br/>%1<br/><br/><t size='0.8' color='#AAAAAA'>Press ESC to cancel</t>",
    _hintText
];

onMapSingleClick {
    params ["_pos"];

    if !(missionNamespace getVariable ["FEF_LZ_Selecting", false]) exitWith { false };

    private _type = missionNamespace getVariable ["FEF_LZ_PendingType", "pickup"];

    missionNamespace setVariable ["FEF_LZ_Selecting", false];
    missionNamespace setVariable ["FEF_LZ_PendingType", ""];

    onMapSingleClick "";
    openMap [false, false];
    hint "";

    [_type, player, _pos] call FEF_fnc_sendLZRequest;

    true
};

// Watch for ESC / map close
[{
    params ["_args", "_handle"];

    if !(missionNamespace getVariable ["FEF_LZ_Selecting", false]) exitWith {
        [_handle] call CBA_fnc_removePerFrameHandler;
    };

    if !(visibleMap) then {
        missionNamespace setVariable ["FEF_LZ_Selecting", false];
        missionNamespace setVariable ["FEF_LZ_PendingType", ""];
        onMapSingleClick "";
        hint "";
        [_handle] call CBA_fnc_removePerFrameHandler;
    };

}, [], 0.1] call CBA_fnc_addPerFrameHandler;
