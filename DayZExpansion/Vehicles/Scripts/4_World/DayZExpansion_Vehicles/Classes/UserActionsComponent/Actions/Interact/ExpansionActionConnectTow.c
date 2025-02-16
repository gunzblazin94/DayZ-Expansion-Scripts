/**
 * ExpansionActionConnectTow.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2021 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionActionConnectTowReciveData : ActionReciveData
{
	Object m_Car;
	int m_Index;
}

class ExpansionActionConnectTowData : ActionData
{
	Object m_Car;
	int m_Index;
};

class ExpansionActionConnectTow : ActionInteractBase
{
	bool m_IsWinch;

	void ExpansionActionConnectTow()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ALL;
		m_HUDCursorIcon = CursorIcons.OpenDoors;
	}

	override ActionData CreateActionData()
	{
		ExpansionActionConnectTowData action_data = new ExpansionActionConnectTowData;
		return action_data;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		if (m_IsWinch)
			return "#STR_EXPANSION_CONNECT_WINCH";

		return "#STR_EXPANSION_CONNECT_TOW";
	}

	override void WriteToContext(ParamsWriteContext ctx, ActionData action_data)
	{
		super.WriteToContext(ctx, action_data);

		ExpansionActionConnectTowData poActionData;
		poActionData = ExpansionActionConnectTowData.Cast(action_data);

		ctx.Write(poActionData.m_Car);
	}

	override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data)
	{
		if (!action_recive_data)
		{
			action_recive_data = new ExpansionActionConnectTowReciveData;
		}

		super.ReadFromContext(ctx, action_recive_data);

		ExpansionActionConnectTowReciveData action_data_po = ExpansionActionConnectTowReciveData.Cast(action_recive_data);

		if (!ctx.Read(action_data_po.m_Car))
			return false;

		return true;
	}

	override void HandleReciveData(ActionReciveData action_recive_data, ActionData action_data)
	{
		super.HandleReciveData(action_recive_data, action_data);

		ExpansionActionConnectTowReciveData recive_data_po = ExpansionActionConnectTowReciveData.Cast(action_recive_data);
		ExpansionActionConnectTowData action_data_po = ExpansionActionConnectTowData.Cast(action_data);

		action_data_po.m_Car = recive_data_po.m_Car;
	}

	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL)
	{
		if (super.SetupAction(player, target, item, action_data, extra_data))
		{
			ExpansionActionConnectTowData action_data_b = ExpansionActionConnectTowData.Cast(action_data);
			return GetCarToTow(player, action_data_b.m_Car, action_data_b.m_Index);
		}

		return false;
	}

	bool GetCarToTow(PlayerBase player, out Object out_car, out int out_index)
	{
		int i;
		Human crew;
		bool hasCrew;

		auto vehCommand = player.GetCommand_Vehicle();

		CarScript car;
		if (vehCommand && Class.CastTo(car, vehCommand.GetTransport()))
		{
			if (car.Expansion_IsTowing())
				return false;

			if (car.CrewMemberIndex(player) == DayZPlayerConstants.VEHICLESEAT_DRIVER)
			{
				array<Object> excluded = new array<Object>;
				array<Object> collided = new array<Object>;
				excluded.Insert(car);
				excluded.Insert(player);

				vector towPosition = car.ModelToWorld(car.Expansion_GetTowPosition());

				GetGame().IsBoxColliding(towPosition, car.Expansion_GetTowDirection(), "5 5 5", excluded, collided);

				float radius = 0.5;
				if (m_IsWinch)
					radius += 0.5;

				foreach (Object o : collided)
				{
					CarScript other_car;
					if (Class.CastTo(other_car, o))
					{
						if (!other_car.Expansion_IsBeingTowed() && !other_car.Expansion_IsTowing() && car.Expansion_CanConnectTow(other_car))
						{
							m_IsWinch = car.Expansion_IsHelicopter();

							//! Check if someone is inside the Vehicle the Helicopter is trying to winch
							//! Goal is to prevent a exploit allowing to get inside people bases
							if (m_IsWinch)
							{
								hasCrew = false;
								for (i = 0; i < other_car.CrewSize(); i++)
								{
									crew = other_car.CrewMember(i);
									if (crew)
										hasCrew = true;
								}

								if (hasCrew)
									continue;
							}

							if (other_car.Expansion_GetMass() * 0.9 < car.Expansion_GetMass())
							{
								if (other_car.Expansion_GetOverlappingTowConnection(towPosition, radius, out_index))
								{
									out_car = other_car;
									return true;
								}
							}
						}
					}

					ItemBase other_vehicle;
					if (Class.CastTo(other_vehicle, o))
					{
						if (!other_vehicle.Expansion_IsBeingTowed() && !other_vehicle.Expansion_IsTowing() && car.Expansion_CanConnectTow(other_vehicle))
						{
							m_IsWinch = car.Expansion_IsHelicopter();

							//! Check if someone is inside the Vehicle the Helicopter is trying to winch
							//! Goal is to prevent a exploit allowing to get inside people bases
							if (m_IsWinch)
							{
								auto helicopter = ExpansionVehicleHelicopterBase.Cast(other_vehicle);

								hasCrew = false;
								for (i = 0; i < helicopter.CrewSize(); i++)
								{
									crew = helicopter.CrewMember(i);
									if (crew)
										hasCrew = true;
								}

								if (hasCrew)
									continue;
							}

							if (other_vehicle.Expansion_GetOverlappingTowConnection(towPosition, radius, out_index))
							{
								out_car = other_vehicle;
								return true;
							}
						}
					}
				}
			}
		}

		return false;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		// only check on connection
		if (GetExpansionSettings() && !GetExpansionSettings().GetVehicle().Towing)
			return false;

		if (!super.ActionCondition(player, target, item))
			return false;

		Object car;
		int index;
		return GetCarToTow(player, car, index);
	}

	override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer(action_data);

		ExpansionActionConnectTowData action_data_b = ExpansionActionConnectTowData.Cast(action_data);

		HumanCommandVehicle vehCommand = action_data_b.m_Player.GetCommand_Vehicle();

		CarScript car;
		if (vehCommand && Class.CastTo(car, vehCommand.GetTransport()))
		{
			if (car.CrewMemberIndex(action_data_b.m_Player) == DayZPlayerConstants.VEHICLESEAT_DRIVER)
			{
				car.Expansion_CreateTow(action_data_b.m_Car, action_data_b.m_Index);

				if (GetGame().IsMultiplayer() && GetExpansionSettings().GetLog().VehicleTowing)
					GetExpansionSettings().GetLog().PrintLog("[VehicleTowing] Player \"" + action_data.m_Player.GetIdentity().GetName() + "\" (id=" + action_data.m_Player.GetIdentity().GetId() + " pos=" + action_data.m_Player.GetPosition() + ")" + " Towed " + action_data_b.m_Car.GetType() + " with " + car.GetType());
			}
		}
	}

	override bool CanBeUsedInVehicle()
	{
		return true;
	}
};
