// Author: Harshiv Mistry
// Date: 10-29-2024
//
// File Name: dogs.cpp
// This file contains the implementation of the Dogs class derived from Attendees.

/*
 * This file implements the Dogs class, which is derived from the Attendees class in a haunted 
 * house simulation project. The Dogs class defines interactions for dog attendees, including 
 * spawning elements such as treats, water cups, and guide lights within the maze. The class 
 * provides functions to allow dogs to eat treats, drink water, and follow guiding lights to 
 * move through the maze. The file also includes functions for displaying dog-specific information 
 * and integrating the parent class's display method. Memory management is handled with a 
 * destructor to reset the elements.
 */


#include "haunted_house.h"

//default constructor
Dogs::Dogs(): treats(0), water(0), guide_light(0)
{}

//destructor
Dogs::~Dogs()
{
	treats = 0;
	water = 0;
	guide_light = 0;
}

//This function will spawn random amount of elements at a given location
//within the maze.
int Dogs::spawn_elements()
{
	treats = random_num(1,5);
	water = random_num(0,1);
	guide_light = random_num(1,1);
	return 1;
}

//This function lets the dogs eat available treats. 
int Dogs::eat_treats()
{
	if (!treats) return 0;
	int response {0};
	std::cout	<< "\nTreats available: " << treats;
	std::cout	<< "\nHow many treats would you like?\n Ans: ";
	std::cin	>> response;
	std::cin.ignore(100, '\n');
	treats -= response;
	std::cout	<< "\nGood boy!! you ate " << response << " treats!\n";
	return response;
}

//This functions lets the dogs drink water from 
// the water cups.
int Dogs::drink()
{
	if (!water) 
	{
		std::cout	<< "\nAWWWW... No water, maybe go forward to get water.\n";
		return 0;
	}
	std::cout	<< "\nSlurp slurp!! The water is gone...\n";
	--water;
	return 1;
}

//This function guides the dogs to the
//next location.
int Dogs::see_lights()
{
	if (!guide_light) return 0;
	std::cout	<< "\n--------------->\n";
	--guide_light;	
	return 1;
}

//this fucntion will display all items in the given location and also
//kickstarts parents(Attendees) display function.
void Dogs::display()
{
	Attendees::display();
	std::cout	<< "\n *** Display from Dogs ***\n"
			<< " 1. Treats: " << treats << std::endl
			<< " 2. Water: " << water << std::endl
			<< " 3. Guide Lights: " << guide_light << std::endl;
	return;
}
