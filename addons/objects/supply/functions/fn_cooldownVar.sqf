// OLI_SUPPLY - name of the cooldown variable one option uses on a console.
//
// Cooldowns are per console AND per option, and shared by everybody: when a
// squad leader takes Platoon Ammo from a console, nobody else can take Platoon
// Ammo from that console until the timer runs out - but Squad Ammo, Medical,
// Explosives and Rockets all stay available, each on their own timer.
//
// The value is a CBA_missionTime stamp, set public by the server so every
// client renders the same countdown.
//
// Arguments: 0: action key <STRING>
// Return: variable name <STRING>

params [["_key", ""]];

if (_key isEqualTo "") exitWith {""};

format ["OLI_Supply_CD_%1", _key]
