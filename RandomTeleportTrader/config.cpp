/*
    Any reuploads or republishes without permission from LinuxPhantom will result in a DMCA. ,"trader"
*/
class CfgPatches
{
	class RandomTeleportTrader
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Structures","trader"};
	};
};

class CfgMods
{
	class RandomTeleportTrader
	{
		type = "mod";
		dependencies[] = {"Mission"};
		class defs
		{
			class missionScriptModule
			{
				value = "";
				files[] = {"RandomTeleportTrader/scripts/5_Mission"};
			};
		};
	};
};
