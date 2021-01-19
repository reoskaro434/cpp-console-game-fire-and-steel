
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "woodcuttersVillage.h"
#include "places.h"
#include "defineThings.h"
#include "obiect.h"
#include "items.h"
#include "character.h"


woodcuttersVillage::woodcuttersVillage(COORD aCord)
{
	set_place_name(woodcuttersName);
	set_place_coord(aCord);
	set_place();
	isThisPlayer = false;

}

void woodcuttersVillage::set_place()
{
	aItems.set_food ( (rand() % woodcuttersFood));
	aItems.set_iron ( (rand() % woodcuttersIron));
	aItems.set_wood ( (rand() % woodcuttersWood));
	aItems.set_army ( (rand() % woodcuttersArmy));
	aItems.set_gold ( (rand() % woodcuttersGold));
	aItems.set_munition ( ((rand() % woodcuttersMunition) + aItems.get_army()));
	aItems.set_tools ( (rand() % woodcuttersTools));

	aItems.set_foodCost(woodcuttersFoodCost);
	aItems.set_ironCost(woodcuttersIronCost);
	aItems.set_woodCost(woodcuttersWoodCost);
}

void woodcuttersVillage::trade_menu(character &aCharacter)
{


	*this >> aCharacter;

	while (aCharacter.keyManagerForCharacter.check_game_loop() == false)
	{
		if (_kbhit())
		{
			aTradeMenu.option_trade_menu_woodcutters(aCharacter, *this);

			//Showing trade menu.

			*this >> aCharacter;

		}
	}
	aCharacter.keyManagerForCharacter.set_end_loop(false);
}

woodcuttersVillage & woodcuttersVillage::operator>>(character & aCharacter)
{
	system("cls");
	std::cout << "Handel z wioska drwali" << std::endl;
	std::cout << "1.Drewno" << std::endl;
	std::cout << "2.Zywnosc" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Przedmioty bohatera." << std::endl;

	aCharacter.aItems.show_all_obiect_items();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Przedmioty wioski." << std::endl;
	this->aItems.show_wood_and_food();
	return *this;
}

void woodcuttersVillage::start_mission(character & aCharacter)
{
	aMission.do_mission(aCharacter);
}
