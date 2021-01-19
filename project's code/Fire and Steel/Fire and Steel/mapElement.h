#ifndef  _MAPELEMENT_H_
#define _MAPELEMENT_H_

#include <Windows.h>
#include "mapElement.h"


class mapElement
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	bool walkable;//If true, player or scrip player is able to move there.

	COORD elementCoordinates;//Stores element's coordinates.

	char mapMark;//Stores map's mark.

	mapElement *nextElement;//Stores next element's address.

	char layedMark;//Stores mark of player or script player when one of them stand's there.

	mapElement *upElement, *downElement, *leftElement, *rightElement;//Stores element addres which comes from up, down, left, right.

public:
	
	/************************************************* PUBLIC METHODS *************************************************/

	//Creates map element which have coordinates (X,Y) and is visible as mark value.
	mapElement(int X, int Y, char mark);

	//Sets element coordinates to value "coordinates".
	void set_element_coordinates(COORD coordinates);
	
	//Sets map mark to "mark".
	void set_map_mark(char mark);

	//Sets mark like bandits "B" or character "P" which covers old mark.
	void set_layed_mark(char mark);

	//Sets up pointer to "ptr".
	void set_up_ptr(mapElement *ptr);

	//Sets down pointer to "ptr".
	void set_down_ptr(mapElement *ptr);

	//Sets left pointer to "ptr".
	void set_left_ptr(mapElement *ptr);

	//Sets right pointer to "ptr".
	void set_right_ptr(mapElement *ptr);

	//Sets next element address to "addres".
	void set_next_element_address(mapElement *addres);

	//Returns up pointer.
	mapElement * get_up_ptr();

	//Returns down pointer.
	mapElement * get_down_ptr();

	//Returns left pointer.
	mapElement * get_left_ptr();

	//Returns right pointer.
	mapElement * get_right_ptr();

	//Returns element's coordinates.
	COORD get_element_coordinates();

	//Returns element's mark.
	char get_element_mark();

	//Returns next element's address.
	mapElement *& get_next_element_address();

	//Returns layed mark.
	char get_layed_mark();

	//Returns boolean varaible "walkable". If variable is true then player or script player can go there.
	bool check_permission();

};

#endif 
