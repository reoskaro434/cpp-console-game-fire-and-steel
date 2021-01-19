#ifndef  _PLACES_H_
#define _PLACES_H_


#include <Windows.h> 
#include <string>
#include "obiect.h" 
#include "character.h"
#include "keyboardControls.h"
#include "trade.h"
#include "recon.h"

class places:public obiect
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	places *nextPlace;//Stores next element address.
	
protected:

	/************************************************* PROTECTED ATTRIBUTES *************************************************/

	std::string placeName;//Stores place name.

	int sleepingCost;//Stores cost of sleeping.

    trade aTradeMenu;//Allows to trade with places.

	recon aRecon;//Allows to do recon.

	/************************************************* PROTECTED METHODS *************************************************/
	
	//Returns sleeping cost.
	int get_sleeping_cost();

	//Sets place's name to variable "name".
	void set_place_name(std::string name);

	//Sets place's coord to variable "aCord".
	void set_place_coord(COORD aCord);

	//Refresh characters move ammount and increase survived days for character (tiredHero).
	void sleep_in(character& tiredHero);

	//Allows to chose action which player are able to do.
	void do_menu_interaction(character &aCharacter);

	//Shows action description, variable placeName shows place name.
	places & operator>>(const std::string &placeName);

public:

	/************************************************* PUBLIC METHODS *************************************************/

	//Sets nextPlace to nullptr.
	places();

	//Returns next place's address.
	places *&get_nextPlace();

	//Shows place's menu for player (aCharacter) where player can chose option.
	void show_menu(character &aCharacter);

	/************************************************* VIRTUAL METHODS *************************************************/

	//Shows trade's menu between player(aCharacter) and place.
    virtual	void trade_menu(character &aCharacter);

	//Random generates items for place.
    virtual void set_place();
	
	//Starts mission for player(aCharacter).
	virtual void start_mission(character &aCharacter);
};
#endif 
