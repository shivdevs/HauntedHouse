// Author: Harshiv Mistry
// Date: 10-29-2024
//
// File_Name: lll_node.cpp
// This file contains the implementation of the member functions of AdultNode Class.

/*
 * This file implements the AdultNode class, which is derived from the Adults class and 
 * represents a node in the linear linked list (LLL) used in the haunted house simulation project. 
 * The AdultNode class includes functionalities for setting and retrieving the location, 
 * linking to the next node, and displaying node-specific details. It also manages dynamic 
 * memory with a copy constructor, assignment operator, and destructor to ensure proper 
 * deep copying and cleanup of linked nodes.
 */


#include "haunted_house.h"


//default constructor
AdultNode::AdultNode(): location(0), next(nullptr){}

//copy constructor
AdultNode::AdultNode(const AdultNode & src): Adults(src), location(src.location), next(nullptr)
{
	if (src.next)
		next = new AdultNode(*src.next);
}

//assignment operator overloading.
AdultNode & AdultNode::operator=(const AdultNode & src)
{
	if (this != &src)
	{
		Adults::operator=(src);
		if (next)
			delete next;
		location = src.location;
		if (src.next)
		{
			next = new AdultNode(*src.next);
		}
		else
			next = nullptr;
	}
	return *this;
}

//destructor
AdultNode::~AdultNode()
{
	delete next;
	next = nullptr;
	location = 0;
}

//sets the passed in next to the private next.
void AdultNode::set_next(AdultNode * new_next)
{
	next = new_next;
}

//sets the location to the passed in value.
void AdultNode::set_location(int new_location)
{
	location = new_location;
}

//returns the next point for recursion.
AdultNode *& AdultNode::get_next()
{
	return next;
}

//returns the location
int AdultNode::get_location() const
{
	return location;
}
//return true if there is a next, false if there isn't.
bool AdultNode::has_next() const
{
	return next;
}

void AdultNode::display() const
{
	Adults::display();

	std::cout	<< "Location (node): " << location << std::endl;
}
