#include <Windows.h>
#include "town.h"
#include "places.h"
#include "defineThings.h"
#include <conio.h> 
#include <iostream>

town::town(COORD aCord)
{
	set_place_name(townName);
	set_place_coord(aCord);

	set_place();
	isThisPlayer = false;

}

void town::set_place()
{
	aItems.set_food ( (rand() % townFood));
	aItems.set_iron( (rand() % townIron));
	aItems.set_wood ( (rand() % townWood));
	aItems.set_army( (rand() % townArmy) + castleArmy);
	aItems.set_gold ( (rand() % townGold));
	aItems.set_munition ( ((rand() % townMunition) + aItems.get_army()));
	aItems.set_tools ( (rand() % townTools));

	aItems.set_foodCost(townFoodCost);
	aItems.set_toolsCost(townToolsCost);
}

void town::trade_menu(character & aCharacter)
{


	*this >> aCharacter;


	while (aCharacter.keyManagerForCharacter.check_game_loop() == false)
	{
		if (_kbhit())
		{
			aTradeMenu.option_trade_menu_town(aCharacter, *this);

			//Showing trade menu.

			*this >> aCharacter;

		}
	}
	aCharacter.keyManagerForCharacter.set_end_loop(false);
}

town & town::operator>>(character & aCharacter)
{
	system("cls");
	std::cout << "Handel z kupcami w miescie." << std::endl;
	std::cout << "1.Narzedzia." << std::endl;
	std::cout << "2.Zywnosc." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Przedmioty bohatera." << std::endl;

	aCharacter.aItems.show_all_obiect_items();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Przedmioty wioski." << std::endl;
	this->aItems.show_tools_and_food();

	return *this;
}

void town::start_mission(character & aCharacter)
{
	aMission.do_mission(aCharacter);
}
