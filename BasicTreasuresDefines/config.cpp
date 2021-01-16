class CfgPatches
{
	class BasicTreasuresDefine
	{
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};

class CfgMods
{
	class BasicTreasuresDefine
	{
		dir="BasicTerritoriesDefine";
        name="BasicTreasures";
        type="mod";
	    dependencies[]={"GameLib", "Game", "World", "Mission"};
	    class defs
	    {
			class gameLibScriptModule
			{
				value = "";
				files[] = {
					"BasicTreasuresDefine/scripts/Common"
					};
			};
			class gameScriptModule
            {
				value = "";
                files[]={
					"BasicTreasuresDefine/scripts/Common"
					};
            };
			
			class worldScriptModule
            {
                value="";
                files[]={ 
					"BasicTreasuresDefine/scripts/Common"
				};
            };
			
	        class missionScriptModule
            {
                value="";
                files[]={
					"BasicTreasuresDefine/scripts/Common"
				};
            };
        };
    };
};