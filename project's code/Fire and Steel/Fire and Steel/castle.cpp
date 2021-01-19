#include "castle.h"
#include <Windows.h>
#include "places.h"
#include "defineThings.h"
#include <iostream>
#include <conio.h>

castle::castle(COORD aCord)
{
	set_place_name(castleName);
	set_place_coord(aCord);

	set_place();
	isThisPlayer = false;

}

void castle::set_place()
{
	aItems.set_food( (rand() % castleFood));
	aItems.set_iron( (rand() % castleIron));
	aItems.set_wood( (rand() % castleWood));
	aItems.set_army ((rand() % castleArmy) + woodcuttersArmy);
	aItems.set_gold ( (rand() % castleGold));
	aItems.set_munition ( ((rand() % castleMunition) + aItems.get_army()));
	aItems.set_tools ( (rand() % castleTools));

	aItems.set_armyCost(castleArmyCost);
	aItems.set_munitionCost(castleMunitionCost);
}

void castle::trade_menu(character & aCharacter)
{


	*this >> aCharacter;


	while (aCharacter.keyManagerForCharacter.check_game_loop() == false)
	{
		if (_kbhit())
		{
			aTradeMenu.option_trade_menu_castle(aCharacter, *this);

			//Showing trade menu.

			*this >> aCharacter;

		}
	}
	aCharacter.keyManagerForCharacter.set_end_loop(false);
}

castle & castle::operator>>(character & aCharacter)
{
	system("cls");
	std::cout << "Mamy najlepszych wojownikow w krolestwie." << std::endl;
	std::cout << "1.Wojsko." << std::endl;
	std::cout << "2.Uzbrojenie." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Przedmioty bohatera." << std::endl;

	aCharacter.aItems.show_all_obiect_items_and_army();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Przedmioty wioski." << std::endl;
	this->aItems.show_munition_and_inf_army();

	return *this;
}

void castle::start_mission(character & aCharacter)
{
	aMission.do_mission(aCharacter);
}
