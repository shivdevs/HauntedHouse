// Author: Harshiv Mistry
// Date: 10-29-2024
//
// File Name: adults.cpp
// This file contains the implementation for the Adults class that is derived from Attendees.


/*
 * This file implements the Adults class, which is derived from the Attendees class in a haunted
 * house simulation project. The Adults class defines interactive elements specific to adult
 * attendees, such as skeleton traps, scary sound effects, and actors in costumes. The class
 * handles the setup of these elements, allows users to interact with them, and tracks their
 * reactions. It includes functionality for displaying attendee and adult-specific information,
 * randomizing the elements, and managing memory for dynamic strings. The file also implements
 * a copy constructor, assignment operator, and destructor to handle dynamic memory and ensure
 * proper object copying.
 */

#include "haunted_house.h"
using namespace std;

//default constructor
Adults::Adults(): reaction(nullptr), skeletons(0), sounds(0), actors(0), trap(0)
{}

//copy constructor
Adults::Adults(const Adults & src): Attendees(src), reaction(nullptr), skeletons(src.skeletons), sounds(src.sounds), actors(src.actors), trap(src.trap)
{
	if (this != &src)
	{
		if (reaction) 
			delete[] reaction;
		if (src.reaction)
		{
			int size = strlen(src.reaction);
			reaction = new char[size+1];
			strcpy(reaction, src.reaction);
		}
		else 
			reaction = nullptr;
	}

}

//assignment operator overloading.
Adults & Adults::operator=(const Adults & src)
{
	if (this != &src)
	{
		Attendees::operator=(src);
		if (reaction) 
			delete[] reaction;
		if (src.reaction)
		{
			int size = strlen(src.reaction);
			reaction = new char[size+1];
			strcpy(reaction, src.reaction);
		}
		else
			 reaction = nullptr;
		skeletons = src.skeletons;
		sounds = src.sounds;
		actors = src.actors;
		trap = src.trap;
	}
	return *this;

}
//destructor
Adults::~Adults()
{
	delete[] reaction;
	reaction = nullptr;
	skeletons = 0;
	sounds = 0;
	actors = 0;
	trap = 0;
}

//This function kickstarts parents display and displays its own items as well.
void Adults::display() const
{
	//calling the parent class display.
	Attendees::display();

	cout 	<< "\n **** Display from Adults **** \n"
		<< " 1. Skeletons: " << skeletons << endl
		<< " 2. Sounds: " << sounds << endl
		<< " 3. Actors: " << actors << endl
		<< " 4. Traps: " << trap << endl;
	if (reaction)
		cout 	<< " 5. Reaction: " << reaction << endl;
	else
		cout 	<< " 5. Reaction: <empty>\n";
	return;
}

//Sets up all the interactive elements in places to be at a random.
int Adults::spawn_elements()
{
	skeletons = Attendees::random_num(0,3);
	sounds = Attendees::random_num(0,3);
	actors = Attendees::random_num(0,2);
	//trap = Attendees::random_num(0,1);
	return 1;
}

//lets the user interact with the elements places in the room.
int Adults::interact_elements()
{
	if (trap == 1) 
	{
		cout	<< "\n\n OH NOOOO... \nIt seems you feel through a hole :0\n";
		return -1;	//sends the signal to restart.	
	}
	for (int i = 0; i < skeletons; ++i)
	{
		cout 	<< "\nBOOOOO... \nA skeleton just jumped out at you!!\n";
		Attendees::scared();
	}	
	if (sounds == 1)
	{
		cout	<< "\n Ah hahahahaha (in a scary tone)!!!\n";
		Attendees::scared();
	}
	else if (sounds == 2)
	{
		cout	<< "\n Ah hahahahaha (in a scary tone)!!!\n"
			<< ".......\n"
			<< ".......\n"
			<< ".......\n"
			<< "\n Dum dhadum dum.... cheeccccck (things falling, and door creakly opens)!!!\n";
		Attendees::scared();
	}
	else if (sounds == 3)
	{
		cout	<< "\n Ah hahahahaha (in a scary tone)!!!\n"
			<< ".......\n"
			<< ".......\n"
			<< ".......\n"
			<< "\n Dum dhadum dum.... cheeccccck (things falling, and door creakly opens)!!!\n"
			<< ".......\n"
			<< ".......\n"
			<< ".......\n"
			<< "\n BOOOO... GET OUT OF HERE!!!! (A witch screams at you)\n";
		Attendees::scared();
	}

	for (int i = 0; i < actors; ++i)
	{
		cout 	<< "\nBOOOOO... \nYou got pushed by a scary actor!!\n";
		Attendees::scared();
	}	
	int temp = ask_reaction();
	return 1 + temp;
}


//This function asks the user about their reaction and saves it after they encounter 
//all the props.
int Adults::ask_reaction()
{
	if (reaction) 
		delete[] reaction;	
	reaction = new char[100];
	cout	<< "\nWhat was your reaction after all this??\n"
		<< "Did you like it?\n"
		<< "Was it thrilling??\n"
		<< "Response: ";
	cin 	>> reaction;
	cin.ignore(100, '\n');
	return 1;
}
