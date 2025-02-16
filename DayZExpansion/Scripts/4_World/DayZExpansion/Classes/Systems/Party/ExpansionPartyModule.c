/**
 * ExpansionPartyModule.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2021 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionPartyModule: JMModuleBase
{
	//! Server and client side
	private ref map<int, ref ExpansionPartyData> m_Parties;

	//! Client side
	private ref ExpansionPartyData m_Party;
	private ref array<ref ExpansionPartyInviteData> m_PartyInvites;
	private bool m_IsClientInitialized;

	int m_NextPartyID = 0;

	private const float UPDATE_TICK_TIME = 1.0;
	private const int UPDATE_PLAYERS_PER_TICK = 10;  //! Refresh up to 10 players every UPDATE_TICK_TIME seconds
	private float m_UpdateQueueTimer;
	private int m_CurrentPlayerTick;
	private int m_CurrentPartyTick;

	static ref ScriptInvoker m_PartyHUDInvoker = new ScriptInvoker();

	void ExpansionPartyModule()
	{
		//! Used server and client side
		m_Parties = new map<int, ref ExpansionPartyData>();

		//! Used only client side
		m_Party = NULL;
		m_PartyInvites = new array<ref ExpansionPartyInviteData>();
	}

	void ~ExpansionPartyModule()
	{
		ClearPlayerParty();
	}

	protected void ClearPlayerParty()
	{
		m_Parties.Clear();
		m_Party = NULL;
		m_PartyInvites.Clear();
	}

	override bool IsEnabled()
	{
		return (super.IsEnabled() && GetExpansionSettings().GetParty().EnableParties);
	}

	override void RegisterKeyMouseBindings()
	{
		super.RegisterKeyMouseBindings();

		RegisterBinding(new JMModuleBinding("Input_UpdateQuickMarker", "UAExpansionQuickMarker", true));
		RegisterBinding(new JMModuleBinding("Input_RemoveQuickMarker",	 "UAExpansionMapDeleteMarker", true));
	}

	override void OnMissionStart()
	{
		super.OnMissionStart();

		if (!IsMissionHost())
			return;

		if (!FileExist(EXPANSION_GROUPS_FOLDER))
			MakeDirectory(EXPANSION_GROUPS_FOLDER);

		map<string, ref ExpansionPartyData> partiesByPlayerUID = new map<string, ref ExpansionPartyData>;

		array<string> group_files = ExpansionStatic.FindFilesInLocation(EXPANSION_GROUPS_FOLDER, ".bin");
		foreach (string fileName : group_files)
		{
			ExpansionPartyData party = new ExpansionPartyData;
			FileSerializer file = new FileSerializer;

			if (file.Open(EXPANSION_GROUPS_FOLDER + fileName, FileMode.READ))
			{
				int version;
				if (Expansion_Assert_False(file.Read(version), "[" + this + ":" + fileName + "] Failed reading version"))
				{
					file.Close();
					continue;
				}

				if (party.OnStoreLoad(file, version))
				{
					party.InitMaps();
					m_Parties.Insert(party.GetPartyID(), party);

					if (m_NextPartyID <= party.GetPartyID())
					{
						m_NextPartyID = party.GetPartyID() + 1;
					}

					file.Close();

					//! Make sure each player can only have at most one party
					array<ref ExpansionPartyPlayerData> players = party.GetPlayers();
					foreach (ExpansionPartyPlayerData player : players)
					{
						if (!player)
							continue;

						ExpansionPartyData playerParty;
						if (partiesByPlayerUID.Find(player.GetID(), playerParty))
						{
							EXPrint(ToString() + "::OnMissionStart - WARNING: Removing player '" + player.GetName() + "' (id=" + player.GetID() + ") from group '" + party.GetPartyName() + "' (id=" + party.GetPartyID() + ") since they are already a member of group '" + playerParty.GetPartyName() + "' (id=" + playerParty.GetPartyID() + ")");
							if (player.GetID() == party.GetOwnerUID())
							{
								m_Parties.Remove(party.GetPartyID());
								party.Delete();
							}
							else
							{
								party.RemoveMember(player.GetID());
								party.Save();
							}
						}
						else
						{
							partiesByPlayerUID.Insert(player.GetID(), party);
						}
					}
				} else
				{
					Print("Failed loading group " + fileName);
					file.Close();
				}
			}
		}
	}

	override int GetRPCMin()
	{
		return ExpansionPartyModuleRPC.INVALID;
	}

	override int GetRPCMax()
	{
		return ExpansionPartyModuleRPC.COUNT;
	}

	#ifdef CF_BUGFIX_REF
	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	#else
	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ref ParamsReadContext ctx)
	#endif
	{
		switch (rpc_type)
		{
			case ExpansionPartyModuleRPC.CreateParty:
				RPC_CreatePartyServer(ctx, sender);
				break;
			case ExpansionPartyModuleRPC.DissolveParty:
				RPC_DissolvePartyServer(ctx, sender);
				break;
			case ExpansionPartyModuleRPC.LeaveParty:
				RPC_LeavePartyServer(ctx, sender);
				break;
			case ExpansionPartyModuleRPC.AcceptInvite:
				RPC_AcceptInviteServer(ctx, sender);
				break;
			case ExpansionPartyModuleRPC.RemovePartyMember:
				RPC_RemovePartyMemberServer(ctx, sender);
				break;
			case ExpansionPartyModuleRPC.UpdatePlayer:
				RPC_UpdatePlayerClient(ctx, sender);
				break;
			case ExpansionPartyModuleRPC.CreateMarker:
				RPC_CreateMarkerServer(ctx, sender);
				break;
			case ExpansionPartyModuleRPC.UpdateMarker:
				RPC_UpdateMarkerServer(ctx, sender);
				break;
			case ExpansionPartyModuleRPC.UpdatePositionMarker:
				RPC_UpdatePositionMarkerServer(ctx, sender);
				break;
			case ExpansionPartyModuleRPC.DeleteMarker:
				RPC_DeleteMarkerServer(ctx, sender);
				break;
			case ExpansionPartyModuleRPC.InvitePlayer:
				RPC_InvitePlayerServer(ctx, sender);
				break;
			case ExpansionPartyModuleRPC.DeclineInvite:
				RPC_DeclineInviteServer(ctx, sender);
				break;
			case ExpansionPartyModuleRPC.SyncPlayerInvites:
				RPC_SyncPlayerInvitesClient(ctx, sender);
				break;
			case ExpansionPartyModuleRPC.UpdateQuickMarker:
				RPC_UpdateQuickMarkerServer(ctx, sender);
				break;
			case ExpansionPartyModuleRPC.UpdatePermissions:
				RPC_UpdatePermissionsServer(ctx, sender);
				break;
		}
	}

	void SyncPlayerInvitesServer(notnull PlayerBase sender)
	{
		if (!IsMissionHost() || !sender || !sender.GetIdentity())
			return;

		array<ref ExpansionPartyInviteData> invites = new array<ref ExpansionPartyInviteData>();

		foreach (int i, ExpansionPartyData data : m_Parties)
		{
			ExpansionPartyInviteData invite = data.GetPlayerInvite(sender.GetIdentityUID());
			if (invite)
				invites.Insert(invite);
		}

		ScriptRPC rpcServer = new ScriptRPC();
		rpcServer.Write(invites);
		rpcServer.Send(NULL, ExpansionPartyModuleRPC.SyncPlayerInvites, true, sender.GetIdentity());
	}

	private void RPC_SyncPlayerInvitesClient(ParamsReadContext ctx, PlayerIdentity senderRPC)
	{
		if (Expansion_Assert_False(ctx.Read(m_PartyInvites), "[" + this + "] Failed reading invites"))
			return;

		UpdateMenu();
	}

	void CreateParty(string partyName)
	{
		if (Expansion_Assert_False(IsMissionClient(), "[" + this + "] CreateParty shall only be called on client!"))
			return;

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(partyName);
		rpc.Send(NULL, ExpansionPartyModuleRPC.CreateParty, true, NULL);
	}

	private void RPC_CreatePartyServer(ParamsReadContext ctx, PlayerIdentity sender)
	{
		string partyName;
		if (!ctx.Read(partyName))
			return;

		PlayerBase player = PlayerBase.GetPlayerByUID(sender.GetId());
		if (!player)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_PLAYERBASE").Error(sender);
			return;
		}

		if (HasParty(player))
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_IN_PARTY").Error(sender);
			return;
		}

		ExpansionPartyData newParty = new ExpansionPartyData(m_NextPartyID);
		newParty.SetupExpansionPartyData(player, partyName);
		newParty.Save();

		m_Parties.Insert(m_NextPartyID, newParty);

		UpdatePartyMembersServer(m_NextPartyID++);

		if (GetExpansionSettings().GetLog().Party)
			GetExpansionSettings().GetLog().PrintLog("[Party] Player \"" + sender.GetName() + "\" (id=" + sender.GetId() + ")" + " created a party named " + partyName);

		ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_SYSTEM_PARTY_CREATED").Success(sender);
	}

	void LeaveParty()
	{
		if (Expansion_Assert_False(IsMissionClient(), "[" + this + "] LeaveParty shall only be called on client!"))
			return;

		ScriptRPC rpc = new ScriptRPC();
		rpc.Send(NULL, ExpansionPartyModuleRPC.LeaveParty, true, NULL);
	}

	private void RPC_LeavePartyServer(ParamsReadContext ctx, PlayerIdentity sender)
	{
		if (!sender)
			return;

		PlayerBase player = PlayerBase.GetPlayerByUID(sender.GetId());
		if (!player)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_PLAYERBASE").Error(sender);
			return;
		}

		int partyId = GetPartyID(player);

		ExpansionPartyData party = m_Parties.Get(partyId);
		if (!party || partyId == -1)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_NOT_EXIST").Error(sender);
			return;
		}

		if (party.GetOwnerUID() == sender.GetId())
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_UNKNOWN").Error(sender);
			return;
		}

		if (!party.RemoveMember(sender.GetId()))
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_SELF_NOT_IN").Error(sender);
			return;
		}

		party.Save();

		//! Update remaining party members
		UpdatePartyMembersServer(partyId);

		//! Update player that has left the party
		UpdatePlayerServer(NULL, player);

		ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_LEFT").Success(sender);

		SendNotificationToMembers(new StringLocaliser("STR_EXPANSION_PARTY_LEFT_MEMBERS", sender.GetName()), party, sender);
	}

	void DissolveParty()
	{
		if (Expansion_Assert_False(IsMissionClient(), "[" + this + "] DissolveParty shall only be called on client!"))
			return;

		ScriptRPC rpc = new ScriptRPC();
		rpc.Send(NULL, ExpansionPartyModuleRPC.DissolveParty, true);
	}

	private void RPC_DissolvePartyServer(ParamsReadContext ctx, PlayerIdentity sender)
	{
		if (!sender)
			return;

		PlayerBase player = PlayerBase.GetPlayerByUID(sender.GetId());
		if (!player)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_PLAYERBASE").Error(sender);
			return;
		}

		int partyId = GetPartyID(player);

		ExpansionPartyData party = m_Parties.Get(partyId);
		if (!party || partyId == -1)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_NOT_EXIST").Error(sender);
			return;
		}

		string senderID = sender.GetId();
		ExpansionPartyPlayerData senderPlayer = party.GetPlayer(senderID);
		if (!senderPlayer)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_NOT_EXIST").Error(sender);
			return;
		}

		if (!senderPlayer.CanDelete())
			return;

		#ifdef EXPANSIONMODMARKET
		//! Add all the money in the party deposit to the party owners deposit
		if (party.GetMoneyDeposited() > 0)
		{
			ExpansionMarketModule module = ExpansionMarketModule.Cast(GetModuleManager().GetModule(ExpansionMarketModule));
			if (module)
			{
				ExpansionMarketATM_Data data = module.GetPlayerATMData(party.GetOwnerUID());
				if (!data)
				{
					Error("ExpansionPartyModule::Exec_DissolvePartyServer - Could not get party owners ATM data!");
					return;
				}

				data.AddMoney(party.GetMoneyDeposited());
				data.Save();
			}
		}
		#endif

		if (!DeletePartyServer(party))
		{
			Error("ExpansionPartyModule::Exec_DissolvePartyServer - Could not get delete party from party module parties array!");
		}
	}

	bool DeletePartyServer(notnull ExpansionPartyData party)
	{
		array<ref ExpansionPartyPlayerData> players = party.GetPlayers();
		foreach (ExpansionPartyPlayerData currPlayer : players)
		{
			if (!currPlayer)
			{
				Error("ExpansionPartyModule::DeletePartyServer - party member player data is NULL!");
				continue;
			}

			PlayerBase partyPlayer = PlayerBase.GetPlayerByUID(currPlayer.UID);
			if (partyPlayer && partyPlayer.GetIdentity())
			{
				UpdatePlayerServer(NULL, partyPlayer);
				ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_PARTY_DISSOLVED").Success(partyPlayer.GetIdentity());
			}
		}

		m_Parties.Remove(party.GetPartyID());
		party.Delete();

		return true;
	}

	bool DeletePartyServer(int partyID)
	{
		ExpansionPartyData party = m_Parties.Get(partyID);

		if (!party)
		{
			Error("[" + this + "] Party " + partyID + " does not exist!");
			return false;
		}

		return DeletePartyServer(party);
	}

	void InvitePlayer(string sendID)
	{
		if (Expansion_Assert_False(IsMissionClient(), "[" + this + "] InvitePlayer shall only be called on client!"))
			return;

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(sendID);
		rpc.Send(NULL, ExpansionPartyModuleRPC.InvitePlayer, true, NULL);
	}

	private void RPC_InvitePlayerServer(ParamsReadContext ctx, PlayerIdentity sender)
	{
		string targetID;
		if ( !ctx.Read( targetID ) )
			return;

		PlayerBase senderPlayer = PlayerBase.GetPlayerByUID(sender.GetId());
		PlayerBase targetPlayer = PlayerBase.GetPlayerByUID(targetID);

		if (!senderPlayer || !targetPlayer)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_PLAYERBASE").Error(sender);
			return;
		}

		int partyId = GetPartyID(senderPlayer);
		ExpansionPartyData party = m_Parties.Get(partyId);
		if (!party || partyId == -1)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_NOT_EXIST").Error(sender);
			return;
		}

		ExpansionPartyPlayerData senderPlayerParty = party.GetPlayer(sender.GetId());
		if (!senderPlayerParty || !senderPlayerParty.CanInvite())
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_NOT_OWNER").Error(sender);
			return;
		}

		if (GetExpansionSettings().GetParty().MaxMembersInParty >= 1 && party.GetPlayers().Count() >= GetExpansionSettings().GetParty().MaxMembersInParty)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", new StringLocaliser("STR_EXPANSION_PARTY_ERROR_MAX_PARTY", GetExpansionSettings().GetParty().MaxMembersInParty.ToString())).Error(sender);
			return;
		}

		if (party.HasPlayerInvite(targetID))
		{
			SyncPlayerInvitesServer(targetPlayer);
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_INVITED").Error(sender);
			return;
		}

		ExpansionPartyInviteData invite = party.AddInvite(targetID);
		if (invite == NULL)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_INVITE").Error(sender);
			return;
		}

		party.Save();

		UpdatePartyMembersServer(partyId);

		SyncPlayerInvitesServer(targetPlayer);

		if (GetExpansionSettings().GetLog().Party)
			GetExpansionSettings().GetLog().PrintLog("[Party] Player \"" + sender.GetName() + "\" (id=" + sender.GetId() + ")" + " invited the player \"" + targetPlayer.GetIdentity().GetName() + "\" (id=" + targetPlayer.GetIdentity().GetId() + ")" + "to the party named " + party.GetPartyName());

		StringLocaliser title = new StringLocaliser("STR_EXPANSION_PARTY_NOTIF_TITLE");
		StringLocaliser text_reciver = new StringLocaliser("STR_EXPANSION_PARTY_INVITED", party.GetPartyName());
		StringLocaliser text_sender = new StringLocaliser("STR_EXPANSION_PARTY_INVITED_SENDER",  targetPlayer.GetIdentity().GetName());

		ExpansionNotification(title, text_reciver).Success(targetPlayer.GetIdentity());
		ExpansionNotification(title, text_sender).Success(sender);
	}

	void DeclineInvite(int partyID)
	{
		if (Expansion_Assert_False(IsMissionClient(), "[" + this + "] DeclineInvite shall only be called on client!"))
			return;

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(partyID);
		rpc.Send(NULL, ExpansionPartyModuleRPC.DeclineInvite, true, NULL);
	}

	private void RPC_DeclineInviteServer(ParamsReadContext ctx, PlayerIdentity sender)
	{
		int partyID;
		if (!ctx.Read(partyID))
			return;

		PlayerBase senderPlayer = PlayerBase.GetPlayerByUID(sender.GetId());
		if (!senderPlayer)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_PLAYERBASE").Error(sender);
			return;
		}

		ExpansionPartyData party = m_Parties.Get(partyID);
		if (!party)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_NOT_EXIST").Error(sender);
			return;
		}

		if (!party.DeclineInvite(sender.GetId()))
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_PLAYER_NOT_IN").Error(sender);
			return;
		}

		party.Save();

		UpdatePartyMembersServer(partyID);

		SyncPlayerInvitesServer(senderPlayer);

		ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", new StringLocaliser("STR_EXPANSION_PARTY_INVITE_DECLINED", party.GetPartyName())).Success(sender);
	}

	void AcceptInvite(int partyID)
	{
		if (Expansion_Assert_False(IsMissionClient(), "[" + this + "] AcceptInvite shall only be called on client!"))
			return;

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(partyID);
		rpc.Send(NULL, ExpansionPartyModuleRPC.AcceptInvite, true, NULL);
	}

	private void RPC_AcceptInviteServer(ParamsReadContext ctx, PlayerIdentity sender)
	{
		if (!IsMissionHost())
			return;

		int partyID;
		if (!ctx.Read(partyID))
			return;

		PlayerBase senderPlayer = PlayerBase.GetPlayerByUID(sender.GetId());
		if (!senderPlayer)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_PLAYERBASE").Error(sender);
			return;
		}

		ExpansionPartyData party = m_Parties.Get(partyID);
		if (!party)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_NOT_EXIST").Error(sender);
			return;
		}

		if (party.IsMember(sender.GetId()))
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_NOT_EXIST").Error(sender);
			return;
		}

		if (HasParty(senderPlayer))
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_IN_PARTY").Error(sender);
			return;
		}

		if (GetExpansionSettings().GetParty().MaxMembersInParty >= 1 && party.GetPlayers().Count() >= GetExpansionSettings().GetParty().MaxMembersInParty)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", new StringLocaliser("STR_EXPANSION_PARTY_ERROR_MAX_PARTY", GetExpansionSettings().GetParty().MaxMembersInParty.ToString())).Error(sender);
			return;
		}

		if (!party.AcceptInvite(senderPlayer))
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", new StringLocaliser("Something went wrong! Could not accept party invite!")).Error(sender);
			return;
		}

		//! Save the party changes (AcceptInvite already removed the invite)
		party.Save();

		ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_MEMBER_ADDED").Success(sender);

		//! Inform all party members that a new player joined
		UpdatePartyMembersServer(partyID);

		SyncPlayerInvitesServer(senderPlayer);

		SendNotificationToMembers(new StringLocaliser("STR_EXPANSION_PARTY_MEMBER_ADDED_SENDER", sender.GetName()), party, sender);
	}

	void RemovePartyMember(string uid)
	{
		if (Expansion_Assert_False(IsMissionClient(), "[" + this + "] RemovePartyMember shall only be called on client!"))
			return;

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(uid);
		rpc.Send(NULL, ExpansionPartyModuleRPC.RemovePartyMember, true, NULL);
	}

	private void RPC_RemovePartyMemberServer(ParamsReadContext ctx, PlayerIdentity sender)
	{
		string uid;
		if (!ctx.Read(uid))
			return;

		PlayerBase senderPlayer = PlayerBase.GetPlayerByUID( sender.GetId() );
		if (!senderPlayer)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_PLAYERBASE").Error(sender);
			return;
		}

		int partyId = GetPartyID(senderPlayer);
		ExpansionPartyData party = m_Parties.Get(partyId);
		if (!party || partyId == -1)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_NOT_EXIST").Error(sender);
			return;
		}

		ExpansionPartyPlayerData senderPartyMember = party.GetPlayer(sender.GetId());
		if (!senderPartyMember.CanKick())
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_NOT_OWNER").Error(sender);
			return;
		}

		if (party.GetOwnerUID() == uid)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_REMOVE_OWNER").Error(sender);
			return;
		}

		if (!party.RemoveMember(uid))
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_PLAYER_NOT_IN").Error(sender);
			return;
		}

		party.Save();

		//! Update remaining party members
		UpdatePartyMembersServer(partyId);

		PlayerBase targetPlayer = PlayerBase.GetPlayerByUID(uid);
		PlayerIdentity targetIdentity;

		if (targetPlayer)
		{
			targetIdentity = targetPlayer.GetIdentity();

			//! Update player that was removed from party
			UpdatePlayerServer(NULL, targetPlayer);

			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_MEMBER_REMOVED").Success(targetPlayer.GetIdentity());
		}

		SendNotificationToMembers(new StringLocaliser("STR_EXPANSION_PARTY_MEMBER_REMOVED_SENDER"), party, targetIdentity);
	}

	//! Update all members of a party
	void UpdatePartyMembersServer(notnull ExpansionPartyData party)
	{
		if (Expansion_Assert_False(IsMissionHost(), "[" + this + "] UpdatePartyMembersServer shall only be called on server!"))
			return;

		array<ref ExpansionPartyPlayerData> players = party.GetPlayers();
		if (!players)
			return;

		for (int i = 0; i < players.Count(); i++)
		{
			ExpansionPartyPlayerData playerData = players[i];
			if (!playerData)
				continue;

			PlayerBase player = PlayerBase.GetPlayerByUID(playerData.UID);

			if (!player)
				continue;

			UpdatePlayerServer(party, player);
		}
	}

	void UpdatePartyMembersServer(int partyId)
	{
		ExpansionPartyData party = m_Parties.Get(partyId);
		UpdatePartyMembersServer(party);
	}

	bool OnReceivePartyClient(ParamsReadContext ctx, out ExpansionPartyData party)
	{
		int id;
		if (Expansion_Assert_False(ctx.Read(id), "Failed to read party ID"))
			return false;

		party = m_Parties.Get(id);
		if (!party)
		{
			party = new ExpansionPartyData( id );
			m_Parties.Insert( id, party );
		}

		if (Expansion_Assert_False(party.OnRecieve(ctx), "Failed to read party"))
			return false;

		return true;
	}

	void UpdatePlayerServer(int partyId, PlayerBase player)
	{
		ExpansionPartyData party = m_Parties.Get(partyId);
		UpdatePlayerServer(party, player);
	}

	void UpdatePlayerServer(ExpansionPartyData party, notnull PlayerIdentity identity)
	{
		if (Expansion_Assert_False(IsMissionHost(), "[" + this + "] UpdatePlayerServer shall only be called on server!"))
			return;

		string playerID = identity.GetId();
		ScriptRPC rpc = new ScriptRPC();
		if (party && party.IsMember(playerID))
		{
			rpc.Write(true);
			party.OnSend(rpc, true, playerID);
		}
		else
		{
			rpc.Write(false);
		}

		rpc.Send(null, ExpansionPartyModuleRPC.UpdatePlayer, true, identity);
	}

	void UpdatePlayerServer(ExpansionPartyData party, PlayerBase player)
	{
		if (!player || !player.GetIdentity())
			return;

		UpdatePlayerServer(party, player.GetIdentity());
	}

	private void RPC_UpdatePlayerClient(ParamsReadContext ctx, PlayerIdentity senderRPC)
	{
		bool hasParty = false;
		if (!ctx.Read(hasParty))
		{
			Error("ExpansionPartyModule::RPC_UpdatePlayerClient can't read hasParty");
			return;
		}

		if (hasParty)
		{
			if (!OnReceivePartyClient(ctx, m_Party))
			{
				Error("ExpansionPartyModule::RPC_UpdatePlayerClient can't read party");
				return;
			}
		}
		else
		{
			ClearPlayerParty();
		}

		m_IsClientInitialized = true;

		ExpansionMarkerModule module;
		if (Class.CastTo(module, GetModuleManager().GetModule(ExpansionMarkerModule)))
		{
			module.Refresh();
		}

		UpdateMenu();

		#ifdef EXPANSIONMOD_PARTYHUD_ENABLE
		if (GetExpansionSettings().GetParty().ShowPartyMemberHUD)
		{
			m_PartyHUDInvoker.Invoke();
		}
		#endif
	}

	void CreateMarker(ExpansionMarkerData marker)
	{
		if (Expansion_Assert_False(IsMissionClient(), "[" + this + "] CreateMarker shall only be called on client!"))
			return;
		
		ScriptRPC rpc = new ScriptRPC();
		marker.OnSend(rpc);
		rpc.Send(NULL, ExpansionPartyModuleRPC.CreateMarker, true, NULL);
	}

	private void RPC_CreateMarkerServer(ParamsReadContext ctx, PlayerIdentity sender)
	{
		ExpansionMarkerData marker = ExpansionMarkerData.Create(ExpansionMapMarkerType.PARTY);
		if (!marker.OnRecieve(ctx))
			return;

		PlayerBase senderPlayer = PlayerBase.GetPlayerByUID(sender.GetId());
		if (!senderPlayer)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_PLAYERBASE").Error(sender);
			return;
		}

		int partyId = GetPartyID(senderPlayer);
		ExpansionPartyData party = m_Parties.Get(partyId);
		if (!party || partyId == -1)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_NOT_EXIST").Error(sender);
			return;
		}

		party.AddMarker(marker);
		party.Save();

		ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_MARKER_ADDED").Success(sender);

		UpdatePartyMembersServer(partyId);
	}

	void UpdateMarker(ExpansionMarkerData marker)
	{
		if (Expansion_Assert_False(IsMissionClient(), "[" + this + "] UpdateMarker shall only be called on client!"))
			return;

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(marker.GetUID());
		marker.OnSend(rpc);
		rpc.Send(NULL, ExpansionPartyModuleRPC.UpdateMarker, true, NULL);
	}

	private void RPC_UpdateMarkerServer(ParamsReadContext ctx, PlayerIdentity senderRPC)
	{
		string uid;
		if (!ctx.Read(uid))
			return;

		PlayerBase senderPlayer = PlayerBase.GetPlayerByUID(senderRPC.GetId());
		if (!senderPlayer)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_PLAYERBASE").Error(senderRPC);
			return;
		}

		int partyId = GetPartyID(senderPlayer);
		ExpansionPartyData party = m_Parties.Get(partyId);
		if (!party || partyId == -1)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_NOT_EXIST").Error(senderRPC);
			return;
		}

		ExpansionMarkerData marker = party.GetMarker(uid);
		if (!marker.OnRecieve(ctx))
			return;

		party.UpdateMarker(marker);
		party.Save();

		ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_MARKER_ADDED").Success(senderRPC);

		UpdatePartyMembersServer(partyId);
	}

	void DeleteMarker(string uid)
	{
		if (Expansion_Assert_False(IsMissionClient(), "[" + this + "] DeleteMarker shall only be called on client!"))
			return;

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(uid);
		rpc.Send(NULL, ExpansionPartyModuleRPC.DeleteMarker, true, NULL);
	}

	private void RPC_DeleteMarkerServer(ParamsReadContext ctx, PlayerIdentity sender)
	{
		string uid;
		if (!ctx.Read(uid))
			return;

		PlayerBase senderPlayer = PlayerBase.GetPlayerByUID(sender.GetId());
		if (!senderPlayer)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_PLAYERBASE").Error(sender);
			return;
		}

		int partyId = GetPartyID(senderPlayer);
		ExpansionPartyData party = m_Parties.Get(partyId);
		if (!party || partyId == -1)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_NOT_EXIST").Error(sender);
			return;
		}

		if (party.RemoveMarker(uid))
		{
			party.Save();

			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_MARKER_REMOVED").Success(sender);

			UpdatePartyMembersServer(partyId);
		} else
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "Could not remove party marker!").Error(sender);
		}
	}

	void UpdatePositionMarker(string uid, vector position)
	{
		if (Expansion_Assert_False(IsMissionClient(), "[" + this + "] UpdatePositionMarker shall only be called on client!"))
			return;

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(uid);
		rpc.Write(position);
		rpc.Send(NULL, ExpansionPartyModuleRPC.UpdatePositionMarker, true, NULL);
	}

	private void RPC_UpdatePositionMarkerServer(ParamsReadContext ctx, PlayerIdentity sender)
	{
		string uid;
		if (!ctx.Read(uid))
			return;

		vector position;
		if (!ctx.Read(position))
			return;

		if (!sender) return;

		PlayerBase senderPlayer = PlayerBase.GetPlayerByUID(sender.GetId());
		if (!senderPlayer)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_PLAYERBASE").Error(sender);
			return;
		}

		int partyId = GetPartyID(senderPlayer);
		ExpansionPartyData party = m_Parties.Get(partyId);
		if (!party || partyId == -1)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_NOT_EXIST").Error(sender);
			return;
		}

		if (party.UpdateMarkerPosition(uid, position))
		{
			party.Save();

			UpdatePartyMembersServer(partyId);

			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_MARKER_CHANGED").Success(sender);
			SendNotificationToMembers(new StringLocaliser("STR_EXPANSION_PARTY_MARKER_CHANGED"), party, sender);
		} else
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "Could not update party marker!").Error(sender);
		}
	}

	void UpdateQuickMarker(vector pos)
	{
		if (Expansion_Assert_False(IsMissionClient(), "[" + this + "] UpdateQuickMarker shall only be called on client!"))
			return;

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(pos);
		rpc.Send(NULL, ExpansionPartyModuleRPC.UpdateQuickMarker, true);
	}

	private void RPC_UpdateQuickMarkerServer(ParamsReadContext ctx, PlayerIdentity sender)
	{
		vector position;
		if (!ctx.Read(position))
			return;

		PlayerBase senderPlayer = PlayerBase.GetPlayerByUID(sender.GetId());
		if (!senderPlayer)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_PLAYERBASE").Error(sender);
			return;
		}

		int partyId = GetPartyID(senderPlayer);
		ExpansionPartyData party = m_Parties.Get(partyId);
		if (!party || partyId == -1)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_NOT_EXIST").Error(sender);
			return;
		}

		ExpansionPartyPlayerData senderPlayerParty = party.GetPlayer(sender.GetId());
		if (!senderPlayerParty)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_NOT_EXIST").Error(sender);
			return;
		}

		senderPlayerParty.SetQuickMarker(position);
		UpdatePartyMembersServer(party);
	}

	void UpdatePermissions(string memberID, ExpansionPartyPlayerPermissions perm)
	{
		if (Expansion_Assert_False(IsMissionClient(), "[" + this + "] UpdatePermissions shall only be called on client!"))
			return;

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(memberID);
		rpc.Write(perm);
		rpc.Send(NULL, ExpansionPartyModuleRPC.UpdatePermissions, true);
	}

	private void RPC_UpdatePermissionsServer(ParamsReadContext ctx, PlayerIdentity sender)
	{
		string memberID;
		if (!ctx.Read(memberID))
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "Could not get player's ID!").Error(sender);
			return;
		}

		ExpansionPartyPlayerPermissions perm;
		if (!ctx.Read(perm))
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "Could not get player's party player permissions data!").Error(sender);
			return;
		}

		PlayerBase senderPlayer = PlayerBase.GetPlayerByUID(sender.GetId());
		if (!senderPlayer)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_ERROR_PLAYERBASE").Error(sender);
			return;
		}

		int partyId = GetPartyID(senderPlayer);
		ExpansionPartyData senderParty = m_Parties.Get(partyId);
		if (!senderParty || partyId == -1)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "Could not get player's party data!").Error(sender);
			return;
		}

		ExpansionPartyPlayerData memberPartyPlayer = senderParty.GetPlayer(memberID);
		if (!memberPartyPlayer)
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "Could not get member's party player data!").Error(sender);
			return;
		}

		if (!perm)
			return;

		if (!senderParty)
			return;

		if (!sender)
			return;

		memberPartyPlayer.ApplyPermissions(perm);
		senderParty.Save();

		UpdatePartyMembersServer(senderParty);

		string title = "STR_EXPANSION_PARTY_NOTIF_TITLE";
		StringLocaliser text_sender = new StringLocaliser("STR_EXPANSION_PARTY_PERMISSIONS_CHANGED_SENDER", memberPartyPlayer.GetName());

		//! Send notification to player who changed permissions
		ExpansionNotification(title, text_sender).Success(sender);

		//! Send notification to player whose permissions were changed (if online)
		PlayerBase memberPlayer = PlayerBase.GetPlayerByUID(memberID);
		if (memberPlayer)
			ExpansionNotification(title, "STR_EXPANSION_PARTY_PERMISSIONS_CHANGED_RECIVER").Success(memberPlayer.GetIdentity());
	}

	override void OnMissionFinish()
	{
		//! Clean-up needed on client
		ClearPlayerParty();

		m_IsClientInitialized = false;
	}

	//! OnClientDisconnect is called on each disconnect
	override void OnClientDisconnect(PlayerBase player, PlayerIdentity identity, string uid)
	{
		//EXPrint(ToString() + "::OnClientDisconnect " + identity.GetId());

		if (!IsMissionHost())
			return;

		if (!player || !identity)
			return;

		ExpansionPartyPlayerData party_player = UpdatePlayerPartyServer(identity.GetId());

		if (party_player)
		{
			party_player.OnLeave();
			party_player.GetParty().OnLeave(party_player);
		}
	}

	//! OnInvokeConnect is called on each connect, reconnect, and respawn
	override void OnInvokeConnect(PlayerBase player, PlayerIdentity identity)
	{
		EXPrint(ToString() + "::OnInvokeConnect " + identity.GetId());

		if (!IsMissionHost())
			return;

		if (!player || !identity)
			return;

		SyncPlayerInvitesServer(player);

		ExpansionPartyPlayerData party_player = UpdatePlayerPartyServer(identity.GetId());

		if (party_player)
		{
			party_player.OnJoin(player);
			party_player.GetParty().OnJoin(party_player);
		}
	}

	private ExpansionPartyPlayerData UpdatePlayerPartyServer(string uid)
	{
		foreach (int i, ExpansionPartyData data : m_Parties)
		{
			ExpansionPartyPlayerData party_player = data.GetPlayer(uid);
			if (!party_player)
				continue;

			UpdatePartyMembersServer(data);

			return party_player;
		}

		return NULL;
	}

	void Input_UpdateQuickMarker(UAInput input)
	{
		if (!(input.LocalPress()))
			return;

		if (!GetExpansionSettings().GetParty().EnableQuickMarker)
			return;

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (!player || !m_Party)
			return;

		if (!GetExpansionSettings().GetParty() || !GetExpansionSettings().GetParty().EnableQuickMarker)
			return;

		vector pos = vector.Zero;

		vector rayStart = GetGame().GetCurrentCameraPosition();
		vector rayEnd = rayStart + GetGame().GetCurrentCameraDirection() * 10000;
		vector hitPos;
		vector hitNormal;
		int hitComponentIndex;

		if (DayZPhysics.RaycastRV(rayStart, rayEnd, hitPos, hitNormal, hitComponentIndex, null, null, player, false, false))
		{
			pos = hitPos;
		}

		UpdateQuickMarker(pos);
	}

	void Input_RemoveQuickMarker(UAInput input)
	{
		if (!(input.LocalPress()))
			return;

		if (!GetExpansionSettings().GetParty().EnableQuickMarker)
			return;

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (!player || !m_Party)
			return;

		if (!GetExpansionSettings().GetParty() || !GetExpansionSettings().GetParty().EnableQuickMarker)
			return;

		if (GetGame().GetUIManager().FindMenu(MENU_EXPANSION_MAP))
			return;

		UpdateQuickMarker(vector.Zero);
	}

	//! Send notification with given StringLocaliser data to all other active members of the given party
	void SendNotificationToMembers(StringLocaliser text, ExpansionPartyData party, PlayerIdentity sender)
	{
		array<ref ExpansionPartyPlayerData> players = party.GetPlayers();
	   	if ( !players )
			return;

		foreach (ExpansionPartyPlayerData playerData : players)
		{
			if (!playerData)
				continue;

			PlayerBase partyPlayer = PlayerBase.GetPlayerByUID(playerData.UID);
			if (partyPlayer && partyPlayer.GetIdentity())
			{
				if (partyPlayer.GetIdentityUID() != sender.GetId())
				{
					ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", text).Success(partyPlayer.GetIdentity());
				}
			}
		}
	}

	bool HasParty()
	{
		if (Expansion_Assert_False(IsMissionClient(), "[" + this + "] HasParty without player argument shall only be called on client!"))
			return false;

		return (m_Party != NULL);
	}

	bool HasParty(PlayerBase player)
	{
		if (Expansion_Assert_False(IsMissionHost(), "[" + this + "] HasParty with player argument shall only be called on server!"))
			return false;

		foreach (int i, ExpansionPartyData party : m_Parties)
		{
			if (party && party.GetPlayer(player.GetIdentityUID()))
				return true;
		}

		return false;
	}

	bool IsClientInitialized()
	{
		return m_IsClientInitialized;
	}

	int GetPartyID()
	{
		if (Expansion_Assert_False(IsMissionClient(), "[" + this + "] GetPartyID without player argument shall only be called on client!"))
			return -1;

		if (m_Party == NULL)
			return -1;

		return m_Party.GetPartyID();
	}

	int GetPartyID(notnull PlayerBase player)
	{
		if (Expansion_Assert_False(IsMissionHost(), "[" + this + "] GetPartyID with player argument shall only be called on server!"))
			return -1;

		string id = player.GetIdentityUID();

		if (!id)
			return -1;

		foreach (int i, ExpansionPartyData party : m_Parties)
		{
			if (party && party.GetPlayer(id))
				return party.GetPartyID();
		}

		return -1;
	}

	ExpansionPartyData GetParty()
	{
		if (Expansion_Assert_False(IsMissionClient(), "[" + this + "] GetPartyClient shall only be called on client!"))
			return NULL;

		return m_Party;
	}

	array<ref ExpansionPartyInviteData> GetPartyInvites()
	{
		if (Expansion_Assert_False(IsMissionClient(), "[" + this + "] GetPartyInvites shall only be called on client!"))
			return NULL;

		return m_PartyInvites;
	}

	bool HasInvites()
	{
		if (Expansion_Assert_False(IsMissionClient(), "[" + this + "] HasPartyInvites shall only be called on client!"))
			return false;

		return (m_PartyInvites && m_PartyInvites.Count() > 0);
	}

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		if (!IsMissionHost())
			return;

		m_UpdateQueueTimer += timeslice;
		if (m_UpdateQueueTimer >= UPDATE_TICK_TIME)
		{
			//! TODO: Currently, when a party marker is changed, all party markers are sent to party members.
			//! This could be optimized.

			if (m_Parties.Count() > 0)
			{
				int updatedParties;
				int updatedPlayers;

				while (updatedParties < m_Parties.Count())
				{
					if (m_CurrentPartyTick >= m_Parties.Count())
					{
						m_CurrentPartyTick = 0;
					}

					ExpansionPartyData party = m_Parties.GetElement(m_CurrentPartyTick);
					if (party.GetPlayers().Count() > 0)
					{
						if (m_CurrentPlayerTick >= party.GetPlayers().Count())
						{
							m_CurrentPlayerTick = 0;
						}

						if (m_CurrentPlayerTick == 0)
						{
							//! This is correct even if we do not update all party members this cycle
							updatedParties++;
						}

						while (updatedPlayers < UPDATE_PLAYERS_PER_TICK)
						{

							ExpansionPartyPlayerData playerData = party.GetPlayers()[m_CurrentPlayerTick];
							PlayerBase active_player = PlayerBase.GetPlayerByUID(playerData.UID);
							if (active_player && active_player.GetIdentity())
							{
								UpdatePlayerServer( party, active_player );
								updatedPlayers++;
							}

							m_CurrentPlayerTick++;

							if (m_CurrentPlayerTick == party.GetPlayers().Count())
							{
								break;
							}
						}
					} else
					{
						updatedParties++;
					}

					if (m_CurrentPlayerTick == party.GetPlayers().Count())
					{
						m_CurrentPartyTick++;
						m_CurrentPlayerTick = 0;
					}

					if (updatedPlayers == UPDATE_PLAYERS_PER_TICK)
					{
						break;
					}
				}
			}
			else
			{
				m_CurrentPartyTick = 0;
			}

			m_UpdateQueueTimer = 0.0;
		}
	}

	ExpansionPartyData GetPartyByID(int partyID)
	{
		if (Expansion_Assert_False(IsMissionHost(), "[" + this + "] GetPartyByID shall only be called on server!"))
			return NULL;

		return m_Parties.Get(partyID);
	}

	protected void UpdateMenu()
	{
		ExpansionScriptViewMenuBase menu = GetDayZGame().GetExpansionGame().GetExpansionUIManager().GetMenu();
		if (menu)
			menu.Refresh();
	}
}
