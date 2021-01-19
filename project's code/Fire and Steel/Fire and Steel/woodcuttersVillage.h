#ifndef  _WOODCUTTERSVILLAGE_H_
#define _WOODCUTTERSVILLAGE_H_



#include <Windows.h>
#include "character.h"
#include "places.h"
#include "character.h"
#include "missionWoodcutters.h"

class woodcuttersVillage:public places
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	missionWoodcutters aMission;//Allows to do mission.

public:

	/************************************************* PUBLIC METHODS *************************************************/

	//Sets place's name, coord. Sets isThisPlayer to false.
	woodcuttersVillage(COORD aCord);

	//Random generates items for place.
	void set_place();

	//Shows trade menu between player(aCharacter) and place.
	void trade_menu(character &aCharacter);

	//Shows information about place. Variable aCharacter is used to show player equipment.
	woodcuttersVillage & operator>>(character & aCharacter);

	//Starts mission for player(aCharacter).
	void start_mission(character &aCharacter);
};	

#endif