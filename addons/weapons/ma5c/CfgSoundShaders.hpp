class CfgSoundShaders {
    // Define the base class
    class CLASS(SoundShader_WeaponShot_Base) {
        samples[] = {};
        volume = 1;
        range = 2000;
        rangeCurve[] = {
            {0, 1},
            {50, 0.7},
            {300, 0.3},
            {2000, 0}
        };
    };

    class CLASS(SoundShader_MA5CShot): CLASS(SoundShader_WeaponShot_Base) {
        samples[] = {
            {QPATHTOF(ma5c\data\audio\MA5C-01.ogg), "db5", 1, 2000},
            {QPATHTOF(ma5c\data\audio\MA5C-02.ogg), "db5", 1, 2000},
            {QPATHTOF(ma5c\data\audio\MA5C-03.ogg), "db5", 1, 2000},
            {QPATHTOF(ma5c\data\audio\MA5C-04.ogg), "db5", 1, 2000},
            {QPATHTOF(ma5c\data\audio\MA5C-05.ogg), "db5", 1, 2000},
            {QPATHTOF(ma5c\data\audio\MA5C-06.ogg), "db5", 1, 2000},
            {QPATHTOF(ma5c\data\audio\MA5C-07.ogg), "db5", 1, 2000},
            {QPATHTOF(ma5c\data\audio\MA5C-08.ogg), "db5", 1, 2000},
            {QPATHTOF(ma5c\data\audio\MA5C-09.ogg), "db5", 1, 2000},
            {QPATHTOF(ma5c\data\audio\MA5C-10.ogg), "db5", 1, 2000},
            {QPATHTOF(ma5c\data\audio\MA5C-11.ogg), "db5", 1, 2000},
            {QPATHTOF(ma5c\data\audio\MA5C-12.ogg), "db5", 1, 2000},
            {QPATHTOF(ma5c\data\audio\MA5C-13.ogg), "db5", 1, 2000}
        };
    };
};
