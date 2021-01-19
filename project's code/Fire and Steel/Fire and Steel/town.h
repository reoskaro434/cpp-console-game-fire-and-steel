#ifndef  _TOWN_H_
#define  _TOWN_H_


#include <Windows.h>
#include "places.h"
#include "missionTown.h"

class town :public places
{
private: 

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	missionTown aMission;//Allows to do mission.

public:

	/************************************************* PUBLIC METHODS *************************************************/

	//Sets place's name, coord. Sets isThisPlayer to false.
	town(COORD aCord);

	//Random generates items for place.
	void set_place();

	//Shows trade menu between player(aCharacter) and place.
	void trade_menu(character &aCharacter);

	//Shows information about place. Variable aCharacter is used to show player equipment.
	town & operator>>(character & aCharacter);

	//Starts mission for player(aCharacter).
	void start_mission(character &aCharacter);
};
#endif 
