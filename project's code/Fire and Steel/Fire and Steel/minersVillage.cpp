#include "minersVillage.h"
#include <Windows.h>
#include "defineThings.h"
#include <conio.h>
#include "iostream"


minersVillage::minersVillage(COORD aCord)
{
	set_place_name(minersName);
	set_place_coord(aCord);
	
	set_place();
	isThisPlayer = false;

}

void minersVillage::set_place()
{
	aItems.set_food((rand() % minersFood));
	aItems.set_iron((rand() % minersIron));
	aItems.set_wood((rand() % minersWood));
	aItems.set_army((rand() % minersArmy));
	aItems.set_gold((rand() % minersGold));
	aItems.set_munition(((rand() % minersMunition)+aItems.get_army()));
	aItems.set_tools((rand() % minersTools));

	aItems.set_foodCost(minersFoodCost);
	aItems.set_ironCost(minersFoodCost);
	aItems.set_woodCost(minersWoodCost);
}

void minersVillage::trade_menu(character & aCharacter)
{


	*this >> aCharacter;


	while (aCharacter.keyManagerForCharacter.check_game_loop() == false)
	{
		if (_kbhit())
		{
			aTradeMenu.option_trade_menu_miners(aCharacter, *this);

		//Showing trade menu.

			*this >> aCharacter;

		}
	}
	aCharacter.keyManagerForCharacter.set_end_loop(false);
}

minersVillage & minersVillage::operator>>(character & aCharacter)
{
	system("cls");
	std::cout << "Handel z wioska gornikow." << std::endl;
	std::cout << "1.Zelazo" << std::endl;
	std::cout << "2.Zywnosc" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Przedmioty bohatera." << std::endl;

	aCharacter.aItems.show_all_obiect_items();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Przedmioty wioski." << std::endl;
	this->aItems.show_iron_and_food();

	return *this;
}

void minersVillage::start_mission(character & aCharacter)
{
	aMission.do_mission(aCharacter);
}
