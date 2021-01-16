modded class BasicMapController {
	protected ref array<vector> ChestSpawnPoints;
	static string ChestSpawnPath = "\\ChestSpawns.json";
	protected int LastChestSpawnTime;
	
	override void Init(){
		super.Init();
		if (GetGame().IsMultiplayer() && !GetGame().IsClient()){
			GetBasicTreasuresConfig();
			if (FileExist(BasicMapPath + ChestSpawnPath)){
				Print("[Treasure] Init loading custom chest spawns");
				ChestSpawnPoints = new array<vector>;
				JsonFileLoader<ref array<vector> >.JsonLoadFile(BasicMapPath + ChestSpawnPath, ChestSpawnPoints);
			} else {
				string TheWorldName;
				GetGame().GetWorldName(TheWorldName);
				TheWorldName.ToLower();
				string TreasuresDefaultFileLocation =  "BasicTreasures\\data\\defaults\\" + TheWorldName + ".json";
				if (FileExist(TreasuresDefaultFileLocation)){
					Print("[Treasure] Init loading default locations for " + TheWorldName);
					JsonFileLoader<ref array<vector> >.JsonLoadFile(TreasuresDefaultFileLocation, ChestSpawnPoints);
				} else {
					Print("== == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==");
					Print("== == == == == == == == == == ==   WARNING   == == == == == == == == == == == == == == ==");
					Print("== == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==");
					Print("==                                                                                     ==");
					Print("==                       No Default Locations for Basic Treasures                      ==");
					Print("==                       Exist for World " + TheWorldName + "                          ==");
					Print("==                                                                                     ==");
					Print("== == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==");
					Print("== == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==");
				}
			}
			#ifdef NAMALSK_SURVIVAL
			Print("[Treasure] NAMALSK_SURVIVAL Detected");
			#endif
		}
	}

	bool IsLootSpawnsPresent(){
		if (ChestSpawnPath && ChestSpawnPoints.Count() > 0){
			return true;
		}
		return false;
	}
	
	vector GetRandomChestSpawn(){
		if (ChestSpawnPoints && ChestSpawnPoints.Count() > 0){
			return ChestSpawnPoints.GetRandomElement();
		}
		return Vector(3693.56005859375, GetGame().SurfaceY(3693.56005859375,6010.0498046875), 6010.0498046875);
	}
	
	bool CanSpawnNewChest(){
		int TimeNow = GetGame().GetTime();
		if (TimeNow > LastChestSpawnTime){
			return true;
		}
		return false;
	}
	
	void NewChestSpawned(){
		int TimeNow = GetGame().GetTime();
		int maxRate = GetBasicTreasuresConfig().MaxSpawnRate * 1000;
		LastChestSpawnTime = TimeNow + maxRate; //10 Seconds
		
	}
	
}
