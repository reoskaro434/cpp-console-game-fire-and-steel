#include "placesList.h"
#include <Windows.h>
#include "mapElement.h"
#include "map.h"
#include "places.h"
#include "woodcuttersVillage.h"
#include "minersVillage.h"
#include "town.h"
#include "castle.h"

placesList::placesList()
{
	placesHead = nullptr;
}

void placesList::read_map_and_make_list( map & aMap)
{
	mapElement *elHead = aMap.get_element_head();

	while (elHead != nullptr)
	{
		places *tmp;
		if (elHead->get_element_mark() == 'D')
		{
			tmp = new woodcuttersVillage(elHead->get_element_coordinates());
			add_to_places_list(placesHead, tmp);
		}
		else if (elHead->get_element_mark() == 'G')
		{
		 tmp = new minersVillage(elHead->get_element_coordinates());
		 add_to_places_list(placesHead, tmp);
		}
		else if (elHead->get_element_mark() == 'Z')
		{
			tmp = new castle(elHead->get_element_coordinates());
			add_to_places_list(placesHead, tmp);
		}
		else if (elHead->get_element_mark() == 'M')
		{
			tmp = new town(elHead->get_element_coordinates());
			add_to_places_list(placesHead, tmp);
		}

		elHead=elHead->get_next_element_address();
	}
}

void placesList::add_to_places_list(places *&placesHead,places * &newElement)
{
	if (placesHead == nullptr)
		placesHead = newElement;
	else
		add_to_places_list(placesHead->get_nextPlace(), newElement);
}

places * placesList::find_place(COORD aCord, places * placesHead)
{
	if (placesHead == nullptr)
		return nullptr;
	else
	{
		if (placesHead->get_obiect_coordinates().X == aCord.X and placesHead->get_obiect_coordinates().Y == aCord.Y)
			return placesHead;

		find_place(aCord, placesHead->get_nextPlace());
	}
	
}

places * placesList::get_places_head()
{
	return placesHead;
}

void placesList::delete_places(places * placesHead)
{
	if (placesHead == nullptr)
		return;
	else
	{
		delete_places(placesHead->get_nextPlace());
		
		delete placesHead;
	}
}
