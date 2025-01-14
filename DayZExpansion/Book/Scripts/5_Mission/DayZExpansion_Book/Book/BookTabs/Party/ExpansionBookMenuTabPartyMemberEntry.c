/**
 * ExpansionBookMenuTabTerritoryMemberEntry.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2021 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

#ifdef EXPANSIONMOD
class ExpansionBookMenuTabPartyMemberEntry: ExpansionScriptView
{
	ref ExpansionBookMenuTabPartyMemberEntryController m_EntryController;
	ExpansionBookMenuTabParty m_PartyTab;
	ExpansionPartyPlayerData m_Member;
	ExpansionPartyModule m_PartyModule;

	private TextWidget member_entry_label;
	private ImageWidget member_entry_icon;
	private ButtonWidget member_entry_button;
	
	void ExpansionBookMenuTabPartyMemberEntry(ExpansionBookMenuTabParty tab, ExpansionPartyPlayerData member)
	{
		m_PartyTab = tab;
		m_Member = member;
		
		if (!m_EntryController)
			m_EntryController = ExpansionBookMenuTabPartyMemberEntryController.Cast(GetController());
		
		if (!m_PartyModule)
			m_PartyModule = ExpansionPartyModule.Cast(GetModuleManager().GetModule(ExpansionPartyModule));

		SetEntry();
	}
	
	void SetEntry()
	{
		m_EntryController.MemberName = m_Member.Name;
		m_EntryController.NotifyPropertyChanged("MemberName");
		
		if (IsPlayerOnline(m_Member.UID))
		{
			member_entry_icon.SetColor(ARGB(255, 22, 160, 133));
		} 
		else 
		{
			member_entry_icon.SetColor(ARGB(255, 192, 57, 43));
		}
		
		m_EntryController.Background = GetRandomElementBackground();
		m_EntryController.NotifyPropertyChanged("Background");
	}
	
	string GetRandomElementBackground()
	{
		TStringArray backgrounds = new TStringArray;
		
		backgrounds.Insert("set:book_assets image:menu_element_1");
		backgrounds.Insert("set:book_assets image:menu_element_2");
		backgrounds.Insert("set:book_assets image:menu_element_3");
		backgrounds.Insert("set:book_assets image:menu_element_4");
		backgrounds.Insert("set:book_assets image:menu_element_5");
		backgrounds.Insert("set:book_assets image:menu_element_6");
		
		return backgrounds.GetRandomElement();
	}
	
	void OnEditButtonClick()
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());		
		ExpansionPartyData player_party = m_PartyModule.GetParty();
		
		if (!player_party)
			return;
		
		if (!m_Member)
			return;

		ExpansionPartyPlayerData playerPartyData = player_party.GetPlayer(GetGame().GetPlayer().GetIdentity().GetId());
		if (playerPartyData && !playerPartyData.CanEdit())
		{
			ExpansionNotification("STR_EXPANSION_PARTY_NOTIF_TITLE", "STR_EXPANSION_PARTY_CANTEDIT").Error();
			return;
		}
		else if (playerPartyData.CanEdit())
		{
			m_PartyTab.Hide();
			m_PartyTab.GetMemberEditTab().SetMember(m_Member);
			m_PartyTab.GetMemberEditTab().SetParty(player_party);
			m_PartyTab.GetMemberEditTab().SetPlayer(playerPartyData);
			m_PartyTab.GetMemberEditTab().SetTab();
			m_PartyTab.GetMemberEditTab().Show();
		}
	}
	
	override string GetLayoutFile() 
	{
		return "DayZExpansion/Book/GUI/layouts/tabs/party/expansion_book_tab_party_member_entry.layout";
	}
	
	override typename GetControllerType() 
	{
		return ExpansionBookMenuTabPartyMemberEntryController;
	}
	
	bool IsPlayerOnline( string uid )
	{
		for ( int i = 0; i < ClientData.m_PlayerList.m_PlayerList.Count(); i++ )
		{
			SyncPlayer player = ClientData.m_PlayerList.m_PlayerList.Get( i );

			if ( player )
			{
				if ( player.m_RUID == uid )
				{
					return true;
				}
			}
		}
		
		return false;
	}
	
	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if (w == member_entry_button)
		{
			member_entry_label.SetColor(ARGB(255, 220, 220, 220));
			member_entry_icon.SetColor(ARGB(255, 220, 220, 220));
		}
		
		return super.OnMouseEnter(w, x, y);
	}
	
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		if (w == member_entry_button)
		{
			member_entry_label.SetColor(ARGB(255, 0, 0, 0));
			
			if (IsPlayerOnline(m_Member.UID))
			{
				member_entry_icon.SetColor(ARGB(255, 22, 160, 133));
			} 
			else 
			{
				member_entry_icon.SetColor(ARGB(255, 192, 57, 43));
			}
		}
		
		return super.OnMouseLeave(w, enterW, x, y);
	}
};

class ExpansionBookMenuTabPartyMemberEntryController: ExpansionViewController
{
	string MemberName;
	string Background;
};

#endif
