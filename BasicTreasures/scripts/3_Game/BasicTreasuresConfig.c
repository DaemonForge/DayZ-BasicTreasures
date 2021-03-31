class BasicTreasuresConfig
{
	protected static string ConfigPATH = "$profile:BasicMap\\Treasures.json";
	string ConfigVersion = "1";
	float ChanceOnSpawn = 0.2;
	int MaxSpawnRate = 5;
	ref array<ref BasicTreasuresRewardPool> RewardPools = new array<ref BasicTreasuresRewardPool>;
	
	void Load(){
		if (GetGame().IsServer()){
			if (FileExist(ConfigPATH)){ //If config exist load File
			    JsonFileLoader<BasicTreasuresConfig>.JsonLoadFile(ConfigPATH, this);
				if (ConfigVersion != "1"){

					Save();
				}
			}else{ //File does not exist create file	
				ref BasicTreasuresRewardPool TempReward = new BasicTreasuresRewardPool;
				TempReward.Name = "First Pool";
				TempReward.RewardContainer = "SeaChest";
				TempReward.Rewards.Insert(new BasicTreasuresReward("M4A1", {"M4_RISHndgrd", "M4_OEBttstck", "M68Optic"}));
				TempReward.Rewards.Insert(new BasicTreasuresReward("PlateCarrierVest", {"PlateCarrierHolster"}));
				TempReward.Rewards.Insert(new BasicTreasuresReward("Mag_STANAGCoupled_30Rnd", {}));
				TempReward.Rewards.Insert(new BasicTreasuresReward("Mag_STANAGCoupled_30Rnd", {}));
				TempReward.Rewards.Insert(new BasicTreasuresReward("NVGoggles", {"Battery9V"}));
				RewardPools.Insert(TempReward);
				Save();
			}
		}
	}
	
	void Save(){
			JsonFileLoader<BasicTreasuresConfig>.JsonSaveFile(ConfigPATH, this);
	}
	
	BasicTreasuresRewardPool GetRandomRewardPool(){
		return RewardPools.GetRandomElement();
	}
	
}

class BasicTreasuresRewardPool {
	string Name;
	string RewardContainer;
	ref array<ref BasicTreasuresReward> Rewards = new array<ref BasicTreasuresReward>;
	
	void BasicTreasuresRewardPool( )
	{
		
	}
};

class BasicTreasuresReward {
	string Item;
	ref TStringArray ItemAttachments;
	
	void BasicTreasuresReward( string item, ref TStringArray itemAttachments)
	{
		Item = item;
		ItemAttachments = itemAttachments;
	}
};

ref BasicTreasuresConfig m_BasicTreasuresConfig;

//Helper function to return Config
static ref BasicTreasuresConfig GetBasicTreasuresConfig()
{
	if (!m_BasicTreasuresConfig)
	{
		m_BasicTreasuresConfig = new BasicTreasuresConfig;
			
		if ( GetGame().IsServer() ){
			m_BasicTreasuresConfig.Load();
		}
	}
	return m_BasicTreasuresConfig;
};