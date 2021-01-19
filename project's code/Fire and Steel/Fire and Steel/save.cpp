#include "save.h"
#include "mapElement.h"


save & save::operator<<(character & aCharacter)
{

	saveFile.write((const char *)& aCharacter, sizeof aCharacter);

	return *this;
}

save & save::operator<<(scriptPlayer & aScriptPlayer)
{
	saveFile.write((const char *)& aScriptPlayer, sizeof aScriptPlayer);

	return *this;
}

save  & save::operator<<(map & aMap)
{
	mapElement *tmp = aMap.get_element_head();

	saveFile.write((const char *)& aMap.get_last_coord(), sizeof aMap.get_last_coord());

	saveFile.write((const char *)& aMap.get_last_line_number(), sizeof aMap.get_last_line_number());

	while (tmp != nullptr)
	{
		char mark = tmp->get_layed_mark();
		saveFile.write((const char *)& mark, sizeof mark);

		mark = tmp->get_element_mark();
		saveFile.write((const char *)& mark, sizeof mark);

		COORD coord = tmp->get_element_coordinates();
		saveFile.write((const char *)& coord, sizeof coord);


		tmp = tmp->get_next_element_address();

	}


	return *this;
}

save  & save::operator<<(placesList& aPlacesList)
{
	places *tmp=aPlacesList.get_places_head();

	while (tmp!=nullptr)
	{
		saveFile.write((const char *)& tmp->aItems, sizeof tmp->aItems);

		tmp = tmp->get_nextPlace();
	}


	return *this;
}

void save::save_game(character &aCharacter, scriptPlayer &aScriptPlayer, map &aMap, placesList &aPlacesList)
{
	saveFile.open("saved_game.bin", std::ios::binary);

	*this << aCharacter;
	*this << aScriptPlayer;
	*this << aMap;
	*this << aPlacesList;

	saveFile.close();
}
