/**
 * DayzPlayerCamera3rdPerson.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2021 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class DayZPlayerCamera3rdPerson
{
	override void OnUpdate( float pDt, out DayZPlayerCameraResult pOutResult )
	{
		ExpansionScriptViewMenuBase viewMenu = GetDayZGame().GetExpansionGame().GetExpansionUIManager().GetMenu();
		m_ExpansionIsScriptViewMenuVisible = viewMenu && viewMenu.IsVisible();

		super.OnUpdate( pDt, pOutResult );
	}
}
