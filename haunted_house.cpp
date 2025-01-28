// Author: Harshiv Mistry
// Date: 10-29-2024
//
// File Name: haunted_house.cpp
// This file will act as a demo client to test functionality of the Haunted House Project.

/*
 * This file contains the main driver program for the haunted house simulation project. 
 * It allows users to choose between different attendee types (Adults, Kids, or Dogs) 
 * and experience unique interactions in the haunted house maze. The program provides 
 * options for testing various features, such as inserting nodes, retrieving data, 
 * displaying elements, and removing nodes for each attendee type. The file also handles 
 * user input for navigating the haunted house, managing the array of linked lists for 
 * adults, circular linked list for kids, and a vector-based maze for dogs.
 */


#include "haunted_house.h"
using namespace std;

int main()
{
	int response {0};	//used to get response for the user and create the apporiate object. 
	int temp {0};		//used to temporarily catch items from testing functions
	int num_a {0};		//stores the amount of adults for the haunted house.	
	int response2 {0};	//used to get response for the user and create the apporiate object.

	while (response2 != 4)
	{
		cout 	<< "*** Welcome to the Scary Haunted House ***" << endl
			<< "\nBefore we get started could you tell us who are you?\n"
			<< " 1. Adult\n"
			<< " 2. Child\n"
			<< " 3. Dog\n"
			<< " 4. Quit\n"
			<< "Your Answer: ";
		cin 	>> response2; 

		if (response2 == 1)
		{
			ARR_LLL my_adults;
			cout	<< "\nHow many adults? : ";
			cin 	>> num_a;
			cin.ignore(100, '\n');
			my_adults.build_ARR_LLL(num_a);

			while (response != 6)
			{
				cout	<< "\nWhat would you like to do?\n"
					<< " 1. Haunted House Experience\n"
					<< " 2. Test Insert Function\n"
					<< " 3. Test Retrival function\n"
					<< " 4. Display All\n"
					<< " 5. Remove\n"
					<< " 6. Quit\n"
					<< " ANS: ";
				cin	>> response;
				cin.ignore(100, '\n');
				if (response == 1)
				{
					while (num_a)
					{
						cout 	<< "\nWho wants to play? (1,2,3....) : ";
						cin 	>> response;
	
						temp = my_adults.user_start(response-1);
						--num_a;
					}
					my_adults.display_all();
				}
				else if (response == 2)
				{
					temp = my_adults.insert(0, 1);
					cout << "\nInserted a node at index 0, location 1.\n";
				}
				else if (response == 3)
				{
					AdultNode test_object;
					temp = my_adults.retrive(test_object, 0, 1);
					cout << "\nBelow is display results for the retrived object\n";
					test_object.display();
				}
				else if (response == 4)
				{
					temp = my_adults.display_all();
					cout	<< "\nDisplayed " << temp << " items.\n";
				}
				else if (response == 5)
				{
					temp = my_adults.remove(0);	
				}
				else if (response == 6)
					cout	<< "\nBack to Main Menu\n";
				else
					cout << "\nINVALID OPTION\n";
			}
		}		
		else if (response2 == 2)
		{
			CLL my_kids;
			my_kids.build_CLL();
			int response3 {0};
			int res{0};
			while (response3 != 7)
			{
				cout 	<< "\nWhat would you like to do?\n"
					<< " 1. Haunted House experience\n"
					<< " 2. Display_all\n"
					<< " 3. Test insert\n"
					<< " 4. Test remove\n"
					<< " 5. Test retrive\n"
					<< " 6. Test remove_all()\n"
					<< " 7. Quit\n"
					<< " ANS: ";
				cin 	>> response3;
				cin.ignore(100, '\n');
				
				if (response3 == 1)
				{
					res = my_kids.user_start();
					cout << "\nTotal candies collected: " << res << endl;
				}
				else if (response3 == 2)
				{
					res = my_kids.display_all();
					cout << "\nDisplayed " << res << " items.\n";
				}
				else if (response3 == 3)
				{
					res = my_kids.insert();
					cout << "Inserted " << res << " nodes.\n";
				}
				else if (response3 == 4)
				{
					res  = my_kids.remove();
					cout <<  "Removed " << res << " nodes.\n";
				}
				else if (response3 == 5)
				{
					KidNode test;
					res = my_kids.retrive(test);
					cout << "Retrived " << res << "nodes.\n";
				} 
				else if (response3 == 6)
				{
					res  = my_kids.remove_all();
					cout <<  "Removed " << res << " nodes.\n";

				}
				else if (response3 == 7)
					cout << "\nOk :) Out!!\n";
				else
					cout << "\nInvalid Option!\n";

			}
		}
		else if (response2 == 3)
		{
			int ret {0};
			Vec dog_maze;
			ret = dog_maze.build_maze();
			cout	<< "\nMaze built with size: " << ret << endl;
			ret = dog_maze.display();
			ret = dog_maze.user_start();
		}
		else if (response2 == 4)
			cout << "\n\tGood Bye:)) ......\n";
		else	
			cout << "\nInvalid Response!\n";
	}

	/* ***** Testing & Debugging ****** */

	//cout << temp;
	//temp = 1;
	//temp = 0;
	return 0;
}

