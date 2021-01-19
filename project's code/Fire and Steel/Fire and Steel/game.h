#ifndef  _GAME_H_
#define _GAME_H_



#include "map"
#include "pawn.h"
#include "keyboardControls.h"
#include "gameEvent.h"
#include "placesList.h"
#include "character.h"
#include "scriptPlayer.h"
#include "save.h"
#include "load.h"

class game
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	map aMap; //Stores game's map.

	character aCharacter; //Stores player's statistics, items.

	keyboardControls aKeyboardControls;//Allows to control keyboard.

	gameEvent aGameEvent;//Calls specific function depends on pressed key.

	placesList aPlacesList;//Stores and manage places list.

	scriptPlayer aScriptPlayer;//Stores script player's statistics.

	save aSave;//Allows to save game.

	load aLoad;//Allows to load game.

	/************************************************* PRIVATE METHODS *************************************************/

	//Checks if script player moved to place where player is. if so then calls function which start battle.
	void check_collision_for_script_player();

	//Checks if player moved to place where script player is. if so then calls function which start battle.
	void check_collision_for_character();

	//Creates game without load.
	void prepare_game();

	//Makes player's turn.
	void player_turn();

	//Makes script player's turn.
	void script_player_turn();

	//Deletes all dynamic structures.
	void delete_structures();

	//Returns true if save game exist.
	bool is_binary_exist();

public:

	/************************************************* PUBLIC METHODS *************************************************/
	
	//Starts generate random numbers.
	game();

	//Starts the game.
	void start_game();

	//Shows map and statistics.
	void show_game();
};


#endif