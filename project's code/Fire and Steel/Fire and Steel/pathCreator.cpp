#include "pathCreator.h"
#include "mapElement.h"
#include <iostream>
#include "defineThings.h"



pathCreator::pathCreator()
{
	pathMapElementForExport = nullptr;
	path = nullptr;
	closedList = nullptr;
	openList = nullptr;
}

mapElement *& pathCreator::find_path(COORD start, COORD stop)
{

	pathMapElementForExport = nullptr;
	path = nullptr;
	closedList = nullptr;
	openList = nullptr;

	//Saving coordinates.
	this->start = start;
	this->stop = stop;
	
	//Adding to open list start coord.
	add(start);

	//Finding smallest F value.
	*this-find_smallest_F();

	//Setting parent pointer to his own addres. It helps while creating path.
	closedList->set_parent(closedList);

	while (path == nullptr)
	{

		find_walkable_elements();

		set_parent_for_elements();

		*this-find_smallest_F();

		try_to_create_path();
	}

	create_path_for_export();
	
	delete_list(openList);
	delete_list(closedList);


	return pathMapElementForExport;
}

pathCreator & pathCreator::operator=(map & aMap)
{
	this->mapElementHead = aMap.get_element_head();
	this->lastCoord = aMap.get_last_coord();
	this->lastLineNumb = aMap.get_last_line_number();
	return *this;
}

pathCreator & pathCreator::operator^(pathNode *& aNode)
{
	  
	mapElement *tmpElementPtr = new mapElement(aNode->get_map_element_address()->get_element_coordinates().X, aNode->get_map_element_address()->get_element_coordinates().Y, markSPACE);

	if (pathMapElementForExport == nullptr)
	{

		this->pathMapElementForExport = tmpElementPtr;
	
		return*this;
	}
	else
	{
		mapElement *tmp = pathMapElementForExport;
		while (tmp->get_next_element_address() != nullptr)
		{
			tmp = tmp->get_next_element_address();
		}
		tmp->set_next_element_address(tmpElementPtr);
		return*this;
	}
	return *this;
}

pathCreator & pathCreator::operator+(pathNode *& aNode)
{
	if (openList == nullptr)
	{
		openList = aNode;
	
		return *this;
	}
	else
	{
		pathNode *tmp = openList;
		
		while (tmp->get_next_node() != nullptr)
			tmp = tmp->get_next_node();

		tmp->get_next_node() = aNode;

		return *this;
	}
}

pathCreator & pathCreator::operator-(pathNode * aNode)
{

	pathNode *tmp = closedList;

	
	if (tmp == nullptr)
	{
		closedList = aNode;
		this->disconnect_from_open_list(aNode->get_map_element_address());

		return *this;
	}
	else
	{
		
		while (tmp->get_next_node() != nullptr) tmp = tmp->get_next_node();
			
		tmp->get_next_node() = aNode;

		this->disconnect_from_open_list(aNode->get_map_element_address());

		return *this;
	}


}

pathNode * pathCreator::find_path_node(mapElement * whichNodeContain)
{
	pathNode *tmp = openList;

	while (tmp != nullptr)
	{
		if (tmp->get_map_element_address() == whichNodeContain) return tmp;
			
		tmp = tmp->get_next_node();
	}

	tmp = closedList;

	while (tmp != nullptr)
	{
		if (tmp->get_map_element_address() == whichNodeContain) return tmp;

		tmp = tmp->get_next_node();
	}

	return nullptr;
}

pathNode *& pathCreator::find_smallest_F()
{
	pathNode *smallestFElement;
	pathNode *tmp = openList;

	smallestFElement = tmp;
	
	if(tmp->get_next_node()!=nullptr)
	tmp = tmp->get_next_node();

	while (tmp != nullptr)
	{
		if (smallestFElement->get_cost_F() > tmp->get_cost_F())
		{
			smallestFElement = tmp;
		}
		tmp = tmp->get_next_node();
	}
	return smallestFElement;
}

pathNode * pathCreator::find_in_closed_list(mapElement * whichNodeContain)
{
	pathNode *tmp = closedList;

	while (tmp != nullptr)
	{
		if (tmp->get_map_element_address() == whichNodeContain) return tmp;

		tmp = tmp->get_next_node();
	}
	return nullptr;

}

pathNode * pathCreator::find_in_open_list(mapElement * whichNodeContain)
{
	pathNode *tmp = openList;

	while (tmp != nullptr)
	{
		if (tmp->get_map_element_address() == whichNodeContain) return tmp;

		tmp = tmp->get_next_node();
	}

	return nullptr;
}

void pathCreator::closed_list_delete_node(mapElement * addresFromNode)
{
	pathNode *tmp = closedList;
	pathNode *ghost = closedList;


	if (tmp->get_map_element_address() == addresFromNode)//If it is first node.
	{
		closedList = closedList->get_next_node();
		delete tmp;
		return;
	}
	else
	{
		tmp = tmp->get_next_node();
	}

	//Starting looking deep.

	while (tmp != nullptr)
	{
		if (tmp->get_map_element_address() == addresFromNode) 
		{
			ghost->get_next_node() = tmp->get_next_node();
			delete tmp;
			return;
		}
		tmp = tmp->get_next_node();
		ghost = ghost->get_next_node();
	}
	return;
}

