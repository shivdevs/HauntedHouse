// Author: Harshiv Mistry
// Date: 10-29-2024
//
// File Name: attendees.cpp
// This file contains the implementation of the Attendees base class.

/*
 * This file implements the Attendees class, which serves as the base class for all attendees
 * in a haunted house simulation. It manages common attributes such as name, attendee type,
 * rating, and the number of times the attendee was scared. The class includes functions for
 * setting and displaying attendee information, generating random numbers, gathering feedback,
 * and tracking reactions during the maze experience. It also provides memory management
 * features with a copy constructor, assignment operator, and destructor to handle dynamic
 * memory allocation for the attendee's name.
 */


#include "haunted_house.h"
using namespace std;

//default constructor
Attendees::Attendees(): name(nullptr), rating(0), attendee_type(0), times_scared(0) {}

//copy constructor
Attendees::Attendees(const Attendees & src):name(nullptr), rating(src.rating), attendee_type(src.attendee_type), times_scared(src.times_scared)
{
	if (this != &src)
	{
		if (name) 
			delete[] name;
		if (src.name)
		{
			int size = strlen(src.name);
			name = new char[size+1];
			strcpy(name, src.name);
		}
		else
			name = nullptr;
	}
}

//assignment operator overloading.
Attendees & Attendees::operator=(const Attendees & src)
{
	if (this != &src)
	{
		if (name) 
			delete[] name;
		if (src.name)
		{
			int size = strlen(src.name);
			name = new char[size+1];
			strcpy(name, src.name);
		}
		else
			name = nullptr;
		rating = src.rating;
		attendee_type = src.attendee_type;
		times_scared = src.times_scared;
	}
	return *this;
}
//destructor
Attendees::~Attendees()
{
	rating = 0;
	attendee_type = 0;
	times_scared = 0;
	delete[] name;
	name = nullptr;
}

//The function will prompt the user for basic info and set it for the attendees base class.
void Attendees::set_info(int user_type)
{
	char * temp_name = new char[50];

	cout	<< "\nWe would like some more info before you can begin!\n"
		<< "Name: ";
	cin 	>> temp_name;
	cin.ignore(100, '\n');

	int length = std::strlen(temp_name);
	name = new char[length+1];
	std::strcpy(name, temp_name);
	attendee_type = user_type;

	delete[] temp_name;
	temp_name = nullptr;
	length = 0;
}

//The function displays all info, return 0 if not set, return 1 if set.
void Attendees::display() const
{
	if (!name || !attendee_type) return; 
	cout 	<< "\n *** Display Attendees ***\n"
		<< "1. Name: " << name << endl
		<< "2. Attendee_type: " << attendee_type << endl
		<< "3. Rating: " << rating << endl
		<< "4. Times Scared: " << times_scared << endl << endl;
}

//The function takes in min and max values and return a random num 
//within the bounds.
int Attendees::random_num(int min, int max) const
{
	random_device rd;
	mt19937 gen(rd());	//gets the random num	
	uniform_int_distribution<> distrib(min,max);
	return distrib(gen);
}

//This function asks the user for rating their experience and stores it in
//rating.
int Attendees::feedback()
{	
	cout	<< "\nThank you for visiting our Haunted House!!"
		<< "\nHope you had fun!!"
		<< "\n\nWe would love hear about your experience!"
		<< "\nPlease give us a rating from 1-5, 5 being the highest"
		<< "\nRating: ";
	cin 	>> rating;
	cin.ignore(100, '\n');
	return 1;
}

//This function asks the user if they were scared at point in maze. Depending on the
//users answer, updates the count that tracks amount of time scared.
int Attendees::scared()
{
	int answer {0};
	cout	<< "\nBe honest, were you scared?"
		<< "\n 	1. Yes"
		<< "\n 	2. No"
		<< "\nAns:  ";
	cin 	>> answer;
	cin.ignore(100, '\n');

	if (answer == 1)
		++times_scared;
	return 1;
}
