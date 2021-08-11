/**
 * DayZPlayerImplement.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2021 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class DayZPlayerImplement
{
	protected ref ExpansionHumanST m_ExpansionST;

	private int m_Expansion_Vehicle_SeatIndex;

	void DayZPlayerImplement()
	{
		RegisterNetSyncVariableInt("m_Expansion_Vehicle_SeatIndex");
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}

	
	// ------------------------------------------------------------
	// DayZPlayerImplement StartCommand_ExpansionVehicle
	// ------------------------------------------------------------
	ExpansionHumanCommandVehicle StartCommand_ExpansionVehicle( ExpansionVehicleBase vehicle, int seatIdx, int seat_anim )
	{
		return NULL;
	}
	
	// ------------------------------------------------------------
	// DayZPlayerImplement GetCommand_ExpansionVehicle
	// ------------------------------------------------------------
	ExpansionHumanCommandVehicle GetCommand_ExpansionVehicle()
	{
		return ExpansionHumanCommandVehicle.Cast( GetCommand_Script() );
	}
		
	// ------------------------------------------------------------
	// DayZPlayerImplement GetExpansionTransport
	// ------------------------------------------------------------
	ExpansionVehicleBase GetExpansionTransport()
	{
		ExpansionHumanCommandVehicle script;
		if ( Class.CastTo( script, GetCommand_Script() ) )
		{
			return script.GetTransport();
		}

		return NULL;
	}
	
	void OnCommandExpansionVehicleStart()
	{
	}
	
	void OnCommandExpansionVehicleFinish()
	{
	}
				
	// ------------------------------------------------------------
	// DayZPlayerImplement HeadingModel
	// ------------------------------------------------------------
	override bool HeadingModel( float pDt, SDayZPlayerHeadingModel pModel )
	{		
		if ( GetCommand_ExpansionVehicle() )
		{
			m_fLastHeadingDiff = 0;

			return false;
		}
		
		return super.HeadingModel( pDt, pModel );
	}
				
	// ------------------------------------------------------------
	// DayZPlayerImplement CameraHandler
	// ------------------------------------------------------------
	override int CameraHandler( int pCameraMode )
	{
		ExpansionVehicleBase exTrans;
		ExpansionHumanCommandVehicle vehicleCommand = GetCommand_ExpansionVehicle();
		if ( vehicleCommand )
			exTrans = vehicleCommand.GetTransport();

		if ( m_Camera3rdPerson )
		{
			if ( vehicleCommand && exTrans )
			{
				int cameraType = exTrans.Get3rdPersonCameraType();
				if ( cameraType != -1 )
					return cameraType;
			}

			/*CarScript car;
			if ( Class.CastTo( car, GetParent() ) && !GetCommand_Vehicle() )
			{
				int carCameraType = car.Get3rdPersonCameraType();
				if ( carCameraType != -1 )
				{
					#ifdef EXPANSIONEXPRINT
					EXPrint( "DayZPlayerImplement::CameraHandler - Return carCameraType: " + carCameraType.ToString() );
					#endif
					return carCameraType;
				}
			}*/
		} else
		{
			if ( vehicleCommand )
			{
				return DayZPlayerCameras.DAYZCAMERA_1ST_VEHICLE;
			}
		}

		return super.CameraHandler( pCameraMode );
	}

	void SetHeadInvisible_Ex(bool invisible)
	{
		Head_Default player_head;
		int slot_id = InventorySlots.GetSlotIdFromString("Head");
		player_head = Head_Default.Cast(GetInventory().FindPlaceholderForSlot(slot_id));
		
		player_head.SetInvisible(invisible);

		SetAttachmentInvisible_Ex("Head", invisible);
		SetAttachmentInvisible_Ex("Headgear", invisible);
		SetAttachmentInvisible_Ex("Mask", invisible);
		SetAttachmentInvisible_Ex("Eyewear", invisible);
	}

	void SetAttachmentInvisible_Ex(string slot, bool invisible)
	{
		int slot_id = InventorySlots.GetSlotIdFromString(slot);
		EntityAI ent = GetInventory().FindAttachment(slot_id);

		if (ent)
			ent.SetInvisible(invisible);
	}
}