void pathCreator::disconnect_from_open_list(mapElement * whichNodeContain)
{
	pathNode *tmp = openList;
	pathNode *ghost = openList;


	if (tmp->get_map_element_address() == whichNodeContain)
	{
		openList = openList->get_next_node();
		tmp->get_next_node() = nullptr;
		return;
	}
	else
	{
		tmp = tmp->get_next_node();
	}

	

	while (tmp != nullptr)
	{
		if (tmp->get_map_element_address() == whichNodeContain) 
		{
			ghost->get_next_node() = tmp->get_next_node();
			tmp->get_next_node() = nullptr;
			return;
		}
		tmp = tmp->get_next_node();
		ghost = ghost->get_next_node();
	}
	return;
}

void pathCreator::set_parent_for_elements()
{
	pathNode * tmp;
	tmp = closedList;

	while (tmp != nullptr)
	{
		//Setting parent for elements from open and closed list.
		tmp->set_parent_for_element(this->find_path_node(tmp->get_map_element_address()->get_up_ptr()), this->find_path_node(tmp->get_map_element_address()->get_down_ptr()), this->find_path_node(tmp->get_map_element_address()->get_left_ptr()), this->find_path_node(tmp->get_map_element_address()->get_right_ptr()));
		tmp = tmp->get_next_node();
	}
}

void pathCreator::find_walkable_elements()
{
	pathNode *tmp = closedList;

	while (tmp != nullptr)
	{
		//Up.
		if (tmp->get_map_element_address()->get_up_ptr() != nullptr and tmp->get_map_element_address()->get_up_ptr()->check_permission() == true) { //If element exist and is walkable. 

			if (this->find_in_closed_list(tmp->get_map_element_address()->get_up_ptr()) == nullptr and this->find_in_open_list(tmp->get_map_element_address()->get_up_ptr()) == nullptr)//If element is not in open or close list.
			{
				this->add(tmp->get_map_element_address()->get_up_ptr()->get_element_coordinates());
			}
		}

		//Down.
		if (tmp->get_map_element_address()->get_down_ptr() != nullptr and tmp->get_map_element_address()->get_down_ptr()->check_permission() == true) {

			if (this->find_in_closed_list(tmp->get_map_element_address()->get_down_ptr()) == nullptr and this->find_in_open_list(tmp->get_map_element_address()->get_down_ptr()) == nullptr)
			{
				this->add(tmp->get_map_element_address()->get_down_ptr()->get_element_coordinates());
			}
		}

		//Left.
		if (tmp->get_map_element_address()->get_left_ptr() != nullptr and tmp->get_map_element_address()->get_left_ptr()->check_permission() == true) {  

			if (this->find_in_closed_list(tmp->get_map_element_address()->get_left_ptr()) == nullptr and this->find_in_open_list(tmp->get_map_element_address()->get_left_ptr()) == nullptr)
			{
				this->add(tmp->get_map_element_address()->get_left_ptr()->get_element_coordinates());
			}
		}

		//Right.
		if (tmp->get_map_element_address()->get_right_ptr() != nullptr and tmp->get_map_element_address()->get_right_ptr()->check_permission() == true) { 

			if (this->find_in_closed_list(tmp->get_map_element_address()->get_right_ptr()) == nullptr and this->find_in_open_list(tmp->get_map_element_address()->get_right_ptr()) == nullptr)
			{
				this->add(tmp->get_map_element_address()->get_right_ptr()->get_element_coordinates());
			}
		}
		tmp = tmp->get_next_node();
	}
}

void pathCreator::add(COORD aCoord)
{
	pathNode *tmp = new pathNode;
	mapElement *tmpElement = this->find_element_address(aCoord, this->get_element_head());


	*tmp = tmpElement;
	tmp->calculate(start,stop);
	
	*this + tmp;//Adding to open list.
}


void pathCreator::try_to_create_path()
{
	path=this->find_in_closed_list_by_coords(stop);
}

pathNode * pathCreator::find_in_closed_list_by_coords(COORD stop)
{
	pathNode *tmp = closedList;

	while (tmp != nullptr)
	{
		if (tmp->get_map_element_address()->get_element_coordinates().X == stop.X and tmp->get_map_element_address()->get_element_coordinates().Y == stop.Y)
			return tmp;

		tmp = tmp->get_next_node();
	}
	return nullptr;
}

void pathCreator::create_path_for_export()
{
	go_through_parents_and_create_export_list(find_in_closed_list_by_coords(stop));
}

void pathCreator::go_through_parents_and_create_export_list(pathNode * aPathNodeHead)
{
	
	if (aPathNodeHead->get_parent() != aPathNodeHead)
	{
		go_through_parents_and_create_export_list(aPathNodeHead->get_parent());

		*this^aPathNodeHead;
	}
	return;
}

void pathCreator::add_map_element_to_export_list(mapElement *& additiveElement)
{
	
	if (pathMapElementForExport == nullptr)
	{
		pathMapElementForExport = additiveElement;
		return;
	}

	mapElement*tmp = pathMapElementForExport;
	while (tmp->get_next_element_address()!= nullptr)
	{
		tmp = tmp->get_next_element_address();
	}
	tmp->set_next_element_address(additiveElement);
	return;
}

void pathCreator::delete_list(pathNode * listHead)
{
	if (listHead == nullptr)
		return;
	else
	{
		delete_list(listHead->get_next_node());
		delete listHead;
	}
}
