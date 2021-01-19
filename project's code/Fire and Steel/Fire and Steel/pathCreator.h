#ifndef _PATHCREATOR_H_
#define _PATHCREATOR_H_

#include <Windows.h> 
#include "pathNode.h"
#include "map.h"

class pathCreator:public map
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	COORD start;//Starting coordinates.

	COORD stop;//End coordinates.

	mapElement * pathMapElementForExport; //Head list which goes to script player.Deleting in "scriptPlayer" class.

	pathNode * path;//Path created from parent pointers.

	pathNode *openList;//Head list of non-visited place.

	pathNode *closedList;//Head list of visited place.
	
	/************************************************* PRIVATE METHODS *************************************************/

	//Adds element to pathMapElementForExport.
	pathCreator & operator^(pathNode *&aNode);

	//Adds to open list.
	pathCreator & operator+(pathNode *&aNode);

	//Deletes from open list and adds to close list.
	pathCreator & operator-(pathNode *aNode);
	
	//Searches element in open and close list. Returns his address.
	pathNode * find_path_node(mapElement * elementFromNode);

	//Findes for element with smallest F value. Returns address.
	pathNode *& find_smallest_F();

	//Search node from pathNode class, which contain "mapElement" address.
	pathNode * find_in_closed_list(mapElement *elementFromNode);

	//Searches node from pathNode class, which contain "mapElement" address.
	pathNode * find_in_open_list(mapElement *elementFromNode);

	//Deletes node, which contain mapElement address.
	void closed_list_delete_node(mapElement *elementFromNode);

	//Unpluges from open list node, which contain mapElement address. It is used, when node is moving to closed list.
	void disconnect_from_open_list(mapElement *elementFromNode);

	//Sets parent for all elements.
	void set_parent_for_elements();

	//Searches walkable element, using closed list.
	void find_walkable_elements();

	//Finding elements by coord and gives it for overload operator.
	void add(COORD aCoord);

	//Findes through parents path from start to stop coordinates. If path is complite it makes stop A* algorythm.
	void try_to_create_path();

	//Findes pathNode's element in close list using coord.
    pathNode *find_in_closed_list_by_coords(COORD stop);

	//Creates path for script player, using parent's pointer.
    void create_path_for_export();

	//Visites all parent pointer from stop to start coordinates.
	void go_through_parents_and_create_export_list(pathNode *aPathNode);

	//Creates mapElement list for script player.
	void add_map_element_to_export_list(mapElement *& elementHead);

	//Deletes list, which head is in function argument.
	void delete_list(pathNode *listHead);

public:

	/************************************************* PUBLIC METHODS *************************************************/

	//Sets all pointers to nullptr.
	pathCreator();

	//Copies element's head, last coord and last line number, for pathCreator.
	pathCreator &operator=(map & aMap);

	//Findes path from start to stop. Returns mapElement list.
	mapElement *& find_path(COORD start, COORD stop);

};

#endif