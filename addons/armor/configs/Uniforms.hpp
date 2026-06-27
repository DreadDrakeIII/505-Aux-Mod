class CLASS(Uniform_CE): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Marine Uniform";
SCOPE_HIDDEN;
	class ItemInfo: ItemInfo{
		uniformClass = QCLASS(Marine_CE_Rifleman);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_Rolled): CLASS(Uniform_CE_Rolled_Base) {
author = "505th Aux Team";
displayName = "[505th] Marine Uniform (Rolled)";
SCOPE_HIDDEN;
	class ItemInfo: ItemInfo
	{
		uniformClass = QCLASS(Marine_CE_Rifleman_Rolled);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_Corpsman): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Corpsman Uniform";
SCOPE_HIDDEN;
	class ItemInfo: ItemInfo
	{
		uniformClass = QCLASS(Marine_CE_Corpsman);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_Corpsman_Rolled): CLASS(Uniform_CE_Rolled_Base) {
author = "505th Aux Team";
displayName = "[505th] Corpsman Uniform (Rolled)";
SCOPE_HIDDEN;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Corpsman_CE_Rifleman_Rolled);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_SL): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Squad Lead Uniform";
SCOPE_HIDDEN;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_CE_SquadLead);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_SL_Rolled): CLASS(Uniform_CE_Rolled_Base) {
author = "505th Aux Team";
displayName = "[505th] Squad Lead Uniform (Rolled) ";
SCOPE_HIDDEN;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_CE_SquadLead_Rolled);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_PL): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Platoon Lead Uniform";
SCOPE_HIDDEN;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_CE_PlatoonLead);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_PL_Rolled): CLASS(Uniform_CE_Rolled_Base) {
author = "505th Aux Team";
displayName = "[505th] Platoon Lead Uniform (Rolled) ";
SCOPE_HIDDEN;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_CE_PlatoonLead_Rolled);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_FR): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Force Recon Uniform";
SCOPE_HIDDEN;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_CE_FR);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_FR_Rolled): CLASS(Uniform_CE_Rolled_Base) {
author = "505th Aux Team";
displayName = "[505th] Force Recon Uniform (Rolled) ";
SCOPE_HIDDEN;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_CE_FR_Rolled);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
////////////////CUSTOM_UNIFORMS////////////////
class CLASS(Uniform_CE_Adamant): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Custom Uniform (Adamant)";
SCOPE_HIDDEN;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_CE_Adamant);
        uniformType = "Neopren";
		containerClass = "Supply500";
		mass = 40;
	};
};
class CLASS(Uniform_CE_Crawford): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Custom Uniform (Crawford)";
SCOPE_HIDDEN;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_CE_Crawford);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_Crawford_Rolled): CLASS(Uniform_CE_Rolled_Base) {
author = "505th Aux Team";
displayName = "[505th] Custom Uniform (Crawford,Rolled)";
SCOPE_HIDDEN;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_CE_Crawford_Rolled);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_Oliver): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Custom Uniform (Oliver)";
uniformType = "Neopren";
SCOPE_HIDDEN;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_CE_Oliver);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_Doc): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Custom Uniform (Doc)";
uniformType = "Neopren";
SCOPE_HIDDEN;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_CE_Doc);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_Kain): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Custom Uniform (Kain)";
uniformType = "Neopren";
SCOPE_HIDDEN;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_CE_Kain);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
/////////////////////Pilot Uniform/////////////////////
class CLASS(Uniform_Pilot): CLASS(Uniform_Pilot_Base) {
   SCOPE_PUBLIC;
    displayName = "[505th] Pilot Uniform";
};
///////////////////Black Ops Uniform///////////////////
class CLASS(Uniform_BlackOps): CLASS(Uniform_BlackOps_Base) {
   SCOPE_PRIVATE;
    displayName = "[505th] Black Ops Uniform";
};
//////////////////CBUU Uniforms//////////////////
class TCP_equipmentTypes;

class CLASS(CBUU_Woodland_1): CLASS(CBUU_Woodland_1_Base) {
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    author = AUTHOR;
    displayName = "[505th] CBUU Uniform (Woodland 1)";

    class TCP_equipmentTypes: TCP_equipmentTypes {
        baseEquipment = QCLASS(CBUU_Woodland_1);
    };

    class ItemInfo: ItemInfo {
        uniformClass = QCLASS(Marine_TCP_Woodland_1);
        containerClass = "Supply150";
        mass = 10;
    };
};

class CLASS(CBUU_Woodland_2): CLASS(CBUU_Woodland_2_Base) {
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    author = AUTHOR;
    displayName = "[505th] CBUU Uniform (Woodland 2)";

    class TCP_equipmentTypes: TCP_equipmentTypes {
        baseEquipment = QCLASS(CBUU_Woodland_2);
    };

    class ItemInfo: ItemInfo {
        uniformClass = QCLASS(Marine_TCP_Woodland_2);
        containerClass = "Supply150";
        mass = 10;
    };
};

class CLASS(CBUU_Urban_1): CLASS(CBUU_Urban_1_Base) {
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    author = AUTHOR;
    displayName = "[505th] CBUU Uniform (Urban 1)";

    class TCP_equipmentTypes: TCP_equipmentTypes {
        baseEquipment = QCLASS(CBUU_Urban_1);
    };

    class ItemInfo: ItemInfo {
        uniformClass = QCLASS(Marine_TCP_Black_1);
        containerClass = "Supply150";
        mass = 10;
    };
};
