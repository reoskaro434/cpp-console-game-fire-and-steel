#include "trade.h"
#include "keyboardControls.h"
#include "character.h"
#include "obiect.h"


void trade::option_trade_menu_woodcutters(character & tradingCharacter, obiect & obiectP)
{
			keyboardControlsForTrade.set_pressed_key();

		switch (keyboardControlsForTrade.get_enum_key())
		{
		case keyboardControls::one:
		{
			deal_wood(tradingCharacter, obiectP);
		}break;
		case keyboardControls::two:
		{
			deal_food(tradingCharacter, obiectP);

		}break;
		case keyboardControls::keyEsc:
		{
			tradingCharacter.keyManagerForCharacter.set_end_loop(true);
		}break;
		default:
		{

		}break;
		}
		keyboardControlsForTrade.clear_buffor();
}

void trade::option_trade_menu_miners(character & tradingCharacter, obiect & obiectP)
{
	keyboardControlsForTrade.set_pressed_key();

	switch (keyboardControlsForTrade.get_enum_key())
	{
	case keyboardControls::one:
	{
		deal_iron(tradingCharacter, obiectP);
	}break;
	case keyboardControls::two:
	{
		deal_food(tradingCharacter, obiectP);

	}break;
	case keyboardControls::keyEsc:
	{
		tradingCharacter.keyManagerForCharacter.set_end_loop(true);
	}break;
	default:
	{

	}break;
	}
	keyboardControlsForTrade.clear_buffor();
}

void trade::option_trade_menu_town(character & tradingCharacter, obiect & obiectP)
{

	keyboardControlsForTrade.set_pressed_key();

	switch (keyboardControlsForTrade.get_enum_key())
	{
	case keyboardControls::one:
	{
		deal_tools(tradingCharacter, obiectP);
	}break;
	case keyboardControls::two:
	{
		deal_food(tradingCharacter, obiectP);

	}break;
	case keyboardControls::keyEsc:
	{
		tradingCharacter.keyManagerForCharacter.set_end_loop(true);
	}break;
	default:
	{

	}break;
	}
	keyboardControlsForTrade.clear_buffor();
}

void trade::option_trade_menu_castle(character & tradingCharacter, obiect & obiectP)
{
	keyboardControlsForTrade.set_pressed_key();

	switch (keyboardControlsForTrade.get_enum_key())
	{
	case keyboardControls::one:
	{
		deal_army(tradingCharacter, obiectP);
	}break;
	case keyboardControls::two:
	{
		deal_munition(tradingCharacter, obiectP);

	}break;
	case keyboardControls::keyEsc:
	{
		tradingCharacter.keyManagerForCharacter.set_end_loop(true);
	}break;
	default:
	{

	}break;
	}
	keyboardControlsForTrade.clear_buffor();
}


void trade::deal_army(obiect & obiectC, obiect & obiectP)
{
	if (can_deal(obiectP.aItems.get_armyCost(), obiectC.aItems.get_gold(), obiectP.aItems.get_army()))
	{
		obiectC.aItems.set_army(obiectC.aItems.get_army() + 1);//Adding one unit.
		obiectC.aItems.set_gold(obiectC.aItems.get_gold() - obiectP.aItems.get_armyCost());
		//We don't remove armies from obiectP.
	}
}

void trade::deal_wood(obiect & obiectC, obiect & obiectP)
{
	if (can_deal(obiectP.aItems.get_woodCost(), obiectC.aItems.get_gold(), obiectP.aItems.get_wood()))
	{
		obiectC.aItems.set_wood(obiectC.aItems.get_wood() + 1);
		obiectC.aItems.set_gold(obiectC.aItems.get_gold() - obiectP.aItems.get_woodCost());
		obiectP.aItems.set_wood(obiectP.aItems.get_wood() - 1);

	}
}

void trade::deal_iron(obiect & obiectC, obiect & obiectP)
{
	if (can_deal(obiectP.aItems.get_ironCost(), obiectC.aItems.get_gold(), obiectP.aItems.get_iron()))
	{
		obiectC.aItems.set_iron(obiectC.aItems.get_iron() + 1);
		obiectC.aItems.set_gold(obiectC.aItems.get_gold() - obiectP.aItems.get_ironCost());
		obiectP.aItems.set_iron(obiectP.aItems.get_iron() - 1);

	}
}

void trade::deal_food(obiect & obiectC, obiect & obiectP)
{
	if (can_deal(obiectP.aItems.get_foodCost(), obiectC.aItems.get_gold(), obiectP.aItems.get_food()))
	{
		obiectC.aItems.set_food(obiectC.aItems.get_food() + 1);
		obiectC.aItems.set_gold(obiectC.aItems.get_gold() - obiectP.aItems.get_foodCost());
		obiectP.aItems.set_food(obiectP.aItems.get_food() - 1);
	}
}

void trade::deal_tools(obiect & obiectC, obiect & obiectP)
{
	if (can_deal(obiectP.aItems.get_toolsCost(), obiectC.aItems.get_gold(), obiectP.aItems.get_tools()))
	{
		obiectC.aItems.set_tools(obiectC.aItems.get_tools() + 1);
		obiectC.aItems.set_gold(obiectC.aItems.get_gold() - obiectP.aItems.get_toolsCost());
		obiectP.aItems.set_tools(obiectP.aItems.get_tools() - 1);
	}
}

void trade::deal_munition(obiect & obiectC, obiect & obiectP)
{
	if (can_deal(obiectP.aItems.get_munitionCost(), obiectC.aItems.get_gold(), obiectP.aItems.get_munition()))
	{ 
		obiectC.aItems.set_munition(obiectC.aItems.get_munition() + 1);
		obiectC.aItems.set_gold(obiectC.aItems.get_gold() - obiectP.aItems.get_munitionCost());
	}
}


bool trade::can_deal(const int & cost, const int & goldC, const int & itemP)
{
	if (goldC >= cost && itemP > 0) return true;
		
	else return false;

}


