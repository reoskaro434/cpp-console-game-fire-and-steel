#ifndef  _PLACESLIST_H_
#define _PLACESLIST_H_

#include <Windows.h>
#include "map.h"

#include "places.h"
class placesList
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	places *placesHead;//Stores all places.

public:

	/************************************************* PUBLIC METHODS *************************************************/
	
	//Sets placesHead to nullptr.
	placesList();

	//Reads map and makes places list. aMap is a map which method reads.
	void read_map_and_make_list( map &aMap);

	//Adds newElement to places list. placesHead is a first element of list.
	void add_to_places_list(places *&placesHead, places *&newElement);

	//Findes place and returns his addres. aCord is a coordinates uses to find element. placeHead is a first element of list.
	places * find_place(COORD aCord, places *placesHead);

	//Returns places head.
	places * get_places_head();

	//Delete places. placesHead is a first element of list.
	void delete_places(places * placesHead);
};

#endif 