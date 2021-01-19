#include "pawn.h"
#include <Windows.h>
#include "mapElement.h"
#include "map.h"
#include "defineThings.h"
#include "scriptPlayer.h"

bool pawn::scriptPlayerTurn = false;


void pawn::set_address_of_stay_to_nullptr()
{
	addressOfStay = nullptr;
}

void pawn::set_address_of_stay(mapElement *address)
{
	if (addressOfStay != nullptr)
		addressOfStay->set_layed_mark(addressOfStay->get_element_mark()); //Removing old mark;
	
	addressOfStay = address; //Setting new address;
	update_position();
}

void pawn::update_position()
{
	addressOfStay->set_layed_mark(pawnMark);
}



void pawn::move_up(map &aMap)
{

	if (can_go(addressOfStay->get_up_ptr()) == true) // Checking if element is walkable.
	{
		obiectCoord.Y--;
		set_address_of_stay(aMap.find_element_address(obiectCoord, aMap.get_element_head()));
	}
}

void pawn::move_down(map & aMap)
{
	if (can_go(addressOfStay->get_down_ptr())== true)
	{
		obiectCoord.Y++;
		set_address_of_stay(aMap.find_element_address(obiectCoord, aMap.get_element_head()));
	}
}

void pawn::move_left(map & aMap)
{
	if (can_go(addressOfStay->get_left_ptr()) == true)
	{
		obiectCoord.X--;
		set_address_of_stay(aMap.find_element_address(obiectCoord, aMap.get_element_head()));
	}
}

void pawn::move_right(map & aMap)
{
	if (can_go(addressOfStay->get_right_ptr()) == true)
	{
		obiectCoord.X++;
		set_address_of_stay(aMap.find_element_address(obiectCoord, aMap.get_element_head()));
	}
}

bool pawn::can_go(mapElement * element)
{
	if (aStatistic.decrease_move())
	{
		if (element == nullptr) return false;

		else if (element->check_permission() == true) return true;

		else return false;
	}
}