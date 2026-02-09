class CfgWeapons {
    class ToolKit; // External reference to vanilla toolkit

    class CLASS(Combat_Engineer_Toolkit): ToolKit {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "Combat Engineer Toolkit";
        descriptionShort = "505th Combat Engineer Toolkit - Required for fortification construction and field repairs";



        // Makes it appear in Arsenal
        class ItemInfo {
            mass = 80; // Same as vanilla toolkit
            type = 620; // Item type
        };
    };
};
