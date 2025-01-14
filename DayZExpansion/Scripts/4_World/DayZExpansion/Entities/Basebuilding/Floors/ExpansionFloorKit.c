/**
 * ExpansionFloorKit.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2021 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

/**@class		ExpansionFloorKit
 * @brief		This class handle base class of expansion basebuilding	
 **/
class ExpansionFloorKit extends ExpansionKitLarge
{
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( IsMissionHost() )
			ExpansionDeploy( player, position, orientation );
	}
}

class ExpansionRoofKit : ExpansionFloorKit
{
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( IsMissionHost() )
		{
			Object obj = ExpansionDeploy( player, position, orientation );
			
			ExpansionFloorBase floor = ExpansionFloorBase.Cast( obj );
			if ( floor )
				floor.SetRoof( true );
		}
	}
}
