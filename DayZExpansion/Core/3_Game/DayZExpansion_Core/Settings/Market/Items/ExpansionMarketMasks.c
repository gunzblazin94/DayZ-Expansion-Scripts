/**
 * ExpansionMarketMasks.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionMarketMasks: ExpansionMarketCategory
{
	// ------------------------------------------------------------
	// Expansion Defaults
	//
	// Price calculation and legend:
	// SN - Silver Nugget 	- .1
	// SB - Silver Bar 		- 1
	// GN - Gold Nugget 	- 10
	// GB - Gold Bar 		- 1000
	//
	//	string 	ClassName 			- Item class name that gets defined
	//	float 	MinPriceThreshold 	- Min price for the price threshold calculation
	//	float	MaxPriceThreshold 	- Max price for the price threshold calculation
	//	int		MinStockThreshold 	- Min stock for the price threshold calculation
	//	int		MaxStockThreshold 	- Max stock for the price threshold calculation
	//	int		PurchaseType		- 0 = Normal Item Trader / 1 = Vehicle Trader
	//	array	SpawnAttachments	- Array of item class names that gets attached to this item on buy.
	// ------------------------------------------------------------
	override void Defaults()
	{
		super.Defaults();

		CategoryID = 38;
		DisplayName = "#STR_EXPANSION_MARKET_CATEGORY_MASKS";
		m_FileName = "Masks";

		AddItem("GasMask", 							12,		14,		1,		250,	0 );
		
		AddItem("BandanaMask_RedPattern", 			3,		5,		1,		250,	0 );
		AddItem("BandanaMask_BlackPattern", 		3,		5,		1,		250,	0 );
		AddItem("BandanaMask_PolkaPattern",			3,		5,		1,		250,	0 );
		AddItem("BandanaMask_GreenPattern", 		3,		5,		1,		250,	0 );
		AddItem("BandanaMask_CamoPattern", 			3,		5,		1,		250,	0 );
		
		AddItem("NioshFaceMask", 					4,		6,		1,		250,	0 );
		
		AddItem("BalaclavaMask_Black", 				5,		7,		1,		250,	0 );
		AddItem("BalaclavaMask_Blackskull",			5,		7,		1,		250,	0 );
		AddItem("BalaclavaMask_Beige", 				5,		7,		1,		250,	0 );
		AddItem("BalaclavaMask_Blue", 				5,		7,		1,		250,	0 );
		AddItem("BalaclavaMask_Green", 				5,		7,		1,		250,	0 );
		AddItem("BalaclavaMask_Pink", 				5,		7,		1,		250,	0 );
		AddItem("BalaclavaMask_White", 				5,		7,		1,		250,	0 );
		
		AddItem("AirboneMask", 						15,		17,		1,		250,	0 );
		AddItem("GP5GasMask", 						15,		17,		1,		250,	0 );
		
		AddItem("Balaclava3Holes_Beige", 			5,		7,		1,		250,	0 );
		AddItem("Balaclava3Holes_Blue", 			5,		7,		1,		250,	0 );
		AddItem("Balaclava3Holes_Black", 			5,		7,		1,		250,	0 );
		AddItem("Balaclava3Holes_Green", 			5,		7,		1,		250,	0 );
		AddItem("SurgicalMask", 					5,		7,		1,		250,	0 );
		
		AddItem("HockeyMask", 						4,		6,		1,		250,	0 );	
	}
};