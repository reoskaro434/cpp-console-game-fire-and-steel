#ifndef  _MAP_H_
#define _MAP_H_

#include <Windows.h> 
#include "mapElement.h"

class map
{
protected:

	/************************************************* PROTECTED ATTRIBUTES *************************************************/

    COORD lastCoord;//Cord from last map element.

	int lastLineNumb;//Last line's number.
   
	mapElement *mapElementHead;//First element of map element list.

	/************************************************* PRIVATE METHODS *************************************************/

	//Sets lastCoord using *mapElementHead.
	void set_last_element_coord();
	

public:

	/************************************************* PUBLIC METHODS *************************************************/

	//Sets mapElementHead to nullptr.
	map();

	//Sets mapElementHead to nullptr.
	~map();

	//Sets lastCoord to aCoord value.
	void set_last_element_coord(COORD aCoord);

	//Sets lastLineNumb to value taken from parametr.
	void set_last_line_number(int value);

	//Adds newElement to mapHead.
	void add_map_element(mapElement *&mapHead, mapElement *&newElement);

	//Show map on screen.
	void view_map();

	//Returns first element from map element list.
	mapElement *& get_element_head();

	//Returns variable lastCoord.
	COORD get_last_coord();

	//Returns last line number.
	int & get_last_line_number();

	//Loads map from txt file.
	void load_map();

	//Finds element in elementHead list using elCord.
	mapElement* find_element_address(COORD elCord, mapElement *elementHead);

	//Create graph.
	void create_web();

	//Delete map structure using mapHead.
	void delete_map(mapElement *&mapHead);

};

#endif 