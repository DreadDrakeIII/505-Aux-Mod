class CfgMusic {
    /* Macro Explanation
    * First value is the class name without prefix
        - This gets other text added to it, SW_AhsokaDelightful becomes BLU_OLI_Music_SW_AhsokaDelightful
    * Second value is the name of the sound that gets displayed
        - Should be prefixed with what game/movie/etc. the song is from
    * Third value is the length of the track
    * Fourth value is what category the song should go in
        - This gets formatted as BLU_OLI_MusicCat_<value> so StarWars becomes BLU_OLI_MusicCat_StarWars
    */
    // Halo
    MUSIC(Halo_DeliverHope_Piano,"[Halo] Deliver Hope (Piano)",127,Halo);
    MUSIC(Halo_DeliverHope,"[Halo] Deliver Hope",120,Halo);
    MUSIC(Halo_FinishTheFight,"[Halo] Finish the Fight",147,Halo);
    MUSIC(Halo_LongNightOfSolace,"[Halo] Long Night Of Solace",706,Halo);
    MUSIC(Halo_NeverForget,"[Halo] Never Forget",187,Halo);

    // Video Games

    // Songs
    MUSIC(BURN,"Burn",202,Songs);
    MUSIC(Norman,"Norman",171,Songs);

    // Soundtracks
    MUSIC(TheFinalBattle,"The Final Battle",207,Soundtracks);
    MUSIC(BarbarianHorde,"Barbarian Horde",633,Soundtracks);
    MUSIC(HtCxHaP,"Hoist The Colours x He's a Pirate",295,Soundtracks);
    MUSIC(BuryingTheDead,"Burying The Dead",129,Soundtracks);
    MUSIC(The_Battle,"Gladiator - The Battle",602,Spimdtracks);
    MUSIC(UnravelEPIC,"Unravel Epic",260,Soundtracks);
    MUSIC(VictoryandDeath,"Victory and Death",62,Soundtracks);
    MUSIC(TENET_Trucks_in_Place,"TENET - Trucks in Place",332,Soundtracks);
    MUSIC(TENET_Freeport,"TENET - Freeport",219,Soundtracks);
    MUSIC(TENET_SATOR,"TENET - SATOR [Dread]",171,Soundtracks);
};