#include <iostream>
#include "statistics.h"
#include "defineThings.h"

statistics::statistics()
{
	survivedDays = 0;
	moveAmount = MOVEAMOUNT;
	
}

void statistics::refresh_move_amount()
{
	moveAmount = MOVEAMOUNT;
}

int statistics::get_move_amount()
{
	return moveAmount;
}

bool statistics::decrease_move()
{
	if (moveAmount > 0)
	{
		moveAmount--;
		return true;
	}
	else return false;
}

void statistics::show_move_ammount_and_survived_days()
{
	std::cout << "\n";
	std::cout << "##### RUCH  " << moveAmount << std::endl;
	std::cout << "##### DZIEN " << survivedDays << std::endl;
}

void statistics::increase_survived_days()
{

	survivedDays++;
	refresh_move_amount();
}

int statistics::get_survived_days()
{
	return survivedDays;
}


