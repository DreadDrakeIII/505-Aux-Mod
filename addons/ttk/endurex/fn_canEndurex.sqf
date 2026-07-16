/*
 * OLI_fnc_canEndurex
 * Condition: alive, conscious, no active dose. Self-use and medic
 * requirements are handled by ACE via the action config (the old mod
 * checked an undefined variable here, which is why Endurex never showed
 * for self-treatment).
 *
 * 0: Patient <OBJECT>, 1: Body part <STRING>
 * Return: BOOL
 */
params ["_patient", "_bodyPart"];

alive _patient
&& {!(_patient getVariable ["OLI_endurexActive", false])}
&& {!(_patient getVariable ["ACE_isUnconscious", false])}
