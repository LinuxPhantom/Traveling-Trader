modded class MissionServer
{

    RTTConfigData m_RTTConfigData;
    ref array<RTTraderDataCfg> m_RTTraderData;

    void MissionServer()
    {
        GetRTTConfig();
    }

    override void OnInit()
	{		
		super.OnInit();
        m_RTTConfigData = GetRTTConfig().GetConfigData();
        m_RTTraderData = m_RTTConfigData.GetRTTraderData();
        for (int it = 0; it <  m_RTTraderData.Count(); it++)
		{
            int time = m_RTTraderData.Get(it).GetMoveTime();
		    GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(RandomTrader, time, true, it);
        }
	}

    void RandomTrader(int traderIdentifier)
    {
        Print("asdasdasdasdasds");
        RTTraderDataCfg trader = m_RTTraderData.Get(traderIdentifier);
        string m_RTraderMoveMessage = trader.GetMoveMessage();
        int ID = trader.GetID();
        ref array<vector> m_RTraderPosition = trader.GetPosition();
        ref array<vector> m_RTraderOrientation = trader.GetOrientation();
        int ROldRandomNumber = -1;
        Print(m_RTraderPosition);
        int RCount = m_RTraderPosition.Count();
        int RrandNum = Math.RandomInt(0, RCount);

        if (ROldRandomNumber != -1 && ROldRandomNumber == RrandNum)
        {
            while (ROldRandomNumber == RrandNum)
            {
                RrandNum = Math.RandomInt(0, RCount);
            }
        }

        for (int tid = 0; tid <  m_Trader_TraderIDs.Count(); tid++)
		{
            if (m_Trader_TraderIDs.Get(tid) == ID) 
                ID = tid;
		}

        PlayerBase RTraderMan = m_Trader_SpawnedTraderCharacters[ID];

        vector RPosition = m_RTraderPosition.Get(RrandNum);
        Print(RPosition);
        
        m_Trader_TraderPositions[ID] = RPosition;
		RTraderMan.SetPosition(RPosition);
        RTraderMan.SetOrientation(m_RTraderOrientation.Get(RrandNum));

        for (int j = 0; j < m_Players.Count(); j++)
		{
            PlayerBase player = PlayerBase.Cast(m_Players.Get(j));

            player.m_Trader_RecievedAllData = false;
            
            Param1<string> m_GlobalMessage = new Param1<string>(m_RTraderMoveMessage); 
		    GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, m_GlobalMessage, true, player.GetIdentity());
        }
        ROldRandomNumber = RrandNum;
    }

    void UpdateToPlayerTraderData(PlayerBase player)
    {
        for (int it = 0; it <  m_RTTraderData.Count(); it++)
		{
            RTTraderDataCfg traderData = m_RTTraderData.Get(it);
            m_Trader_TraderPositions[traderData.GetID()] = traderData.GetPosition();
            player.m_Trader_RecievedAllData = false;
		}
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        if(player)
        {
            UpdateToPlayerTraderData(player);
        }
        super.InvokeOnConnect(player,identity)
    }

    override void OnClientRespawnEvent(PlayerIdentity identity, PlayerBase player)
    {
        if(player)
        {
            UpdateToPlayerTraderData(player);
        }
        super.OnClientRespawnEvent(identity,player);
    }

    void OnClientReconnectEvent(PlayerIdentity identity, PlayerBase player)
    {
        if ( player )
        {
            UpdateToPlayerTraderData(player);
        }
        super.OnClientReconnectEvent(identity,player);
    }

    override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
        for (int j = 0; j < m_Players.Count(); j++)
		{
			PlayerBase player = PlayerBase.Cast(m_Players.Get(j));
			
			if ( !player )
				continue;

            if (!player.m_Trader_RecievedAllData)
					sendTraderDataToPlayer(player);
        }
    }
}