/**
 * ExpansionMarketMenuState.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2021 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

enum ExpansionMarketMenuState
{
	INVALID = -1,
	NONE,
	LOADING,
	DIALOG,
	REQUESTING_SELECTED_ITEM,
	REQUESTING_PURCHASE,
	REQUESTING_SELL,
	REQUESTING_EXCHANGE_PURCHASE,
	REQUESTING_EXCHANGE_SELL,
	CONFIRMING_PURCHASE,
	CONFIRMING_SELL,
	COUNT
}