#include "load.h"

load & load::operator>>(character & aCharacter)
{
	loadFile.read(( char *)& aCharacter, sizeof aCharacter);

	aCharacter.set_address_of_stay_to_nullptr();

	return *this;
}

load & load::operator>>(scriptPlayer & aScriptPlayer)
{
	loadFile.read((char *)& aScriptPlayer, sizeof aScriptPlayer);

	aScriptPlayer.set_address_of_stay_to_nullptr();

	return *this;
}

load & load::operator>>(map & aMap)
{
	bool condition = false;

	COORD tmp;
	loadFile.read((char *)& tmp, sizeof tmp);
	aMap.set_last_element_coord(tmp);

	int tmp2;
	loadFile.read((char *)& tmp2, sizeof tmp2);
	aMap.set_last_line_number(tmp2);

	while (condition != true)
	{
		//Downloading data.

		char layedMark;
		loadFile.read(( char *)& layedMark, sizeof layedMark);

		char mark;
		loadFile.read(( char *)& mark, sizeof mark);

		COORD coord;
		loadFile.read(( char *)& coord, sizeof coord);

		
		//Allocating memory for map element.

		mapElement *tmp = new mapElement(coord.X, coord.Y, mark);
		tmp->set_layed_mark(layedMark);


		//Creating map.

		aMap.add_map_element(aMap.get_element_head(), tmp);


		
		if (coord.X == aMap.get_last_coord().X and coord.Y == aMap.get_last_coord().Y) 
			condition = true;
	}


	//Graph recovery.
	
	aMap.create_web();


	return *this;
}

load & load::operator>>(placesList & aPlacesList)
{

	places *tmpPlacePtr = aPlacesList.get_places_head();

	while (tmpPlacePtr!=nullptr)
	{
		//Downloading data.

		items tmp;
		loadFile.read((char *)& tmp, sizeof tmp);	


	

		tmpPlacePtr->aItems = tmp;
		tmpPlacePtr = tmpPlacePtr->get_nextPlace();
	}

	return *this;
}

void load::check_script_player_destination(scriptPlayer &aScriptPlayer)
{
	if (aScriptPlayer.get_destination().X == 0 and aScriptPlayer.get_destination().Y == 0)//Setting new destination coordinates.
		aScriptPlayer.set_destination(aScriptPlayer.roll_coord());
}

void load::load_game(character & aCharacter, scriptPlayer & aScriptPlayer, map & aMap, placesList & aPlacesList)
{
	loadFile.open("saved_game.bin", std::ios::binary);

	*this >> aCharacter;
	*this >> aScriptPlayer;
	*this >> aMap;


	aPlacesList.read_map_and_make_list(aMap);

	*this >> aPlacesList;

	loadFile.close();



	aCharacter.set_address_of_stay(aMap.find_element_address(aCharacter.get_obiect_coordinates(), aMap.get_element_head())); 

	aScriptPlayer.set_map(aMap);
	aScriptPlayer.set_address_of_stay(aMap.find_element_address(aScriptPlayer .get_obiect_coordinates(), aMap.get_element_head()));

	check_script_player_destination(aScriptPlayer);

	aScriptPlayer.recover_path();
}
