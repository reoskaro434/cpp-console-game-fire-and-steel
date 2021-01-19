#ifndef  _TRADE_H_
#define _TRADE_H_

#include "obiect.h"
#include "character.h"
#include "keyboardControls.h"
class trade
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	keyboardControls keyboardControlsForTrade;//Allows to control trade menu.

public:

	/************************************************* PUBLIC METHODS *************************************************/

	//Shows trade menu between tradingCharacter and obiectP, where obiectP is obiect which comes from woodcutters class.
	void option_trade_menu_woodcutters(character &tradingCharacter, obiect &obiectP);

	//Shows trade menu between tradingCharacter and obiectP, where obiectP is obiect which comes from miners class.
	void option_trade_menu_miners(character &tradingCharacter, obiect &obiectP);

	//Shows trade menu between tradingCharacter and obiectP, where obiectP is obiect which comes from town class.
	void option_trade_menu_town(character &tradingCharacter, obiect &obiectP);

	//Shows trade menu between tradingCharacter and obiectP, where obiectP is obiect which comes from castle class.
	void option_trade_menu_castle(character &tradingCharacter, obiect &obiectP);

	//Adds one unit of army to obiectC. Gets army cost from obiectP and substracts same value of gold from obiectC.
	void deal_army(obiect & obiectC, obiect & obiectP);

	//Adds one unit of wood to obiectC. Delete one unit form obiectP. Gets wood cost from obiectP and substracts same value of gold from obiectC.
	void deal_wood(obiect & obiectC, obiect & obiectP);

	//Adds one unit of iron to obiectC. Delete one unit form obiectP. Gets iron cost from obiectP and substracts same value of gold from obiectC.
	void deal_iron(obiect & obiectC, obiect & obiectP);

	//Adds one unit of food to obiectC. Delete one unit form obiectP. Gets food cost from obiectP and substracts same value of gold from obiectC.
	void deal_food(obiect & obiectC, obiect & obiectP);

	//Adds one unit of tools to obiectC. Delete one unit form obiectP. Gets tools cost from obiectP and substracts same value of gold from obiectC.
	void deal_tools(obiect & obiectC, obiect & obiectP);

	//Adds one unit of munition to obiectC. Gets munition cost from obiectP and substracts same value of gold from obiectC.
	void deal_munition(obiect & obiectC, obiect & obiectP);

	//If goldC is greater or equal to cost and itemP is greater than 0, so it returns true.
	bool can_deal(const int &cost,const int &goldC,const int &itemP);
};

#endif 