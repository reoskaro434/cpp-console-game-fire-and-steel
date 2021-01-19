#ifndef  _CHARACTER_H_
#define  _CHARACTER_H_


#include "pawn.h"
#include "keyboardControls.h"


class character:public pawn
{
	
public:

	/************************************************* PUBLIC ATTRUBUTES *************************************************/

	keyboardControls keyManagerForCharacter;//Allow tu use keyboard.

	/************************************************* PUBLIC METHODS ***************************************************/

	//Sets address of stay to nullptr. Set basic equpiment for player.
	character();

	//Starts the sleeping procedure. Increase game's day number and refresh move ammount.
	void sleep();

	//Marks player on map. Variable aMap is a place for finding by coordinates addres of player. aCoord is a coordinates of player.
	void create_character(map & aMap, COORD aCoord);

	//Shows character's equipment.
	void show_character_items();
};

#endif  