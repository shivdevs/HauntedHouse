// Author: Harshiv Mistry
// Date: 10-29-2024
//
// File_Name: vec.cpp
// This file contains the implementation of the member function for Vec class. 

/*
 * This file implements the Vec class, which manages a vector-based maze for dogs in the haunted 
 * house simulation project. The Vec class provides functionalities for building the maze by 
 * spawning elements at random locations, allowing the dog to move through the maze, and 
 * interacting with various elements such as treats, water, and guiding lights. Additionally, 
 * the class tracks the number of treats eaten and provides functions for displaying the current 
 * state of the maze.
 */


#include "haunted_house.h"

//default constructor
Vec::Vec(): treats_eaten(0), size(0)
{}

//destructor
Vec::~Vec()
{
	treats_eaten = 0;
	size = 0;
}

//this function will build the maze and also call ask
//spawn element fucntion so props are set.
int Vec::build_maze()
{
	size = dogs_maze[0].random_num(5,12);
	dogs_maze.resize(size);
	
	for (int i =0; i < size; ++i)
	{
		dogs_maze[i].spawn_elements();
	}
	return size;
}

//this function will let the dog move through the maze.
int Vec::user_start()
{
	int curr {0};
	int res {0};
	while (curr < size)
	{
		interact(curr);	
		++curr;
	}
	std::cout	<< "\n Treats eaten: " << treats_eaten << std::endl;
	return res;
}

//this function will let the dog interact with props at
//the given location.
int Vec::interact(int index)
{
	int res {0};
	treats_eaten += dogs_maze[index].eat_treats();
	res = dogs_maze[index].drink();
	res += dogs_maze[index].see_lights();
	return res;
}

//this function displays everything at all locations of the
//maze.
int Vec::display()
{
	for (int i =0; i < size; ++i)
		dogs_maze[i].display();
	return 1;
}


