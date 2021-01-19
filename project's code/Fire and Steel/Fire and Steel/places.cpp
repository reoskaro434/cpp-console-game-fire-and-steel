#include "places.h"
#include "keyboardControls.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include "obiect.h"
#include "character.h"
#include "defineThings.h"
#include "fight.h"

places::places()
{
	nextPlace = nullptr;
}


int places::get_sleeping_cost()
{
	return sleepingCost;
}

void places::set_place_name(std::string name)
{
	placeName = name;
}

void places::set_place_coord(COORD aCord)
{
	obiectCoord = aCord;
}


places *& places::get_nextPlace()
{
	return nextPlace;
}

void places::set_place()
{
	

}

void places::start_mission(character & aCharacter)
{
}

void places::do_menu_interaction(character & aCharacter)
{
	aCharacter.keyManagerForCharacter.set_pressed_key();

	switch (aCharacter.keyManagerForCharacter.get_enum_key())
	{
	case keyboardControls ::one:
	{
		sleep_in(aCharacter);
	}break;
	case keyboardControls::two:
	{
		start_mission(aCharacter);
	}break;
	case keyboardControls::three:
	{
		trade_menu(aCharacter);
	}break;
	case keyboardControls::four:
	{
		this->aRecon.do_recon(this->aItems, aCharacter);

	}break;
	case keyboardControls::five:
	{
		
		this->start_battle(aCharacter);
	
	}break;
	case keyboardControls::keyEsc:
	{
		aCharacter.keyManagerForCharacter.set_end_loop(true);
	}break;
	default:
	{
	}break;
	}

	aCharacter.keyManagerForCharacter.clear_buffor();
}

places & places::operator>>(const std::string & placeName)
{
	system("CLS");
	std::cout << "Jestes w " << placeName << std::endl;
	std::cout << std::endl;
	std::cout << "1.Przespij sie." << std::endl;
	std::cout << "2.Popros o zadanie." << std::endl;
	std::cout << "3.Handluj." << std::endl;
	std::cout << "4.Przeprowadz zwiad." << std::endl;
	std::cout << "5.Zaatakuj." << std::endl;

	return *this;
}

void places::show_menu(character &aCharacter)
{
	*this >> placeName;

	while (aCharacter.keyManagerForCharacter.check_game_loop()==false)
	{
		if (_kbhit())
		{
			do_menu_interaction(aCharacter);

			*this >> placeName;

		}
	}
	aCharacter.keyManagerForCharacter.set_end_loop(false);

}
void places::trade_menu(character &aCharacter)
{
}


void places::sleep_in(character& tiredHero)
{
	if (tiredHero.aItems.get_gold() >= get_sleeping_cost())
	{
		aItems.set_gold(aItems.get_gold()+ sleepingCost);
		tiredHero.aStatistic.increase_survived_days();
		tiredHero.aItems.set_gold(tiredHero.aItems.get_gold() - sleepingCost);
		system("CLS");
		std::cout << "Wysypasz sie w bezpiecznym miejscu." << std::endl;
		Sleep(2000);
		system("CLS");
		pawn::scriptPlayerTurn = true;
	}
}

