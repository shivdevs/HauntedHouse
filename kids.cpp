// Author: Harshiv Mistry
// Date: 10-29-2024
//
// File Name: kids.cpp
// This file contains the implementation of the Kids class derived from Attendees

/*
 * This file implements the Kids class, derived from the Attendees class in the haunted house
 * simulation project. The Kids class provides functionalities for interacting with various
 * elements in the maze, such as collecting candies, encountering dark corners, and facing
 * scary props. The class includes functions to spawn interactive elements, allow kids to
 * pick up candies, and display relevant information about the current state of the maze.
 * It also manages memory and integrates with the base class to display common attendee
 * details.
 */


#include "haunted_house.h"
using namespace std;

//default constructor
Kids::Kids(): candies(0), corners(0), props(0)
{}

//destructor
Kids::~Kids()
{
	candies = 0;
	corners = 0;
	props = 0;
}

//this function will spawn interactive elements of the location
//of a random amount.
int Kids::spawn_elements()
{
	candies = random_num(10, 50);
	corners = random_num(0, 1);
	props = random_num(0, 3);
	return candies + corners + props;
}

//this function will allow the kids to pickup candies that are 
//available in the given location and return amount of candies picked up.
int Kids::pick_up_candies()
{
	if (!candies)
	{
		cout	<< "\nSorry Kiddo!! no candies left :(\n";	
		return 0;
	}

	int res {0};	//used to store amount entered from the user.

	cout	<< "\nCandies available for u to take: " << candies << endl
		<< "How many would you like to take?\n ANS: ";
	cin 	>> res;
	cin.ignore(100, '\n');
	candies -= res;
	return res;
}

//this function will let the user experience the scaryness of dark corners.
int Kids::dark_corners()
{
	if (!corners) return 0;
	cout	<< "\nWoooo... \t you've entered a dark dark corner!!\n";
	--corners;
	return 0;
}

//this function will interact with the user in terms of the scary props 
//set in the location that are "guarding" the candies.
int Kids::scary_props()
{
	if (!props)	
	{
		cout	<< "\nIts your lucky day!!\n Candies are unguarded :/\n";
		return 0;
	}
	if (props == 1)
	{
		cout	<< "\nA very scary skeleton is guarding the candies!!\n";
	}
	else if (props == 2)
	{
		cout	<< "\nA very scary skeleton is guarding the candies!!\n"
			<< "Also a very scary ghost hidden in a pumpkin is guarding the candies!!\n";

	}
	else if (props == 3)
	{
		cout	<< "\nA very scary skeleton is guarding the candies!!\n"
			<< "Also a very scary ghost hidden in a pumpkin is guarding the candies!!\n"
			<< "With the Ghost, an army of spiders hanging from the ceiling right above the candies.\n";
	}
	return 1;
}

//this functions diplays the elements of the Kids class
//as well as calls it's parents class display function
void Kids::display()
{
	Attendees::display();
	cout	<< "\n *** Display from Kids *** \n"
		<< " 1. Candies: " << candies << endl
		<< " 2. Dark Corners: " << corners << endl
		<< " 3. Scary Props: " << props << endl;
	return;
}

