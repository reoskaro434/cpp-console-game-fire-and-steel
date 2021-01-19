#ifndef  _MINERSVILLAGE_H_
#define _MINERSVILLAGE_H_


#include <Windows.h>
#include "places.h"
#include "missionMiners.h"

class minersVillage :public places
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	missionMiners aMission;//Allows to do mission.

public:

	/************************************************* PUBLIC METHODS *************************************************/

	//Sets place's name, coord. Sets isThisPlayer to false.
	minersVillage(COORD aCord);

	//Random generates items for place.
	void set_place();

	//Shows trade menu between player(aCharacter) and place.
	void trade_menu(character &aCharacter);

	//Shows information about place. Variable aCharacter is used to show player equipment.
	minersVillage & operator>>(character & aCharacter);

	//Starts mission for player(aCharacter).
	void start_mission(character &aCharacter);
};

#endif 