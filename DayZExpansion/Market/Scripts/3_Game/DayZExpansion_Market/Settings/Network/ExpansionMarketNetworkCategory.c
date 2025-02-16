/**
 * ExpansionMarketNetworkCategory.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2021 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionMarketNetworkCategory
{
	string Name;
	string Icon;
	int Color;

	int CategoryID;

	string m_FileName;

	void ExpansionMarketNetworkCategory( ExpansionMarketCategory category )
	{
		Name = category.DisplayName;
		Icon = category.Icon;
		Color = ExpansionColor.HexToARGB(category.Color);
		CategoryID = category.CategoryID;
		m_FileName = category.m_FileName;
	}
};