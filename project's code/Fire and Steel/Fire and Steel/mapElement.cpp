#include <Windows.h>
#include "mapElement.h"
#include "defineThings.h"



mapElement::mapElement(int X, int Y,char mark)
{

	if (mark == markWALL)
		walkable = false;
	else 
		walkable = true;

	elementCoordinates.X = X;
	elementCoordinates.Y = Y;
	
	mapMark = mark;
	layedMark =mark;
	
	this->nextElement = nullptr;

	nextElement = upElement = downElement = leftElement = rightElement = nullptr;
}

void mapElement::set_element_coordinates(COORD coordinates)
{
	this->elementCoordinates = coordinates;
}

void mapElement::set_map_mark(char mark)
{
	this->mapMark = mark;
}

void mapElement::set_layed_mark(char mark)
{
	this->layedMark = mark;
}

void mapElement::set_up_ptr(mapElement * ptr)
{
	upElement = ptr;
}

void mapElement::set_down_ptr(mapElement * ptr)
{
	downElement = ptr;
}

void mapElement::set_left_ptr(mapElement * ptr)
{
	leftElement = ptr;
}

void mapElement::set_right_ptr(mapElement * ptr)
{
	rightElement = ptr;
}

mapElement * mapElement::get_up_ptr()
{
	return upElement;
}

mapElement * mapElement::get_down_ptr()
{
	return downElement;
}

mapElement * mapElement::get_left_ptr()
{
	return leftElement;
}

mapElement * mapElement::get_right_ptr()
{
	return rightElement;
}

COORD mapElement::get_element_coordinates()
{
	return this->elementCoordinates;
}

char mapElement::get_element_mark()
{
	return this->mapMark;
}

mapElement *& mapElement::get_next_element_address()
{
	return this->nextElement;
}

void mapElement::set_next_element_address(mapElement *addres)
{
	this->nextElement = addres;
}

char mapElement::get_layed_mark()
{
	return this->layedMark;
}

bool mapElement::check_permission()
{
	return walkable;
}

