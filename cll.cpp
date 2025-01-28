// Author: Harshiv Mistry
// Date: 10-29-2024
//
// File_Name: cll.cpp
// This file contains the implementation of the member functions of CLLclass and KidNode class.

/*
 * This file implements the KidNode and CLL classes, used for managing a circular linked list (CLL) 
 * in a haunted house simulation, specifically for kids. The KidNode class represents nodes within 
 * the CLL and provides deep copying, assignment, and memory management functionality. The CLL class 
 * manages the overall linked list structure, allowing for the insertion, removal, and traversal 
 * of nodes. The file also includes recursive functions for deep copying, removing nodes, displaying 
 * all elements, and building the CLL. Memory management is handled with a copy constructor, 
 * assignment operator, and destructor to ensure proper dynamic memory allocation and deallocation.
 */



#include "haunted_house.h"

//default constructor 
KidNode::KidNode(): next(nullptr)
{

}

//destructor
KidNode::~KidNode()
{
	//delete next;
	//next = nullptr;
}

//copy constructor
KidNode::KidNode(const KidNode & src): Kids(src), next(nullptr)
{
	if (src.next)
		next = new KidNode(*src.next);
}

//assignment operator 
KidNode& KidNode::operator=(const KidNode & src)
{
	if (this != &src)
	{
		if (next)
			delete next;
		next = nullptr;

		Kids::operator=(src);

		if (src.next)
			next = new KidNode(*src.next);
	}
	return *this;
}

//sets the next of the node to the passed in next.
void KidNode::set_next(KidNode * new_next)
{
	next = new_next;
}

//returns the private next for recursion.
KidNode *& KidNode::get_next()
{
	return next;
}

//returns true if there is a next, false it there isn't
bool KidNode::has_next() const
{
	return next;
}


/************************** CLL class implementation from here to below *************************************/

//default constructor
CLL::CLL(): rear(nullptr), candies_collected(0)
{}


//destructor
CLL::~CLL()
{
	if (rear)
		//delete rear;
		remove_all();
	rear = nullptr;
	candies_collected = 0;
}

//copy constructor
CLL::CLL(const CLL & src): rear(nullptr), candies_collected(src.candies_collected)
{
	if (!src.rear) return;
	deep_copy(src.rear, src.rear, rear);
}

CLL & CLL::operator=(const CLL & src)
{
	if (this != &src)
	{
		remove_all();
		deep_copy(src.rear,src.rear,rear);
	}
	return *this;
}
//inserts a node into the CLL.
int CLL::insert()
{
	return insert(rear);
}

//recursive for inserting node into a CLL.
int CLL::insert(KidNode *& rear)
{
	if (!rear) //empty list
	{
		rear = new KidNode;
		rear->set_next(rear);
		rear->spawn_elements();
		return 1;
	}
	KidNode * hold = rear->get_next();
	rear->get_next() = new KidNode;
	rear->get_next()->set_next(hold);
	rear->get_next()->spawn_elements();
	return 1;
}

//public function for remove_all
int CLL::remove_all()
{
	if (!rear) return 0;
	KidNode * hold = rear->get_next();
	rear->set_next(nullptr);
	int num = remove_all(hold);
	//delete rear;
	rear = nullptr;
	return num;
}

//recursive for remove_all
int CLL::remove_all(KidNode *& rear)
{
	if (!rear) return 0;
	KidNode * hold = rear->get_next();
	delete rear;
	rear = hold;
	return 1 + remove_all(rear);
}
//displays all items in the list
int CLL::display_all() const
{
	if (!rear) return 0;
	return display_all(rear->get_next());
}


//recursive for display_all
int CLL::display_all(KidNode * rear) const
{
	if (!rear) return 0;
	if (rear == this->rear)
	{
		rear->display();
		return 1;
	}
	rear->display();
	return 1 + display_all(rear->get_next());
}

//this function can be use to perform a deep copy of the given 
//destination from src.
int CLL::deep_copy(KidNode * src, KidNode *src_rear, KidNode *& dest)
{
	if (!src) return 0;
	dest = new KidNode(*src);
	if (src == src_rear)	//only one or last one to copy
	{
		if (this->rear == nullptr)
			dest->set_next(dest);
		else
		{
			dest->set_next(this->rear->get_next());
		}
		this->rear = dest;
		return 1;
	}
	return 1 + deep_copy(src->get_next(), src_rear, dest->get_next());	
}

//this function retrives rear's data back to caller
int CLL::retrive(KidNode & dest)
{
	dest = *(rear->get_next());
	return 0;
}


//builds the CLL of random size
int CLL::build_CLL()
{
	int i {0};
	int size {10};
	return build_rec(i,size);
}

//builder helper of CLL build,
int CLL::build_rec(int & index, int size)
{
	if (index == size) return 0;
	int num = insert();
	++index;
	return num + build_rec(index, size);
}

//helps the user start the haunted house experience
int CLL::user_start()
{
	KidNode * curr = rear->get_next();
	rear->scary_props();
	rear->dark_corners();
	candies_collected += rear->pick_up_candies();
	while (curr != rear)
	{
		curr->scary_props();
		curr->dark_corners();
		candies_collected += curr->pick_up_candies();
		std::cout << "\nMoving on....\n";
		curr = curr->get_next();
	}

	return candies_collected;
}

//removes the first node from the CLL.
int CLL::remove()
{
	if (!rear) return 0;
	KidNode * hold = rear->get_next()->get_next();
	delete rear->get_next();
	rear->set_next(hold);
	return 1;
}
