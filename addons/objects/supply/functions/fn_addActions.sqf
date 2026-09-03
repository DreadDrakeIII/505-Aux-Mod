// OLI_SUPPLY - attach the console's scroll-wheel actions to an object.
//
// One action per ENABLED entry in OLI_Supply_Actions: an option switched off
// in the addon options gets no action at all, so a mission running ammo and
// medical only shows four entries rather than six greyed-out ones.
//
// The placeable console class gets these automatically. For any other prop use
// OLI_Supply_fnc_registerConsole on the server instead of calling this
// directly - the server has to know the object is a console before it will
// honour requests aimed at it.
//
// Arguments: 0: object <OBJECT>
// Return: action IDs <ARRAY>

params [["_console", objNull]];

if (!hasInterface) exitWith {[]};
if (isNull _console) exitWith {[]};
if !(isNil {_console getVariable "OLI_Supply_ActionIDs"}) exitWith {
    _console getVariable ["OLI_Supply_ActionIDs", []]
};

if (isNil "OLI_Supply_LocalConsoles") then {OLI_Supply_LocalConsoles = []};

private _radius = missionNamespace getVariable ["OLI_Supply_ActionRadius", 4];
private _ids = [];
private _map = [];      // [[action key, action id], ...] - only the enabled ones
private _shown = [];    // last rendered whole second, parallel to _map

{
    _x params ["_key", "", "", "", "", "", "", "", "_enabledVar"];

    // Option switched off in the addon options: no action, not even greyed out.
    if (missionNamespace getVariable [_enabledVar, true]) then {
        private _title  = [_key, false, 0] call OLI_Supply_fnc_actionTitle;
        private _window = [_key, false, 0, 1.6] call OLI_Supply_fnc_actionTitle;

        private _id = _console addAction [
            _title,                                                  // title (HTML)
            {
                params ["_target", "_caller", "_actionId", "_arguments"];
                [_target, _caller, _arguments] call OLI_Supply_fnc_requestCrate;
            },
            _key,                                                    // arguments
            1.5 - (_forEachIndex * 0.01),                            // priority (keeps table order)
            true,                                                    // showWindow - on-screen prompt, no scrolling needed
            true,                                                    // hideOnUse
            "",                                                      // shortcut
            "alive _this && {isNull objectParent _this}",            // condition (_this = caller)
            _radius,                                                 // radius (m)
            false,                                                   // unconscious
            "",                                                      // selection
            ""                                                       // memoryPoint
        ];

        // Third element is the on-screen "default action" text - the prompt you
        // get just by looking at the console. addAction has no parameter for it,
        // setUserActionText does.
        _console setUserActionText [_id, _title, _window];

        _ids pushBack _id;
        _map pushBack [_key, _id];
        _shown pushBack -1;
    };
} forEach OLI_Supply_Actions;

_console setVariable ["OLI_Supply_ActionIDs", _ids];
_console setVariable ["OLI_Supply_ActionMap", _map];
_console setVariable ["OLI_Supply_ShownSecs", _shown];
OLI_Supply_LocalConsoles pushBackUnique _console;

_ids
