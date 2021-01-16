class CfgPatches
{
	class BasicTreasures
	{
		requiredVersion = 0.1;
		requiredAddons[] = {
			"BasicMap",
			"BasicTreasuresDefine"
		};
	};
};

class CfgMods
{
	class BasicTreasures
	{
		dir="BasicTreasures";
        name="BasicTreasures";
        credits="DaemonForge";
        author="DaemonForge";
        authorID="0";
        version="0.1";
        extra=0;
        type = "Mod";
	    dependencies[]={"Game", "World", "Mission"};
	    class defs
	    {
			class gameScriptModule
            {
				value = "";
                files[]={
					"BasicTreasures/scripts/3_Game"
					};
            };
			
			class worldScriptModule
            {
                value="";
                files[]={ 
					"BasicTreasures/scripts/4_World" 
				};
            };
			
	        class missionScriptModule
            {
                value="";
                files[]={
					"BasicTreasures/scripts/5_Mission" 
				};
            };
        };
    };
	
	
};