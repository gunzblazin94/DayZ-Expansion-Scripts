/**
 * OffroadHatchback.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2021 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class OffroadHatchback
{
	override bool IsVitalCarBattery()
	{
		return true;
	}
	override string ExpansionGetWheelType(int slot_id)
	{
		return "HatchbackWheel";
	}

	override float GetCameraDistance()
	{
		return 3.5;
	}
}