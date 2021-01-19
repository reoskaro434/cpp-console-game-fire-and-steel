#ifndef _SCRIPTPLAYER_H
#define _SCRIPTPLAYER_H
#include <Windows.h>
#include "pawn.h"
#include "map.h"
#include "statistics.h"
#include "character.h"
#include "pathCreator.h"

class scriptPlayer :public pawn
{
private:

	/************************************************* PRIVATE ATTRIBUTES *************************************************/

	pathCreator aPathCreator;//Allows to create path.

	COORD destination;//Coordinates where script player have to go.

	mapElement * path;//Path from obiect starting point to destination coordinates.

	/************************************************* PRIVATE METHODS *************************************************/

	//Sets random destination coordinate.
	void set_random_destination_coord();

	//Returns true or false if script player finished his turn.
	bool finished();

	//Moves to next element from path list.
	void go_one_block();
	
	//Deletes old head from mapElement list and set new, which is next element.
	void set_new_path_head_and_delete_old();

	

public:

	/************************************************* PUBLIC METHDS *************************************************/

	//Sets pawn's mark and addres of stay to nullptr.
	scriptPlayer();

	//Creates a copy of pointers for map contained in pathCreator. Use pointers from map from argument.
	void set_map(map &map);

	//Returns random coordinates.
	COORD roll_coord();

	//Makes script player's turn.
	void do_turn();

	//Sets items for script player.
	void roll_items();

	//Calls all function which creates script player.
	void create_script_player(map & aMap);

	//Recovers path, if user loaded game.
	void recover_path();

	//Deletes path located in function argument, if script player hasn't deleted it. It is protection from memory leak.
	void delete_path(mapElement *path);

	//Returns script player's path.
	mapElement * get_path();

	//Sets new destination coordinates using coordinnates below. 
	void set_destination(COORD aCoord);

	//Returns destination coord.
	COORD get_destination();
};

#endif