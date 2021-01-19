#include "scriptPlayer.h"
#include <cstdlib>
#include <Windows.h>
#include "mapElement.h"
#include "defineThings.h"
#include <cmath>

scriptPlayer::scriptPlayer()
{
	addressOfStay = nullptr;
	pawnMark = SCRIPT_PLAYER_MARK;
}

void scriptPlayer::set_map(map & map)
{
	aPathCreator = map;//Copying map.
}

void scriptPlayer::do_turn()
{

	if (finished())
	{
		set_random_destination_coord();
		aStatistic.increase_survived_days();
		roll_items();
	}
	else
		go_one_block();

}

void scriptPlayer::roll_items()
{
	int dayNumb = aStatistic.get_survived_days();

	this->aItems.set_army(rand() % (SCRIPT_PLAYER_roll_item_multiplier * dayNumb));
	this->aItems.set_munition(rand() % (SCRIPT_PLAYER_roll_item_multiplier * dayNumb));
	this->aItems.set_gold(rand() % (SCRIPT_PLAYER_roll_item_multiplier * dayNumb));
	this->aItems.set_wood(rand() % (SCRIPT_PLAYER_roll_item_multiplier * dayNumb));
	this->aItems.set_iron(rand() % (SCRIPT_PLAYER_roll_item_multiplier * dayNumb));
	this->aItems.set_tools(rand() % (SCRIPT_PLAYER_roll_item_multiplier * dayNumb));
}

void scriptPlayer::create_script_player(map & aMap)
{

 	set_map(aMap);

	set_obiect_coord(roll_coord());

	set_address_of_stay(aMap.find_element_address(this->get_obiect_coordinates(), aMap.get_element_head()));
}

void scriptPlayer::recover_path()
{

	this->path = this->aPathCreator.find_path(this->get_obiect_coordinates(), this->destination);
}

COORD scriptPlayer::roll_coord()
{
	COORD rolledCoord;
	COORD lastCoordCoopy = aPathCreator.get_last_coord();
	mapElement *tmp;

	//Searching while findes walkable coordinates.
	do{

	rolledCoord.X = rand() % lastCoordCoopy.X;
	rolledCoord.Y = rand() % lastCoordCoopy.Y;

	tmp = aPathCreator.find_element_address(rolledCoord, aPathCreator.get_element_head());

	} while (tmp->get_element_mark() == markWALL or tmp==nullptr or tmp->check_permission()!=true); 
	
	return rolledCoord;
}

void scriptPlayer::set_random_destination_coord()
{
 	destination = roll_coord();

    path = aPathCreator.find_path(this->get_obiect_coordinates(), destination);
}

bool scriptPlayer::finished()
{
	if (path == nullptr)
	{
		pawn::scriptPlayerTurn = false;
		return true;
	}
	else
		return false;
}

void scriptPlayer::go_one_block()
{	
	//Setting new coordinates.
	this->obiectCoord = path->get_element_coordinates();

	set_address_of_stay(aPathCreator.find_element_address(path->get_element_coordinates(), aPathCreator.get_element_head()));//Showing position on map.

	set_new_path_head_and_delete_old();	//Deleting head list.

	Sleep(scriptPLAYER_WAIT);
}

void scriptPlayer::set_new_path_head_and_delete_old()
{

	mapElement*tmp = path;

	if (path->get_next_element_address() == nullptr)//If  next element' address is empty.
	{
		path = nullptr;

		delete tmp;
	}
	else
	{
		path = path->get_next_element_address();

		delete tmp;
	}


	return;
}

void scriptPlayer::delete_path(mapElement * path)
{
	if (path == nullptr)
		return;
	else
	{
		delete_path(path->get_next_element_address());
		delete path;
	}
}

mapElement * scriptPlayer::get_path()
{
	return path;
}

void scriptPlayer::set_destination(COORD aCoord)
{
	destination = aCoord;
}

COORD scriptPlayer::get_destination()
{
	return destination;
}
