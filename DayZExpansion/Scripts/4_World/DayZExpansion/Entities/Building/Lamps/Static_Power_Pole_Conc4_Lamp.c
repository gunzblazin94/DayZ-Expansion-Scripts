/**
 * Static_Power_Pole_Conc4_Lamp.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2021 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

/**@class		Static_Lamp_Rail
 * @brief		
 **/
class Static_Power_Pole_Conc4_Lamp: ExpansionLampLightBase
{
	override vector GetLampPosition()
	{
		return "-0.81982 5.0445 -0.01017";
	}
};
class bldr_Power_Pole_Conc4_Lamp: Static_Power_Pole_Conc4_Lamp {};
class bldr_Power_Pole_Conc4_Lamp_trail_b: Static_Power_Pole_Conc4_Lamp {};
class bldr_Power_Pole_Conc4_Lamp_trail_g: Static_Power_Pole_Conc4_Lamp {};
class bldr_Power_Pole_Conc4_Lamp_trail_r: Static_Power_Pole_Conc4_Lamp {};
class bldr_Power_Pole_Conc4_Lamp_trail_y: Static_Power_Pole_Conc4_Lamp {};