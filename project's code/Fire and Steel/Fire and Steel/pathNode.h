#ifndef _PATHNODE_H_
#define _PATHNODE_H_

#include "mapElement.h"
#include <Windows.h>

class pathNode
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

    mapElement *aMapElement;//Stores map element address.

	pathNode *nextNode;//Stores next element address.

    pathNode *parent;//Stores parent address.

	int costF;//Additioned costG + costH.

	int costG;//Startpoint distance.

	int costH;//Destination distance.

public:

	/************************************************* PUBLIC METHODS *************************************************/

	//Sets ptrs to nullptr.
	pathNode();

	//Sets map's element.
	pathNode &operator=(mapElement *&anElement);

	//Returns F value.
	int get_cost_F();
	
	//Calculates F G H value for element using coordinates below.
	void calculate(COORD start,COORD stop);

	//Calculates H value using coordinates in arguments.
	void calculate_H_value( COORD meta);

	//Calculates G value using coordinates in arguments.
	void calculate_G_value(COORD start);

	//Sets parents for each node in function arguments.
	void set_parent_for_element(pathNode *up, pathNode *down, pathNode *left, pathNode *right);
	 
	//Returns map element's address.
	mapElement *& get_map_element_address();

	//Returns next node's address.
	pathNode *& get_next_node();

	//Sets parent for element using argument below.
	void set_parent(pathNode *aNode);

	//Returns parent address.
	pathNode *& get_parent();

};

#endif