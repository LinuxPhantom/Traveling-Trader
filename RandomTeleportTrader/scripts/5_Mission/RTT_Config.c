ref RTTConfig m_RTTConfig;
static const string RTT_CONFIG_FOLDER = "$profile:RandomTeleportTrader/";
static const string RTT_CONFIG_FILENAME = "config.json";

class RTTConfig
{
	protected static ref RTTConfigData m_RTTConfigData;
	
	void RTTConfig()
	{
		LoadConfig();
	};
	
	RTTConfigData GetConfigData()
	{
		if(!m_RTTConfigData) LoadConfig();
		
		return m_RTTConfigData;
	};
	
	protected void LoadConfig()
	{
		if(!FileExist(RTT_CONFIG_FOLDER)) MakeDirectory(RTT_CONFIG_FOLDER);
		
		m_RTTConfigData = new RTTConfigData();
		
		if(FileExist(RTT_CONFIG_FOLDER + RTT_CONFIG_FILENAME)) JsonFileLoader<RTTConfigData>.JsonLoadFile(RTT_CONFIG_FOLDER + RTT_CONFIG_FILENAME, m_RTTConfigData);
		else CreateDefaultConfig();
	};
	
	protected void CreateDefaultConfig()
	{
		m_RTTConfigData = new RTTConfigData();
		
		JsonFileLoader<RTTConfigData>.JsonSaveFile(RTT_CONFIG_FOLDER + RTT_CONFIG_FILENAME, m_RTTConfigData);
	};
};

class RTTraderDataCfg
{
    protected int ID;
    protected int MoveTime;
    protected string MoveMessage;
	protected ref array<string> Position;
    protected ref array<string> Orientation;

	void RTTraderDataCfg()
	{
		Position = new array<string>;
		Orientation = new array<string>;
	}
    
    int GetID()
	{
		return ID;
	};
    
    int GetMoveTime()
	{
		return MoveTime;
	};
    
    string GetMoveMessage()
	{
		return MoveMessage;
	};
	
    ref array<vector> GetPosition()
	{
        array<vector> rttpos = new array<vector>;
        for (int rti = 0; rti <  Position.Count(); rti++)
		{
			rttpos.Insert(Position.Get(rti).ToVector());
		}
		return rttpos;
	};

	ref array<vector> GetOrientation()
	{
        array<vector> rttori = new array<vector>;
        for (int rti = 0; rti <  Orientation.Count(); rti++)
		{
			rttori.Insert(Orientation.Get(rti).ToVector());
		}
		return rttori;
	};
}

class RTTConfigData
{
    protected ref array<RTTraderDataCfg> RTTraderData;
	
	void RTTConfigData()
	{
		RTTraderData = new array<RTTraderDataCfg>;
	};

	ref array<RTTraderDataCfg> GetRTTraderData()
	{
		return RTTraderData;
	};
};

ref RTTConfig GetRTTConfig()
{
	if(!m_RTTConfig) m_RTTConfig = new RTTConfig;
	return m_RTTConfig;
};