/**
 * ExpansionMarketSniperRifles.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2021 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionMarketSniperRifles: ExpansionMarketCategory
{
	// ------------------------------------------------------------
	// Expansion Defaults
	// ------------------------------------------------------------
	override void Defaults()
	{
		super.Defaults();

		CategoryID = 51;
		DisplayName = "#STR_EXPANSION_MARKET_CATEGORY_SNIPER_RIFLES";
		m_FileName = "Sniper_Rifles";

		AddItem("VSS", 						1600,	3200,	1,		100,	{"Mag_VSS_10Rnd"});
		AddItem("ASVAL", 					1600,	3200,	1,		100,	{"Mag_VAL_20Rnd"});
		AddItem("B95", 						1700,	3400,	1,		100);
		AddItem("SVD", 						2000,	4000,	1,		100,	{"Mag_SVD_10Rnd"});

		if (IsMapEnoch())
		{
			AddItem("Scout_Livonia", 		2100,	4200,	1,		100,	{"Mag_Scout_5Rnd"});
		}
		else if (IsMapChernarus())
		{
			AddItem("Scout_Chernarus", 		2100,	4200,	1,		100,	{"Mag_Scout_5Rnd"});
		}
		else
		{
			AddItem("Scout", 				2100,	4200,	1,		100,	{"Mag_Scout_5Rnd"});
		}
	#ifdef EXPANSIONMOD
		AddItem("Expansion_AWM", 			5000,	10000,	1,		100,	{"Mag_Expansion_AWM_5rnd"});
	#endif
	}
};