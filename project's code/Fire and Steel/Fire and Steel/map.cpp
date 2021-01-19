#include "map.h"
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include "map.h"
#include "mapElement.h"


map::map()
{
	mapElementHead = nullptr;
}


map::~map()
{
	this->mapElementHead = nullptr;
}

void map::set_last_element_coord(COORD aCoord)
{
	lastCoord = aCoord;
}

void map::set_last_line_number(int value)
{
	lastLineNumb = value;
}

void map::set_last_element_coord()
{
	mapElement *tmp = mapElementHead;

	while (tmp->get_next_element_address() != nullptr)
	{
		tmp = tmp->get_next_element_address();
	}
	lastCoord = tmp->get_element_coordinates();
}

void map::load_map()
{
	std::fstream mapFile;
	mapFile.open("map.txt", std::ios::in);

	std::string line;
	int cordY=0;
	while (mapFile)
	{
		int i = 0;
		std::getline(mapFile, line);
	
		while (i!=line.length())
		{
			mapElement * newElement = new mapElement(i, cordY,line[i]);
			add_map_element(mapElementHead,newElement);
			i++;
		}
		cordY++;
	}
	lastLineNumb = cordY-1;

	set_last_element_coord();

	mapFile.close();

	create_web();
}

void map::view_map()
{
	int compare = 0;
	mapElement *tmp = mapElementHead;
	while (compare != lastLineNumb)
	{
		while (tmp->get_element_coordinates().Y == compare)
		{
			if(tmp->get_layed_mark()==tmp->get_element_mark()) 
				std::cout << tmp->get_element_mark();


			else 
				std::cout << tmp->get_layed_mark();

			tmp = tmp->get_next_element_address();
		}
		compare++;
		std::cout << "\n";
	}
}

void map::add_map_element(mapElement *&mapHead,mapElement *&newElement)
{
	if (mapHead == nullptr)
		mapHead = newElement;
	else
		add_map_element(mapHead->get_next_element_address(), newElement);
}

void map::delete_map(mapElement *& mapHead)
{
	if (mapHead == nullptr)
		return;
	else
	{
		delete_map(mapHead->get_next_element_address());
		delete mapHead;
	}
}

mapElement * map::find_element_address(COORD elCord, mapElement *mapHead)
{

	if (mapHead == nullptr)
		return nullptr;
	else
	{

		if (mapHead->get_element_coordinates().X == elCord.X and mapHead->get_element_coordinates().Y == elCord.Y)
			return mapHead;

		find_element_address(elCord, mapHead->get_next_element_address());
	}
}

mapElement *& map::get_element_head()
{
	return mapElementHead;
}

void map::create_web()
{
	if (mapElementHead != nullptr)
	{
		mapElement *linkingElement = mapElementHead;
		

		while (linkingElement != nullptr)
		{
			COORD tmpCoord = linkingElement->get_element_coordinates();
			//up
			tmpCoord.Y--;
			linkingElement->set_up_ptr(find_element_address(tmpCoord, mapElementHead));
			tmpCoord.Y++;

			//down
            tmpCoord.Y++;
			linkingElement->set_down_ptr(find_element_address(tmpCoord, mapElementHead));
			tmpCoord.Y--;

			//left
			tmpCoord.X--;
			linkingElement->set_left_ptr(find_element_address(tmpCoord, mapElementHead));
			tmpCoord.X++;

			//right
			tmpCoord.X++;
			linkingElement->set_right_ptr(find_element_address(tmpCoord, mapElementHead));
			tmpCoord.X--;

			linkingElement = linkingElement->get_next_element_address();
		}
	}
}

COORD map::get_last_coord()
{
	return lastCoord;
}

int & map::get_last_line_number()
{
	return lastLineNumb;
}


