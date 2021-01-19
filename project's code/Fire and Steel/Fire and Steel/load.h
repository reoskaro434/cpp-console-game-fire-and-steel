#pragma once
#include <fstream>
#include "character.h"
#include "scriptPlayer.h"
#include "map.h"
#include "placesList.h"

class load
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	std::ifstream loadFile;//Uses to load game data.

	/************************************************* PRIVATE METHODS *************************************************/

	//Loads from file to aCharacter.
	load & operator>>(character &aCharacter);

	//Loads from file to aScriptPlayer.
	load  & operator>>(scriptPlayer &aScriptPlayer);

	//Loads from file to aMap.
	load  & operator>>(map &aMap);

	//Loads from file to aPlacesList.
	load & operator>>(placesList &aPlacesList);

	//If aScriptPlayer destination are sets to (0,0), the function roll new destination.
	void check_script_player_destination(scriptPlayer &aScriptPlayer);

public:

	/************************************************* PUBLIC METHODS *************************************************/

	//Loads aCharacter, aScriptPlayer, aMap and aPlacesList from file.
	void load_game(character &aCharacter, scriptPlayer &aScriptPlayer, map &aMap, placesList &aPlacesList);
};

