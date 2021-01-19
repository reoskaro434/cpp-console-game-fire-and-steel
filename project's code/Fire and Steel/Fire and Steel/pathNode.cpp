#include "pathNode.h"




pathNode::pathNode()
{
	nextNode = nullptr;
	parent = nullptr;
}

void pathNode::calculate_H_value(COORD meta)
{
	int x, y;

	x = meta.X - this->aMapElement->get_element_coordinates().X;
	if (x < 0)
	{
		x = x * (-1);
	}
	y = meta.Y - this->aMapElement->get_element_coordinates().Y;
	if (y < 0)
	{
		y = y * (-1);
	}

	costH = x;
	costH += y;
}

void pathNode::calculate_G_value(COORD start)
{

	int x, y;

	x = start.X - this->aMapElement->get_element_coordinates().X;
	if (x < 0)
	{
		x = x * (-1);
	}
	y = start.Y - this->aMapElement->get_element_coordinates().Y;
	if (y < 0)
	{
		y = y * (-1);
	}

	costG = x;
	costG += y;
}

void pathNode::set_parent_for_element(pathNode *up, pathNode *down, pathNode *left, pathNode *right)
{

	if (up != nullptr)
	{
		if (up->parent == nullptr) 
			up->parent = this;		
	}
	if (down != nullptr)
	{
		if (down->parent == nullptr)
			down->parent = this;
	}
	if (left != nullptr)
	{
		if (left->parent == nullptr)
			left->parent = this;
	}
	if (right != nullptr)
	{
		if (right->parent == nullptr)
			right->parent = this;	
	}
}

mapElement *& pathNode::get_map_element_address()
{
	return aMapElement;
}

pathNode *& pathNode::get_next_node()
{
	return nextNode;
}

void pathNode::set_parent(pathNode * aNode)
{
	parent = aNode;
}

pathNode *& pathNode::get_parent()
{
	return parent;
}

pathNode & pathNode::operator=(mapElement *& anElement)
{
	this->aMapElement = anElement;
	return *this;
}

int pathNode::get_cost_F()
{
	return costF;
}

void pathNode::calculate(COORD start, COORD stop)
{
	calculate_H_value(stop);
	calculate_G_value(start);
	costF = costH;
	costF += costG;
}
