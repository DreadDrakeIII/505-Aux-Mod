/*
 * Author: RevGamer
 * Creates a temporary map ping at casualty location
 *
 * Arguments:
 * 0: Position <ARRAY>
 * 1: Player name <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * [getPosATL player, "John"] call CWR_fnc_createCasualtyPing;
 */

params ["_position", "_playerName"];

// Create unique marker name
private _markerName = format ["CWR_Casualty_%1_%2", _playerName, time];

// Create marker
private _marker = createMarkerLocal [_markerName, _position];
_marker setMarkerTypeLocal "hd_destroy";
_marker setMarkerColorLocal "ColorRed";
_marker setMarkerTextLocal format ["CASUALTY - %1", _playerName];
_marker setMarkerAlphaLocal 1;

// Play notification sound
playSound "addItemOK";

// Delete marker after 30 seconds
[{
    params ["_markerName"];
    deleteMarkerLocal _markerName;
}, [_markerName], 30] call CBA_fnc_waitAndExecute;
