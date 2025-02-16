/**
 * ExpansionMarketMenuItemManagerCategory.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2021 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionMarketMenuItemManagerCategory: ExpansionScriptView
{
	protected ref ExpansionMarketMenuItemManagerCategoryController m_MarketItemManagerCategoryController;
	string m_CategoryName;
	ref TStringArray m_ItemAttachments = new TStringArray;
	ExpansionMarketMenuItemManager m_MarketMenuItemManager;
	protected ref ExpansionMarketMenuTooltip m_CategoryTooltip;
		
	ButtonWidget category_button;
	Widget category_background;
	
	void ExpansionMarketMenuItemManagerCategory(string categoryName, TStringArray attachments, ExpansionMarketMenuItemManager itemManager)
	{
		m_CategoryName = categoryName;
		m_ItemAttachments = attachments;
		m_MarketMenuItemManager = itemManager;
		
		if (!m_MarketItemManagerCategoryController)
			m_MarketItemManagerCategoryController = ExpansionMarketMenuItemManagerCategoryController.Cast(GetController());
	}
	
	override string GetLayoutFile() 
	{
		return "DayZExpansion/Market/GUI/layouts/market/expansion_market_menu_item_manager_category_element.layout";
	}
	
	override typename GetControllerType() 
	{
		return ExpansionMarketMenuItemManagerCategoryController;
	}
	
	void SetIcon(string name)
	{
		m_MarketItemManagerCategoryController.CategoryIcon = name;
		m_MarketItemManagerCategoryController.NotifyPropertyChanged("CategoryIcon");
	}
	
	void OnCategoryButtonClick()
	{
		m_MarketMenuItemManager.SetListView(m_ItemAttachments);
	}
	
	override bool OnMouseEnter(Widget w, int x, int y)
	{
		super.OnMouseEnter(w, x, y);
		
		switch (w)
		{
			case category_button:
			{
				category_background.SetColor(ExpansionColor.HexToARGB(GetExpansionSettings().GetMarket().MarketMenuColors.ColorSearchFilterButton));
				if (!m_CategoryTooltip) 
				{
					m_CategoryTooltip = new ExpansionMarketMenuTooltip();
					m_CategoryTooltip.SetTitle(m_CategoryName);
					m_CategoryTooltip.SetContentOffset(0.019531, 0);
					m_CategoryTooltip.Show();
				}
				break;
			}
		}		
		return false;
	}
	
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		super.OnMouseLeave(w, enterW, x, y);
		
		switch (w)
		{
			case category_button:
			{
				category_background.SetColor(ExpansionColor.HexToARGB(GetExpansionSettings().GetMarket().MarketMenuColors.BaseColorHeaders));
				if (m_CategoryTooltip) 
					delete m_CategoryTooltip;
				break;
			}
		}
			
		return false;
	}
};
class ExpansionMarketMenuItemManagerCategoryController: ExpansionViewController
{
	string CategoryIcon;
};