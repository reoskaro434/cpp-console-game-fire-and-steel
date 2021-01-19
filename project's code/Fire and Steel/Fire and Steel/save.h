#pragma once
#include <fstream>
#include "character.h"
#include "scriptPlayer.h"
#include "map.h"
#include "placesList.h"

class save
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	std::ofstream saveFile;//Uses to save game data.

	/************************************************* PRIVATE METHODS *************************************************/

	//Saves character to binary file.
	save & operator<<(character &aCharacter);

	//Saves script player to binary file.
	save  & operator<<(scriptPlayer &aScriptPlayer);

	//Saves map to binary file.
	save  & operator<<(map &aMap);

	//Saves places list to binary file.
	save & operator<<(placesList &aPlacesList);

public:
	
	/************************************************* PUBLIC METHODS *************************************************/

	//Calls all private operators which makes a game save to binary file.
	void save_game(character &aCharacter, scriptPlayer &aScriptPlayer, map &aMap, placesList &aPlacesList);
};

