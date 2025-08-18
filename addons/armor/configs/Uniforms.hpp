class CLASS(Uniform_CE): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Marine Uniform";
scope = 2;
scopeCurator = 2;
scopeArsenal = 2;
	class ItemInfo: UniformItem{
		uniformClass = QCLASS(Marine_Rifleman_CE);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_Rolled): CLASS(Uniform_CE_Rolled_Base) {
author = "505th Aux Team";
displayName = "[505th] Marine Uniform (Rolled)";
scope = 2;
scopeCurator = 2;
scopeArsenal = 2;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_Rifleman_Rolled_CE);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_Corpsman): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Corpsman Uniform";
scope = 2;
scopeCurator = 2;
scopeArsenal = 2;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Corpsman_Rifleman_CE);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_Corpsman_Rolled): CLASS(Uniform_CE_Rolled_Base) {
author = "505th Aux Team";
displayName = "[505th] Corpsman Uniform (Rolled)";
scope = 2;
scopeCurator = 2;
scopeArsenal = 2;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Corpsman_Rifleman_CE_Rolled);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_SL): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Squad Lead Uniform";
scope = 2;
scopeCurator = 2;
scopeArsenal = 2;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_SquadLead_CE);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_SL_Rolled): CLASS(Uniform_CE_Rolled_Base) {
author = "505th Aux Team";
displayName = "[505th] Squad Lead Uniform (Rolled) ";
scope = 2;
scopeCurator = 2;
scopeArsenal = 2;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_SquadLead_CE_Rolled);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_PL): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Platoon Lead Uniform";
scope = 2;
scopeCurator = 2;
scopeArsenal = 2;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_PlatoonLead_CE);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_PL_Rolled): CLASS(Uniform_CE_Rolled_Base) {
author = "505th Aux Team";
displayName = "[505th] Platoon Lead Uniform (Rolled) ";
scope = 2;
scopeCurator = 2;
scopeArsenal = 2;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_PlatoonLead_CE_Rolled);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_FR_CE): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Force Recon Uniform";
scope = 2;
scopeCurator = 2;
scopeArsenal = 2;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_FR_CE);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Uniform_CE_FR_Rolled): CLASS(Uniform_CE_Rolled_Base) {
author = "505th Aux Team";
displayName = "[505th] Force Recon Uniform (Rolled) ";
scope = 2;
scopeCurator = 2;
scopeArsenal = 2;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_CE_FR_Rolled);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
////////////////CUSTOM_UNIFORMS////////////////
class CLASS(Adamant_Uniform_CE): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Custom Uniform (Adamant)";
scope = 2;
scopeCurator = 2;
scopeArsenal = 2;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_Adamant_CE);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Crawford_Uniform_CE): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Custom Uniform (Crawford)";
scope = 2;
scopeCurator = 2;
scopeArsenal = 2;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_Crawford_CE);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Crawford_Uniform_Rolled_CE): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Custom Uniform (Crawford,Rolled)";
scope = 2;
scopeCurator = 2;
scopeArsenal = 2;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_Crawford_Rolled_CE);
        uniformType = "Neopren";
		containerClass = "Supply150";
		mass = 40;
	};
};
class CLASS(Oliver_Uniform_CE): CLASS(Uniform_CE_Base) {
author = "505th Aux Team";
displayName = "[505th] Custom Uniform (Oliver)";
uniformType = "Neopren";
scope = 2;
scopeCurator = 2;
scopeArsenal = 2;
	class ItemInfo: UniformItem
	{
		uniformClass = QCLASS(Marine_Oliver_CE);
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
