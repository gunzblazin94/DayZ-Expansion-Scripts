/**
 * ExpansionWoodPillarKit.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2021 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

/**@class		ExpansionWoodPillarKit
 * @brief		This class handle base class of expansion basebuilding	
 **/
class ExpansionWoodPillarKit extends ExpansionKitLarge
{
	// ------------------------------------------------------------
	// OnPlacementComplete
	// ------------------------------------------------------------
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( IsMissionHost() )
		{			
			ExpansionWoodPillar pillar = ExpansionWoodPillar.Cast( GetGame().CreateObject( "ExpansionWoodPillar", GetPosition() ) );
			pillar.SetPosition( position );
			pillar.SetOrientation( orientation );
			
			//! Make the kit invisible, so it can be destroyed from deploy UA when action ends
			HideAllSelections();

			GetGame().ObjectDelete(this);
		}	
		
		SetIsDeploySound( true );
	}
}