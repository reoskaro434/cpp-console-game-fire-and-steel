#include <iostream>
#include "character.h"
#include "defineThings.h"
#include "scriptPlayer.h"


void character::sleep()
{
	system("CLS");
	std::cout << "Zzzz.." << std::endl;
	Sleep(timeForRead);
	system("CLS");
	pawn::scriptPlayerTurn = true;
	aStatistic.increase_survived_days();
}

void character::create_character(map & aMap,COORD aCoord)
{

	set_obiect_coord(aCoord);

	set_address_of_stay(aMap.find_element_address(aCoord, aMap.get_element_head()));

}

void character::show_character_items()
{
	system("cls");
	std::cout << "***** Przedmioty bohatera *****"<<std::endl;
	std::cout << std::endl;
	aItems.show_all_obiect_items_and_army();

	system("pause");
}



character::character()
{
	obiectCoord.X = theX;
	obiectCoord.Y = theY;
	pawnMark = markCHARACTER;

	addressOfStay = nullptr;

	aItems.set_food(characterFood);
	aItems.set_gold(characterGold);
	aItems.set_munition(characterMunition);
	aItems.set_army(characterArmy);
	aItems.set_iron(characterIron);
	aItems.set_wood(characterWood);
	aItems.set_tools(characterTools);

	isThisPlayer = true;
	
}
