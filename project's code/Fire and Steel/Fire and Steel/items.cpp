#include "items.h"
#include <iostream>



items::items()
{
	armyCost = 0;
	foodCost = 0;
	woodCost = 0;
	ironCost = 0;
	toolsCost = 0;
	munitionCost = 0;

	army = 0;
	gold = 0;
	food = 0;
	wood = 0;
	iron = 0;
	tools = 0;
	munition = 0;
}

items & items::operator+=(items & aItems)
{
	army += aItems.army;
	gold += aItems.gold;
	food += aItems.food;
	wood += aItems.wood;
	iron += aItems.iron;
	tools += aItems.tools;
	munition += aItems.munition;

	aItems.army = 0;
	aItems.gold = 0;
	aItems.food = 0;
	aItems.wood = 0;
	aItems.iron = 0;
	aItems.tools = 0;
	aItems.munition = 0;
	return *this;
}

void items::show_all_obiect_items()
{
	std::cout << "zloto      >" <<gold<< std::endl;
	std::cout << "zywnosc    >" <<food<< std::endl;
	std::cout << "zelazo     >" <<iron<< std::endl;
	std::cout << "drewno     >" <<wood<< std::endl;
	std::cout << "narzedzia  >" <<tools<< std::endl;
	std::cout << "uzbrojenie >" <<munition<< std::endl;

}

void items::show_wood_and_food()
{
	std::cout << "drewno     >" << wood << std::endl;
	std::cout << "zywnosc    >" << food << std::endl;
}

void items::show_iron_and_food()
{
	std::cout << "zelazo     >" << iron << std::endl;
	std::cout << "zywnosc    >" << food << std::endl;
}

void items::show_tools_and_food()
{
	std::cout << "narzedzia  >" << tools << std::endl;
	std::cout << "zywnosc    >" << food << std::endl;
}

void items::show_munition_and_inf_army()
{
	std::cout << "uzbrojenie >" << "ukryte" << std::endl;
	std::cout << "wojsko     >" <<"ukryte" << std::endl;
}

void items::show_all_obiect_items_and_army()
{
	std::cout << "zloto      >" << gold << std::endl;
	std::cout << "zywnosc    >" << food << std::endl;
	std::cout << "zelazo     >" << iron << std::endl;
	std::cout << "drewno     >" << wood << std::endl;
	std::cout << "narzedzia  >" << tools << std::endl;
	std::cout << "uzbrojenie >" << munition << std::endl;
	std::cout << "wojsko     >" <<army<< std::endl;
}

void items::set_army(int value)
{
	army = value;
}

void items::set_gold(int value)
{
	gold = value;
}

void items::set_food(int value)
{
	food = value;
}

void items::set_wood(int value)
{
	wood = value;
}

void items::set_iron(int value)
{iron = value;
}

void items::set_tools(int value)
{tools = value;
}

void items::set_munition(int value)
{
	munition = value;
}

int & items::get_army()
{
	return army;
}

int & items::get_gold()
{
	return gold;
}

int & items::get_food()
{
	return food;
}

int & items::get_wood()
{
	return wood;
}

int & items::get_iron()
{
	return iron;
}

int & items::get_tools()
{
	return tools;
}

int & items::get_munition()
{
	return munition;
}

int items::get_armyCost()
{
	return armyCost;
}

int items::get_foodCost()
{
	return foodCost;
}

int items::get_woodCost()
{
	return woodCost;
}

int items::get_ironCost()
{
	return ironCost;
}

int items::get_toolsCost()
{
	return toolsCost;
}

int items::get_munitionCost()
{
	return munitionCost;
}

void items::set_armyCost(int value)
{
	armyCost = value;
}


void items::set_foodCost(int value)
{
	foodCost = value;
}

void items::set_woodCost(int value)
{
	woodCost = value;
}

void items::set_ironCost(int value)
{
	ironCost = value;
}

void items::set_toolsCost(int value)
{
	toolsCost = value;
}

void items::set_munitionCost(int value)
{
	munitionCost = value;
}
