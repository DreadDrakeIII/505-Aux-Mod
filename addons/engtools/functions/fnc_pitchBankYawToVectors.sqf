#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_pitchBankYawToVectors
 * Converts pitch/bank/yaw angles to vectorDir and vectorUp arrays.
 *
 * Parameters:
 *   _pitch - Pitch angle in degrees
 *   _bank  - Bank angle in degrees
 *   _yaw   - Yaw angle in degrees
 *
 * Returns: [vectorDir, vectorUp]
 */

params ["_pitch", "_bank", "_yaw"];

private _cp = cos _pitch; private _sp = sin _pitch;
private _cb = cos _bank;  private _sb = sin _bank;
private _cy = cos _yaw;   private _sy = sin _yaw;

private _vecDir = [
    _sy * _cp,
    _cy * _cp,
    -_sp
];
private _vecUp = [
    _sb * _cy + _cb * _sp * _sy,
    -_sb * _sy + _cb * _sp * _cy,
    _cb * _cp
];

[vectorNormalized _vecDir, vectorNormalized _vecUp]
