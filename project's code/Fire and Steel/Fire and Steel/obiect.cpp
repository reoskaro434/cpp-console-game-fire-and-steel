#include <iostream>
#include "obiect.h"
#include <Windows.h>
#include "fight.h"


bool obiect::operator==(obiect & A)
{
   if(this==&A) return true;
	
	else return false;
}


void obiect::take_loot(obiect & defeated)
{
	this->aItems += defeated.aItems;
}


bool obiect::get_is_this_player()
{
	return isThisPlayer;
}

COORD obiect::get_obiect_coordinates()
{
	return obiectCoord;
}

void obiect::start_battle(obiect & aggressor)
{
	system("CLS");

	fight aFight;


	aFight.do_fight(aggressor,*this);

	if (this->aItems.get_army() <= 0)
	{
		//Attacker won.
		aFight.aggressor_winning_message(*this);
		aggressor.take_loot(*this);
	}
	else
	{
		//Defender won.
		aFight.defender_winning_message(aggressor);
		this->take_loot(aggressor);
	}

	system("pause");
}

void obiect::set_obiect_coord(COORD newCoord)
{
	obiectCoord = newCoord;
}
