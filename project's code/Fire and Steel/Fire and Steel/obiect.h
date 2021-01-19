#ifndef  _OBIECT_H_
#define _OBIECT_H_

#include <Windows.h>
#include "items.h"
#include "arcadeGame.h"
#include "prepareToFight.h"

class obiect 
{
protected:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	bool isThisPlayer;//Tells if obiect is player or non-player.
	
	COORD obiectCoord;//Obiect's coordinates.
	
public:
	
	/************************************************* PUBLIC ATTRIBUTES *************************************************/

	prepareToFight aPrepareToFight;//Sets real fighting wariors.

	items aItems;//Stores items.

    arcadeGame aArcadeGame;//Allow to play arcade game. Used to roll "luck".

	/************************************************* PUBLIC METHODS *************************************************/

	//Returns true if obiect address which calls function is equal to address of obiect A. Otherwise return false.
	bool operator==(obiect &A);

	//Takes the all items from defeated obiect.
	void take_loot(obiect &defeated);

	//Returns true if obiect which calls the function is player.
	bool get_is_this_player();

	//Returns obiect's coordinates.
	COORD get_obiect_coordinates();

	//Starts battle between obiect which calls function and obiect aObiectWhichAttack.
	void start_battle(obiect & aObiectWhichAttack);

	//Sets new obiect's coordinates to newCoord value.
	void set_obiect_coord(COORD newCoord);

};

#endif