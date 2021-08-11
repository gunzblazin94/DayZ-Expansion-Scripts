#define _ARMA_

class CfgPatches
{
	class BuilderItems_StaticItems_Core
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Structures_Signs"};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class bldr_Mil_AircraftShelter_Grass_R: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\military\Airfield\Mil_AircraftShelter_Grass_R.p3d";
	};
	class bldr_Mil_AircraftShelter_Grass_L: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\military\Airfield\Mil_AircraftShelter_Grass_L.p3d";
	};
	class bldr_Canteen: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\drinks\Canteen.p3d";
	};
	class bldr_WaterBottle: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\drinks\WaterBottle.p3d";
	};
	class bldr_Vodka: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\drinks\VodkaBottles.p3d";
	};
	class bldr_SodaCan_Pipsi: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\drinks\SodaCan.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\gear\drinks\Data\SodaCan_pipsi_co.paa"};
	};
	class bldr_SodaCan_Cola: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\drinks\SodaCan.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\gear\drinks\Data\SodaCan_cola_co.paa"};
	};
	class bldr_SodaCan_Spite: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\drinks\SodaCan.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\gear\drinks\Data\SodaCan_spite_co.paa"};
	};
	class bldr_SodaCan_Kvass: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\drinks\SodaCan.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\gear\drinks\Data\SodaCan_rasputin_kvass_co.paa"};
	};
	class bldr_SodaCan_Empty: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\drinks\SodaCan_Used.p3d";
	};
	class bldr_BoxCerealCrunchin: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\BoxCereal.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\gear\food\Data\CerealBox_01_CO.paa"};
	};
	class bldr_PowderedMilk: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\PowderedMilk.p3d";
	};
	class bldr_SmallGuts: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\animal_smallguts.p3d";
	};
	class bldr_Guts: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\animal_guts.p3d";
	};
	class bldr_Rice: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\Rice.p3d";
	};
	class bldr_Marmalade: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\Marmalade.p3d";
	};
	class bldr_BakedBeansCan: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\food_can.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\deez_beans_co.paa"};
	};
	class bldr_BakedBeansCan_Opened: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\food_can_open.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\deez_beans_co.paa"};
	};
	class bldr_PeachesCan: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\food_can.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\canned_peaches_co.paa"};
	};
	class bldr_PeachesCan_Opened: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\food_can_open.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\canned_peaches_co.paa"};
	};
	class bldr_TacticalBaconCan: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\food_can.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\tactical_bacon_co.paa"};
	};
	class bldr_TacticalBaconCan_Opened: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\food_can_open.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\tactical_bacon_co.paa"};
	};
	class bldr_SpaghettiCan: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\food_can.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\canned_spaghetti_co.paa"};
	};
	class bldr_SpaghettiCan_Opened: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\food_can_open.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\canned_spaghetti_co.paa"};
	};
	class bldr_SardinesCan: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\can_sardines.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\sardines_CO.paa"};
	};
	class bldr_SardinesCan_Opened: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\can_sardines_open.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\sardines_CO.paa"};
	};
	class bldr_TunaCan: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\Tuna.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\tuna_CO.paa"};
	};
	class bldr_TunaCan_Opened: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\tuna_open.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\tuna_CO.paa"};
	};
	class bldr_Apple: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\apple_fresh.p3d";
		hiddenSelections[] = {"cs_raw","cs_boiled","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\apple_raw_CO.paa","dz\gear\food\data\apple_baked_CO.paa","dz\gear\food\data\apple_baked_CO.paa","dz\gear\food\data\apple_dried_CO.paa","dz\gear\food\data\apple_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\apple_raw.rvmat","dz\gear\food\data\apple_baked.rvmat","dz\gear\food\data\apple_boiled.rvmat","dz\gear\food\data\apple_dried.rvmat","dz\gear\food\data\apple_burnt.rvmat","dz\gear\food\data\apple_rotten.rvmat"};
	};
	class bldr_Banana: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\banana_fresh.p3d";
		hiddenSelections[] = {"cs_raw","cs_rotten"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\banana_frash_CO.paa","dz\gear\food\data\ban_rotten_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\banana_frash.rvmat","dz\gear\food\data\banana_rotten.rvmat"};
	};
	class bldr_Orange: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\orange_fresh.p3d";
		hiddenSelections[] = {"cs_raw","cs_rotten"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\orange_frash_CO.paa","dz\gear\food\data\orange_rotten_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\orange_frash.rvmat","dz\gear\food\data\orange_rotten.rvmat"};
	};
	class bldr_Tomato: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\tomato.p3d";
		hiddenSelections[] = {"cs_raw","cs_burned"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\tomato_raw_CO.paa","dz\gear\food\data\tomato_baked_CO.paa","dz\gear\food\data\tomato_baked_CO.paa","dz\gear\food\data\tomato_dried_CO.paa","dz\gear\food\data\tomato_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\tomato_raw.rvmat","dz\gear\food\data\tomato_baked.rvmat","dz\gear\food\data\tomato_boiled.rvmat","dz\gear\food\data\tomato_dried.rvmat","dz\gear\food\data\tomato_burnt.rvmat","dz\gear\food\data\tomato_rotten.rvmat"};
	};
	class bldr_GreenBellPepper: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\pepper_green.p3d";
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\pepper_green_raw_CO.paa","dz\gear\food\data\pepper_green_baked_CO.paa","dz\gear\food\data\pepper_green_baked_CO.paa","dz\gear\food\data\pepper_green_dried_CO.paa","dz\gear\food\data\pepper_green_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\pepper_green_raw.rvmat","dz\gear\food\data\pepper_green_boiled.rvmat","dz\gear\food\data\pepper_green_baked.rvmat","dz\gear\food\data\pepper_green_dried.rvmat","dz\gear\food\data\pepper_green_burnt.rvmat","dz\gear\food\data\pepper_green_rotten.rvmat"};
	};
	class bldr_Zucchini: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\zucchini_fresh.p3d";
		hiddenSelections[] = {"cs_raw","cs_burned"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\zucchini_raw_CO.paa","dz\gear\food\data\zucchini_baked_CO.paa","dz\gear\food\data\zucchini_baked_CO.paa","dz\gear\food\data\zucchini_dried_CO.paa","dz\gear\food\data\zucchini_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\zucchini_raw.rvmat","dz\gear\food\data\zucchini_boiled.rvmat","dz\gear\food\data\zucchini_baked.rvmat","dz\gear\food\data\zucchini_dried.rvmat","dz\gear\food\data\zucchini_burnt.rvmat","dz\gear\food\data\zucchini_rotten.rvmat"};
	};
	class bldr_Pumpkin: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\Pumpkin_fresh.p3d";
		hiddenSelections[] = {"cs_raw","cs_rotten"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\pumpkin_fresh_CO.paa","dz\gear\food\data\pumpkin_rotten_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\pumpkin_fresh.rvmat","dz\gear\food\data\pumpkin_rotten.rvmat"};
	};
	class bldr_SlicedPumpkin: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\pumpkin_sliced.p3d";
		hiddenSelections[] = {"cs_raw","cs_baked","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\pumpkin_sliced_raw_CO.paa","dz\gear\food\data\pumpkin_sliced_baked_CO.paa","dz\gear\food\data\pumpkin_sliced_baked_CO.paa","dz\gear\food\data\pumpkin_sliced_dried_CO.paa","dz\gear\food\data\pumpkin_sliced_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\pumpkin_sliced_raw.rvmat","dz\gear\food\data\pumpkin_sliced_boiled.rvmat","dz\gear\food\data\pumpkin_sliced_baked.rvmat","dz\gear\food\data\pumpkin_sliced_dried.rvmat","dz\gear\food\data\pumpkin_sliced_burnt.rvmat","dz\gear\food\data\pumpkin_sliced_rotten.rvmat"};
	};
	class bldr_Potato: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\potato_fresh.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\potato_raw_CO.paa","dz\gear\food\data\potato_baked_CO.paa","dz\gear\food\data\potato_baked_CO.paa","dz\gear\food\data\potato_dried_CO.paa","dz\gear\food\data\potato_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\potato_raw.rvmat","dz\gear\food\data\potato_boiled.rvmat","dz\gear\food\data\potato_baked.rvmat","dz\gear\food\data\potato_dried.rvmat","dz\gear\food\data\potato_burnt.rvmat","dz\gear\food\data\potato_rotten.rvmat"};
	};
	class bldr_Kiwi: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\kiwi_fresh.p3d";
		hiddenSelections[] = {"cs_raw","cs_rotten"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\kiwi_frash_CO.paa","dz\gear\food\data\kiwi_rotten_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\kiwi_frash.rvmat","dz\gear\food\data\kiwi_rotten.rvmat"};
	};
	class bldr_SambucusBerry: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\Sambucus_nigra.p3d";
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\sambucus_nigra_CO.paa","dz\gear\food\data\sambucus_nigra_dried_CO.paa","dz\gear\food\data\sambucus_nigra_dried_CO.paa","dz\gear\food\data\sambucus_nigra_dried_CO.paa","dz\gear\food\data\sambucus_nigra_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\sambucus_nigra_raw.rvmat","dz\gear\food\data\sambucus_nigra_boiled.rvmat","dz\gear\food\data\sambucus_nigra_baked.rvmat","dz\gear\food\data\sambucus_nigra_dried.rvmat","dz\gear\food\data\sambucus_nigra_burnt.rvmat","dz\gear\food\data\sambucus_nigra_rotten.rvmat"};
	};
	class bldr_CaninaBerry: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\canina_raw.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\canina_raw_CO.paa","dz\gear\food\data\canina_baked_CO.paa","dz\gear\food\data\canina_raw_CO.paa","dz\gear\food\data\canina_dried_CO.paa","dz\gear\food\data\canina_baked_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\canina_raw.rvmat","dz\gear\food\data\canina_baked.rvmat","dz\gear\food\data\canina_boiled.rvmat","dz\gear\food\data\canina_dried.rvmat","dz\gear\food\data\canina_burnt.rvmat","dz\gear\food\data\canina_rotten.rvmat"};
	};
	class bldr_Cannabis: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\cannabis_seedman.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\cannabis_seedman_raw_CO.paa","dz\gear\food\data\cannabis_seedman_baked_CO.paa","dz\gear\food\data\cannabis_seedman_raw_CO.paa","dz\gear\food\data\cannabis_seedman_raw_CO.paa","dz\gear\food\data\cannabis_seedman_baked_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\cannabis_seedman_raw.rvmat","dz\gear\food\data\cannabis_seedman_baked.rvmat","dz\gear\food\data\cannabis_seedman_raw.rvmat","dz\gear\food\data\cannabis_seedman_dried.rvmat","dz\gear\food\data\cannabis_seedman_burnt.rvmat","dz\gear\food\data\cannabis_seedman_rotten.rvmat"};
	};
	class bldr_Plum: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\plum.p3d";
		hiddenSelections[] = {"cs_raw","cs_baked","cs_boiled","cs_dried","cs_burned"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\plum_raw_CO.paa","dz\gear\food\data\plum_baked_CO.paa","dz\gear\food\data\plum_boiled_CO.paa","dz\gear\food\data\plum_dried_CO.paa","dz\gear\food\data\plum_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\plum_raw.rvmat","dz\gear\food\data\plum_boiled.rvmat","dz\gear\food\data\plum_baked.rvmat","dz\gear\food\data\plum_dried.rvmat","dz\gear\food\data\plum_burnt.rvmat","dz\gear\food\data\plum_rotten.rvmat"};
	};
	class bldr_Pear: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\pear.p3d";
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\pear_raw_CO.paa","dz\gear\food\data\pear_baked_CO.paa","dz\gear\food\data\pear_baked_CO.paa","dz\gear\food\data\pear_dried_CO.paa","dz\gear\food\data\pear_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\pear_raw.rvmat","dz\gear\food\data\pear_boiled.rvmat","dz\gear\food\data\pear_baked.rvmat","dz\gear\food\data\pear_dried.rvmat","dz\gear\food\data\pear_burnt.rvmat","dz\gear\food\data\pear_rotten.rvmat"};
	};
	class bldr_HumanSteakMeat: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\human_meat.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
	};
	class bldr_GoatSteakMeat: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\meat_steak.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
	};
	class bldr_MouflonSteakMeat: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\meat_steak.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
	};
	class bldr_BoarSteakMeat: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\meat_steak.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
	};
	class bldr_PigSteakMeat: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\meat_steak.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
	};
	class bldr_DeerSteakMeat: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\meat_steak.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
	};
	class bldr_WolfSteakMeat: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\meat_steak.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
	};
	class bldr_BearSteakMeat: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\meat_steak.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
	};
	class bldr_CowSteakMeat: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\meat_steak.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
	};
	class bldr_SheepSteakMeat: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\meat_steak.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
	};
	class bldr_FoxSteakMeat: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\meat_steak.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
	};
	class bldr_ChickenBreastMeat: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\meat_breast.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_breast_raw_CO.paa","dz\gear\food\data\meat_breast_baked_CO.paa","dz\gear\food\data\meat_breast_baked_CO.paa","dz\gear\food\data\meat_breast_dried_CO.paa","dz\gear\food\data\meat_breast_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_breast_raw.rvmat","dz\gear\food\data\meat_breast_baked.rvmat","dz\gear\food\data\meat_breast_boiled.rvmat","dz\gear\food\data\meat_breast_dried.rvmat","dz\gear\food\data\meat_breast_burnt.rvmat","dz\gear\food\data\meat_breast_rotten.rvmat"};
	};
	class bldr_RabbitLegMeat: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\meat_leg.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_leg_raw_CO.paa","dz\gear\food\data\meat_leg_baked_CO.paa","dz\gear\food\data\meat_leg_baked_CO.paa","dz\gear\food\data\meat_leg_dried_CO.paa","dz\gear\food\data\meat_leg_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_leg_raw.rvmat","dz\gear\food\data\meat_leg_baked.rvmat","dz\gear\food\data\meat_leg_boiled.rvmat","dz\gear\food\data\meat_leg_dried.rvmat","dz\gear\food\data\meat_leg_burnt.rvmat","dz\gear\food\data\meat_leg_rotten.rvmat"};
	};
	class bldr_CarpFilletMeat: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\carp_fillet_raw_CO.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\carp_fillet_raw.rvmat","dz\gear\food\data\carp_fillet_baked.rvmat","dz\gear\food\data\carp_fillet_boiled.rvmat","dz\gear\food\data\carp_fillet_dried.rvmat","dz\gear\food\data\carp_fillet_burnt.rvmat","dz\gear\food\data\carp_fillet_rotten.rvmat"};
	};
	class bldr_MackerelFilletMeat: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mackerel_fillet_raw_CO.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mackerel_fillet_raw.rvmat","dz\gear\food\data\mackerel_fillet_baked.rvmat","dz\gear\food\data\mackerel_fillet_boiled.rvmat","dz\gear\food\data\mackerel_fillet_dried.rvmat","dz\gear\food\data\mackerel_fillet_burnt.rvmat","dz\gear\food\data\mackerel_fillet_rotten.rvmat"};
	};
	class bldr_Lard: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\lard.p3d";
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\lard_raw_CO.paa","dz\gear\food\data\lard_baked_CO.paa","dz\gear\food\data\lard_boiled_CO.paa","dz\gear\food\data\lard_dried_CO.paa","dz\gear\food\data\lard_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\lard_raw.rvmat","dz\gear\food\data\lard_baked.rvmat","dz\gear\food\data\lard_boiled.rvmat","dz\gear\food\data\lard_dried.rvmat","dz\gear\food\data\lard_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
	};
	class bldr_Carp: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\carp_live.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\carp_live_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\carp_live.rvmat"};
	};
	class bldr_Sardines: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\sardines_live.p3d";
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\sardines_raw_CO.paa","dz\gear\food\data\sardines_baked_CO.paa","dz\gear\food\data\sardines_raw_CO.paa","dz\gear\food\data\sardines_baked_CO.paa","dz\gear\food\data\sardines_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\sardines_raw.rvmat","dz\gear\food\data\sardines_baked.rvmat","dz\gear\food\data\sardines_boiled.rvmat","dz\gear\food\data\sardines_dried.rvmat","dz\gear\food\data\sardines_burnt.rvmat","dz\gear\food\data\sardines_rotten.rvmat"};
	};
	class bldr_Mackerel: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\mackerel_live.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mackerel_live_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mackerel_live.rvmat"};
	};
	class bldr_Worm: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\bait_worm.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\bait_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\bait.rvmat"};
	};
	class bldr_AgaricusMushroom: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\mushroom_agaricus.p3d";
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mushroom_agaricus_raw_CO.paa","dz\gear\food\data\mushroom_agaricus_baked_CO.paa","dz\gear\food\data\mushroom_agaricus_baked_CO.paa","dz\gear\food\data\mushroom_agaricus_dried_CO.paa","dz\gear\food\data\mushroom_agaricus_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mushroom_agaricus_raw.rvmat","dz\gear\food\data\mushroom_agaricus_baked.rvmat","dz\gear\food\data\mushroom_agaricus_boiled.rvmat","dz\gear\food\data\mushroom_agaricus_dried.rvmat","dz\gear\food\data\mushroom_agaricus_burnt.rvmat","dz\gear\food\data\mushroom_agaricus_rotten.rvmat"};
	};
	class bldr_AmanitaMushroom: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\mushroom_amanita.p3d";
		hiddenSelections[] = {"cs_raw","cs_boiled"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mushroom_amanita_raw_CO.paa","dz\gear\food\data\mushroom_amanita_boiled_CO.paa","dz\gear\food\data\mushroom_amanita_baked_CO.paa","dz\gear\food\data\mushroom_amanita_dried_CO.paa","dz\gear\food\data\mushroom_amanita_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mushroom_amanita_raw.rvmat","dz\gear\food\data\mushroom_amanita_baked.rvmat","dz\gear\food\data\mushroom_amanita_boiled.rvmat","dz\gear\food\data\mushroom_amanita_dried.rvmat","dz\gear\food\data\mushroom_amanita_burnt.rvmat","dz\gear\food\data\mushroom_amanita_rotten.rvmat"};
	};
	class bldr_MacrolepiotaMushroom: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\mushroom_macrolepiota.p3d";
		hiddenSelections[] = {"cs_raw","cs_baked","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mushroom_macrolepiota_raw_CO.paa","dz\gear\food\data\mushroom_macrolepiota_baked_CO.paa","dz\gear\food\data\mushroom_macrolepiota_baked_CO.paa","dz\gear\food\data\mushroom_macrolepiota_dried_CO.paa","dz\gear\food\data\mushroom_macrolepiota_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mushroom_macrolepiota_raw.rvmat","dz\gear\food\data\mushroom_macrolepiota_baked.rvmat","dz\gear\food\data\mushroom_macrolepiota_boiled.rvmat","dz\gear\food\data\mushroom_macrolepiota_dried.rvmat","dz\gear\food\data\mushroom_macrolepiota_burnt.rvmat","dz\gear\food\data\mushroom_macrolepiota_rotten.rvmat"};
	};
	class bldr_LactariusMushroom: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\mushroom_lactarius.p3d";
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mushroom_lactarius_raw_CO.paa","dz\gear\food\data\mushroom_lactarius_baked_CO.paa","dz\gear\food\data\mushroom_lactarius_baked_CO.paa","dz\gear\food\data\mushroom_lactarius_dried_CO.paa","dz\gear\food\data\mushroom_lactarius_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mushroom_lactarius_raw.rvmat","dz\gear\food\data\mushroom_lactarius_baked.rvmat","dz\gear\food\data\mushroom_lactarius_boiled.rvmat","dz\gear\food\data\mushroom_lactarius_dried.rvmat","dz\gear\food\data\mushroom_lactarius_burnt.rvmat","dz\gear\food\data\mushroom_lactarius_rotten.rvmat"};
	};
	class bldr_PsilocybeMushroom: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\Psilocybe_semilanceata.p3d";
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\Psilocybe_semilanceata_CO.paa","dz\gear\food\data\Psilocybe_semilanceata_dried_CO.paa","dz\gear\food\data\Psilocybe_semilanceata_dried_CO.paa","dz\gear\food\data\Psilocybe_semilanceata_dried_CO.paa","dz\gear\food\data\Psilocybe_semilanceata_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\Psilocybe_semilanceata_raw.rvmat","dz\gear\food\data\Psilocybe_semilanceata_baked.rvmat","dz\gear\food\data\Psilocybe_semilanceata_boiled.rvmat","dz\gear\food\data\Psilocybe_semilanceata_dried.rvmat","dz\gear\food\data\Psilocybe_semilanceata_burnt.rvmat","dz\gear\food\data\Psilocybe_semilanceata_rotten.rvmat"};
	};
	class bldr_AuriculariaMushroom: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\mushroom_auricularia.p3d";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mushroom_auricularia_raw_CO.paa","dz\gear\food\data\mushroom_auricularia_baked_CO.paa","dz\gear\food\data\mushroom_auricularia_boiled_CO.paa","dz\gear\food\data\mushroom_auricularia_dried_CO.paa","dz\gear\food\data\mushroom_auricularia_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mushroom_auricularia_raw.rvmat","dz\gear\food\data\mushroom_auricularia_baked.rvmat","dz\gear\food\data\mushroom_auricularia_boiled.rvmat","dz\gear\food\data\mushroom_auricularia_dried.rvmat","dz\gear\food\data\mushroom_auricularia_burnt.rvmat","dz\gear\food\data\mushroom_auricularia_rotten.rvmat"};
	};
	class bldr_BoletusMushroom: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\Mushroom_boletus.p3d";
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mushroom_boletus_raw_CO.paa","dz\gear\food\data\mushroom_boletus_boiled_CO.paa","dz\gear\food\data\mushroom_boletus_boiled_CO.paa","dz\gear\food\data\mushroom_boletus_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mushroom_boletus_raw.rvmat","dz\gear\food\data\mushroom_boletus_baked.rvmat","dz\gear\food\data\mushroom_boletus_boiled.rvmat","dz\gear\food\data\mushroom_boletus_dried.rvmat","dz\gear\food\data\mushroom_boletus_burnt.rvmat","dz\gear\food\data\mushroom_boletus_rotten.rvmat"};
	};
	class bldr_PleurotusMushroom: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\food\mushroom_pleurotus.p3d";
		hiddenSelections[] = {"cs_raw","cs_boiled","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mushroom_pleurotus_raw_CO.paa","dz\gear\food\data\mushroom_pleurotus_baked_CO.paa","dz\gear\food\data\mushroom_pleurotus_baked_CO.paa","dz\gear\food\data\mushroom_pleurotus_dried_CO.paa","dz\gear\food\data\mushroom_pleurotus_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mushroom_pleurotus_raw.rvmat","dz\gear\food\data\mushroom_pleurotus_baked.rvmat","dz\gear\food\data\mushroom_pleurotus_boiled.rvmat","dz\gear\food\data\mushroom_pleurotus_dried.rvmat","dz\gear\food\data\mushroom_pleurotus_burnt.rvmat","dz\gear\food\data\mushroom_pleurotus_rotten.rvmat"};
	};
	class bldr_KitchenKnife: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\tools\kitchenknife.p3d";
	};
	class bldr_MeatTenderizer: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\tools\Meat_Tenderizer.p3d";
	};
	class bldr_Pot: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\cooking\CookingPot.p3d";
	};
	class bldr_MediumGasCanister: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\consumables\GasCannisterMedium.p3d";
	};
	class bldr_PortableGasStove: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\cooking\GasCooker.p3d";
	};
	class bldr_LargeGasCanister: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\consumables\GasCannisterLarge.p3d";
	};
	class bldr_SmallGasCanister: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\consumables\GasCannisterSmall.p3d";
	};
	class bldr_PortableGasLamp: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\cooking\GasLight.p3d";
	};
	class bldr_DisinfectantSpray: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\medical\DisinfectantSpray.p3d";
	};
	class bldr_DisinfectantAlcohol: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\medical\alfa.p3d";
	};
	class bldr_VitaminBottle: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\medical\VitaminBottle.p3d";
	};
	class bldr_CharcoalTablets: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\medical\charcoal_tablets.p3d";
	};
	class bldr_PainkillerTablets: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\medical\painkillers2.p3d";
	};
	class bldr_TetracyclineAntibiotics: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\gear\medical\tetracycline.p3d";
	};
};
