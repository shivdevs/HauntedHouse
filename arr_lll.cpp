// Author: Harshiv Mistry
// Date: 10-29-2024
//
// File_Name: arr_lll.cpp
// This file contains the implementation of the member functions of ARR_LLL class and AdultNode Class.

/*
 * This file implements the ARR_LLL class, which manages a graph of the maze for adults using an
 * array of linear linked lists (LLL) in a haunted house simulation project. The class provides
 * functions for building the maze, inserting and removing nodes, traversing through nodes,
 * counting nodes, and displaying all nodes. It supports recursive operations for building the
 * maze and removing all nodes, and also manages dynamic memory for the linked list structure
 * with a copy constructor, assignment operator, and destructor.
 */


#include "haunted_house.h"

//default constructor
ARR_LLL::ARR_LLL(): head(nullptr), size(0) {}


//copy constructor
ARR_LLL::ARR_LLL(const ARR_LLL & src): head(nullptr), size(src.size)
{
	head = new AdultNode*[size];
	for (int i = 0; i < size; ++i)
	{
		if (src.head[i])
			head[i] = new AdultNode(*src.head[i]);
		else
			head[i] = nullptr;
	}	
}

//assignment operator implementation
ARR_LLL & ARR_LLL::operator=(const ARR_LLL & src)
{
	if (this != & src)
	{
		remove_all();
		size = src.size;

		head = new AdultNode*[size];

		for (int i = 0;i < size; ++i)
		{
			if (src.head[i])
				head[i] = new AdultNode(*src.head[i]);
			else
				head[i] = nullptr;
		}
	}
	return *this;
}
//destructor
ARR_LLL::~ARR_LLL()
{
	remove_all();	//calls the function that removes everything.
}

//this function builds the actual ARRAY of passed in size.
int ARR_LLL::build_ARR_LLL(int new_size)
{
	head = new AdultNode*[new_size];
	size = new_size;
	int index = 0;
	int num = build_rec(index);
	return 1 + num;
}

//this function helps build_arr_lll in building the maze by recursively calling build_maze that builds all the individual LLLs.
int ARR_LLL::build_rec(int & index)
{
	if (index >= size) return 1;	//basecase.
	int cur = 0;
	head[index] = new AdultNode;
	head[index]->set_info(1);
	int num = build_maze(head[index], head[index]->random_num(5,12), cur);
	++index;
	return num + build_rec(index);	
}


int ARR_LLL::build_maze(AdultNode *& head, int l_size, int & curr)
{
	if (curr >= l_size) return 1;
	if (!head)
	{
		//AdultNode * temp = head;
		head = new AdultNode;
		//head->set_next(temp);
		head->spawn_elements();
		head->set_location(curr);
	}
	++curr;
	return build_maze(head->get_next(), l_size, curr);	
}

int ARR_LLL::display_all() const
{
	if (!head) return 0;
	int i = 0;
	//for (int i = 0; i < size; ++i)
	//display_all(head[i]);
	return display_all(i);
	//return 1;
}

int ARR_LLL::display_all(int & index) const
{	
	if (index >= size) return 1;
	int num = display_all(head[index]);
	++index;
	return num + display_all(index);
}


int ARR_LLL::display_all(AdultNode * head) const
{
	if (!head) return 1;
	head->display();
	return display_all(head->get_next());
}

//counts the number of nodes in the given LLL at index i
int ARR_LLL::countNodes(int i) const
{
	if (!head) return 0;
	return countNodes(head[i]);
}

//recursive private function for counting nodes.
int ARR_LLL::countNodes(AdultNode * head) const
{
	if (!head) return 0;
	return 1 + countNodes(head->get_next());
}

//deletes all nodes from all indeces and also deletes the array.
int ARR_LLL::remove_all()
{
	if (!head) return 0;
	int index = 0;
	int num = remove_all(index);
	delete[] head;
	head = nullptr;
	return num;
}

//recursive function that helps delete all nodes frmom all indeces.
int ARR_LLL::remove_all(int & index)
{
	if (index >= size) return 0;
	delete head[index];
	++index;
	return 1 + remove_all(index);
}


//removes the LLL at the passed in index.
int ARR_LLL::remove(int index)
{
	if (index > size || index < 0) return 0;
	delete head[index];
	return 1;
}

//travels to the given location. 
AdultNode * ARR_LLL::traverse(int index, int dest)
{
	return traverse(head[index], dest);
}

//recursive to traverse to the given location.
AdultNode * ARR_LLL::traverse(AdultNode * head, int dest)
{
	if (!head) return nullptr;
	if (head->get_location() == dest) return head->get_next();
	return traverse(head->get_next(), dest);
}
//inserts at the passed in location.
int ARR_LLL::insert(int index, int dest)
{
	if (index > size || index < 0) return 0;
	AdultNode * my_head = traverse(index, dest);	
	AdultNode * to_add = new AdultNode; to_add->set_next(my_head->get_next()); my_head->set_next(to_add);
	return 1;
}


//retrives data at the given location and destination
int ARR_LLL::retrive(AdultNode & dest, int index, int loc)
{
	AdultNode * temp = traverse(index, loc);
	dest = *temp;
	return 1;
}

//starts the user experience and can call necessary things.
int ARR_LLL::user_start(int index)
{
	if (index > size || index < 0) return 0;
	int temp =0;
	temp = move(index, countNodes(index));
	std::cout	<< "\nOut the doors...\nCome again!!\n";
	return temp;
}

//lets the user move within in the LLL at the given array
int ARR_LLL::move(int index, int max)
{		
	if (index > size || index < 0) return 0;
	int user_choice =0;
	AdultNode * curr = nullptr;
	int ret =0;		//holds the returned values for the interact elements function;
	curr = traverse(index, 0);	
	do
	{
		std::cout	<< "\nWhich direction do you wanna go?\n"
			<< " 1. Forward\n"
			<< " 2. Backwards\n"
			<< " 3. Jump Ahead (move 2 times)\n"
			<< " ANS: ";
		std::cin 	>> user_choice;

		if (user_choice == 1)
		{
			curr  = traverse(index, curr->get_location()+1);
			if (curr)
				ret = curr->interact_elements();	
		}
		else if (user_choice == 2)
		{
			if (curr->get_location() == 0)
				std::cout	<< "\nNo back!!\n";
			curr = traverse(index, curr->get_location()-1);
			if (curr)
				ret = curr->interact_elements();	

		}
		else if (user_choice == 3)
		{
			curr = traverse(index, curr->get_location()+2);
			if (curr)
				ret = curr->interact_elements();	
		}
		else
			std::cout << "\nInvalid Choice!\n";
		if (ret == -1)
		{
			curr = traverse(index, 0);
			if (curr) 
				ret = curr->interact_elements();
		}
	}while (curr && curr->get_location() < max);
	return 1;
}
