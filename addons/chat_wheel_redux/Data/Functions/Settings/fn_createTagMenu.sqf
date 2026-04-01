/*
 * Author: DartRuffian
 * Creates a diary tab showing all available tags and what they are replaced with.
 */

player createDiarySubject ["CWR_TagsSubject", "Chat Wheel Tags"];

private _tags = [["[distance] - Previously [contact]",
    "[distance] will prompt the user to open a submenu to select a distance.",
    ["Contact! Infantry [distance]!", "Contact! Infantry Close!"]
], [
    "[weapon]",
    "[weapon] will be replaced with the name of the weapon the player is currently holding.",
    ["I'm holding a [weapon]!", "I'm holding a MX!"]
], [
    "[launcher]",
    "[launcher] is not intended to be used with custom messages, but is compatible. [launcher] will open the launcher sub-menu, with rocket launcher related options. Such as 'Permission to fire?', 'Clear backblast!', etc.",
    ["[launcher]", "Permission to fire?"]
], [
    "[status]",
    '[status] will prompt the user to open a submenu and select a status of Green, Yellow, Orange, Red, or Black. The selected option then replaced "[status]".',
    ["Status [status]!", "Status Red!"]
], [
    "[bearing]",
    "[bearing] is replaced with the compass bearing the player is currently facing.",
    ["Facing [bearing].", "Facing 138."]
], [
    "[direction]",
    "[direction] is replaced with the direction the player is facing.",
    ["Facing [direction].", "Facing Southeast."]
], [
    "[vl-ABC]",
    '[vl-ABC] is used to play voicelines for specific actions. The "ABC" part of the tag is the class defined in "CWR_VoiceLines", so in this case, a random file from configFile >> "CWR_VoiceLines" >> "ABC" >> "voiceLines" will be played. If no voicelines are set up, the tag is still removed from the message but no sound effect is played.',
    ["[vl-NeedMedic]I need a medic!", "I need a medic!"]
]];

reverse _tags;

private _formatTitle = {
    params ["_str"];
    _str = "<font color='#99cccc' size='20' face='RobotoCondensedBold'>" + _str + "</font>";
    _str;
};

private _formatSubtitle = {
    params ["_str"];
    _str = "<font color='#bdcc9c' size='15' face='RobotoCondensedBold'>" + _str + "</font>";
    _str;
};

private _formatCode = {
    params ["_str"];
    _str = '<font face="etelkaMonospacePro" size="10">"' + _str + '"</font>';
    _str;
};

// FIX: safe default, was undefined causing runtime error
private _useNewLine = missionNamespace getVariable ["CWR_TagMenu_UseNewLine", false];
_separator = if (_useNewLine) then [{ "<br />becomes<br />" }, { " <font size='11'>→</font>   " }];

{
    private _raw = _x#2#0 call _formatCode;
    private _formatted = _x#2#1 call _formatCode;
    player createDiaryRecord ["CWR_TagsSubject", ["Examples", ((_x#0 call _formatSubtitle) + "<br />" + ([_raw, _formatted] joinString _separator))], taskNull, "NONE", false];
} forEach _tags;
player createDiaryRecord ["CWR_TagsSubject", ["Examples", "Tag Examples" call _formatTitle], taskNull, "NONE", false];

{
    player createDiaryRecord ["CWR_TagsSubject", ["Message Tags", ((_x#0 call _formatSubtitle) + "<br />" + _x#1)], taskNull, "NONE", false];
} forEach _tags;
player createDiaryRecord ["CWR_TagsSubject", ["Message Tags", "Message Tags" call _formatTitle], taskNull, "NONE", false];
