/**
 * ExpansionMarketKits.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2021 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionMarketKits: ExpansionMarketCategory
{
	override void Defaults()
	{
		super.Defaults();

		CategoryID = 31;
		DisplayName = "#STR_EXPANSION_MARKET_CATEGORY_KITS";
		m_FileName = "Kits";
		
		AddItem("SewingKit", 					4,		8,		1,		100,	0);
		AddItem("LeatherSewingKit", 			5,		10,		1,		100,	0);
		AddItem("WeaponCleaningKit", 			8,		16,		1,		100,	0);
	}
};