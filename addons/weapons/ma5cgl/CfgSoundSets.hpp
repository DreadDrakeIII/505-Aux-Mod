class CfgSoundSets {

    class CLASS(SoundSet_WeaponShot_Base);

    class CLASS(SoundSet_MA5CGLShot): CLASS(SoundSet_WeaponShot_Base) {
        soundShaders[] = {QCLASS(SoundShader_MA5CGLShot)};
    };
};
