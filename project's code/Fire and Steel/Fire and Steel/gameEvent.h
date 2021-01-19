#ifndef  _GAMEEVENT_H_
#define _GAMEEVENT_H_

#include "keyboardControls.h" 
#include "pawn.h" 
#include "placesList.h"
#include "map"
#include "character.h"

class gameEvent
{
public:

	/************************************************* PUBLIC METHODS *************************************************/

	//Calls relevant methods depends on pressed key. Called methods requires variables from function arguments.
	void do_event(character &aCharacter,map &aMap,keyboardControls &aKeyboardControls,placesList &aPlacesList);

	//Shows place's menu for aCharacter. Place are taken from aPlacesList.
	void go_to_place(placesList& aPlacesList, character &aCharacter);\

	//Sets end loop to true from aKryboardControls which brakes main loop.
	void exit_game(keyboardControls &aKeyboardControls);
};

#endif 