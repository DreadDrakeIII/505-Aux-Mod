/*
 * Authors: DartRuffian
 * Returns an array of players near a given position.
 *
 * Arguments:
 * 0: position <Array PositionATL>
 * 1: radius <Number>
 * 2: includeRemoteControlled <Boolean> (Optional, default true)
 *
 * Return Value:
 * Array of players
 */

params ["_position", "_radius", ["_includeRemoteControlled", true]];

private _nearbyUnits = _position nearEntities ["CAManBase", _radius];
_nearbyUnits = _nearbyUnits select { [_x, _includeRemoteControlled] call CWR_fnc_isPlayer; };

_nearbyUnits;
