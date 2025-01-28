// Author: Harshiv Mistry
// Date: 10-29-2024
/* * File_Name: haunted_house.h
 * This file contains the class definitions & function declarations for the Haunted House Project. 
 * 
 * 				*** OVERVIEW ***
 *
 * In this project, there will be a inheritence hierarchy for the classes as shown below: * 
 * 
 * 		       Attendees 
 * 				/  |  \
 * 		       /   |   \
 * 		      /    |    \
 * 		 Adults  Dogs   Kids
 * 		    /             \
 * 		   /               \
 * 		  /                 \
 * 	  AdultNode           KidNode
 * 
 * Attendees -- base class
 * 	Within the attendees class, common things about the attendees will be saved such as Name & Age.  * 	Responsibilites of this class will be things such as creating the mazes for attendees. 
 *  
 * Adults -- derived class from Attendees
 * 	Within the Adults class, special characteristics, and functions such the jumping skeletons, 
 * 	scary sound effects & actors dressed in scary costumes. 
 * 
 * Kids -- derived class from Attendees
 * 	Within the Kids class, special characteristics, and functions such as candies, 
 * 	scary props, dark corners. 
 * 
 * Dogs -- derived class from Attendees
 * 	Within the Dogs class, special characteristics, and functions such trail of treats, 
 * 	water cups, and guiding lights. 
 * 
 * 
 * These attendees' maze will be created using three different data structures as follows:
 *
 * Adults -- an Array of Linear Linked Lists will be used to implement a graph using an adajency list.
 *
 * Kids -- a Circular Linked List will be used to make a simple maze for kids with candies along the way. 
 *
 * Dogs -- a vector will be used to make a simple maze with treats along the way.
 */


//Libraries
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <random>

/* Responsibilites for the class:
 * 	- Gets and store logistical data about the user.
 * 	- Keeps track of the amount of times user was scared.
 * 	- Get feedback from the attendees about their experience.
 */
class Attendees	//Base class
{
	public:
		Attendees();		//default constructor
		~Attendees();		//destructor
		Attendees(const Attendees & src);	//copy constructor
		Attendees & operator=(const Attendees & src);	//assignment operator overloading.
		void display() const;	 	//will display the info about attendees.
		int random_num(int min, int max) const;		//generates a random number and returns it.
		int feedback();			//gets the rating for the attendees.	
		int scared();			//asks the user if they were scared after their interaction and updates the total count.
		void set_info(int user_type);	//needs to be called first thing from client to get user info
	protected:
		char * name; 		//stores the name of the attendees.
	private: 
		int rating; 		//will be used to get rating from the attendees (1-5) -- 5 being the highest.
		int attendee_type; 	//store the type of attendee -- 1 = adults, 2 = kids, 3 = dogs.
		int times_scared;	//stores the amount of time attendees were scared during their experience.
};



/* Characteristics:
 * 	- Skeleton traps will be set throughout the maze that will jump on the adults passing through the maze.
 * 	- Hole traps will be set that will lead the adults back to the starting point of the maze.
 * 	- Actors dressed in scary costumes will interact and scare the adults through the maze at different locations.
 * 	- Scary music and sound effects will be played at random intervals to scare the adults. 
 */ 
class Adults: public Attendees
{
	public:
		Adults();	//default constructor
		~Adults();	//destructor
		Adults(const Adults & src);	//copy constructor
		Adults & operator=(const Adults & src);	//assignment operator overloading.
		void display() const;			//displays all the elements
		int spawn_elements();		//sets up all the interactive elements.
		int interact_elements();	//helps user interact with elements in the location.
		int ask_reaction();		//prompts the user for their reaction and saves it.
	protected:
		char * reaction;	//stores the reaction of adults after prop interaction.	
	private:
		int skeletons; 		//number of skeletons that jump out.
		int sounds;		//number of times the scary sound plays at the location.
		int actors; 		//number of scary actors at the location.
		int trap;		//whether or not the location has a trap that goes back to start.
		
};

/* Characteristics:
 * 	- Candies will be placed throughout the maze with different amounts. 
 * 	- Kids will be able to pick the candies up.
 * 	- At some locations, scary props will be "guarding" the candies.
 * 	- Kids will sometimes go through dark corners. 
 */ 
class Kids: public Attendees
{
	public:
		Kids();	//default constructor
		~Kids();	//destructor
		int spawn_elements();	//function will set random amount of candies throughout the maze.
		int pick_up_candies(); 	//function will help kids pick candies up.
		int dark_corners();	//function will set scary dark corners in some parts of the maze.
		int scary_props();	//function will set scary props that are kid friendly in parts of the maze.
		void display();		//displays all current items and kickstarts parents display
	protected:
		int candies;	//stores number of candies available per node (location).
	private:
		int corners;	//stores whether or not the location is a dark corner.
		int props;	//stores scary props present at the location.
};

/* Characteristics:
 *	- Treats will be placed along the way to help guide the dogs through the maze.
 *	- Additionally water cups will be placed at intervals for dogs. 
 *	- Lighting that can guide dogs as well as sometimes scare them will be set in the maze.
 */ 
class Dogs: public Attendees
{
	public:
		Dogs();	//default constructor
		~Dogs();	//destructor
		int spawn_elements();	//treats guiding the dogs through the maze.
		int eat_treats(); 	//helps dog eat the treat and update their score.	
		int drink();		//helps the dog drink the water. 
		int see_lights();	//guiding lights to help progress through the maze.
		void display();		//displays items and kickstarts parents display.
	protected:
		int treats;	//will be used to keep track of treats eaten.
	private:	
		int water; 	//store 1 for if there is water and 0 if there isn't
		int guide_light;	//used to indicate a guide light. 
};

/*** Data Structure Classes ***/ 

/* This class will support ARR_LLL in building connections. This manages the nodes
 * of the individual indeces of the ARR_LLL, and holds the location of the possible connections
 * as data.
 */
class AdultNode: public Adults
{
	public:
		AdultNode();			//default constructor
		~AdultNode();			//destructor
		AdultNode & operator=(const AdultNode & src);	//assignment operator overloading
		AdultNode(const AdultNode & src);	//copy constructor
		void set_next(AdultNode * new_next);	//sets the next pointer to the passed in pointer.
		void set_location(int new_location);	//sets the location to the passed in int.
		AdultNode *& get_next();		//helps with recursion.
		int get_location() const;			//helps with recursion & maze movement.
		bool has_next() const;			//return true if there is a next, false if null.
		void display() const;			//displays the location & also kickstarts adults display
	private:
		int location; 	//holds the location of the connection.
		AdultNode * next; 	//pointer to the next node;
};


/* This class will manage the graph of the maze through the implementation of an
 * Adjacency List using an Array of Linear Linked Lists.
 */
class ARR_LLL
{
	public:
		ARR_LLL();			//default constructor
		ARR_LLL(const ARR_LLL & src);	//copy constructor w/ deepcopy
		~ARR_LLL();			//destructor
		ARR_LLL & operator=(const ARR_LLL & src);
		int build_ARR_LLL(int new_size);	//builds the adajency list of random size from 1 through 10.
		int display_all() const;		//displays all indeces, all nodes.
		int countNodes(int i) const;		//counts the number of nodes at index i.
		int remove_all();			//deletes the entire data structure.
		int remove(int index);			//removes the LLL at the passed in index.
		int insert(int index, int dest);	//inserts at the given index and destination
		int retrive(AdultNode & dest, int index, int loc); //copies info to the passed in object of the index and location
		int user_start(int index);		//starts the haunted house experience for the user on index.
	private:
		AdultNode ** head; 	//points to the Array of LLLs
		int size; 	//size of the adjacency list array
		int build_maze(AdultNode *& head, int l_size, int & curr);	//recursive builds the actual LLL.
		int build_rec(int & index);	//recursive building LLL at each index.
		int display_all(int & index) const;		//recursive for Array.
		int display_all(AdultNode * head) const;	//recursive for LLL.
		int countNodes(AdultNode * head) const;		//recursive for counting nodes	
		int remove_all(int & index);		//recursive for removeall.
		AdultNode * traverse(int index, int dest);	//helps with travel.
		AdultNode * traverse(AdultNode * head, int dest);	//help with travel. 
		int move(int index, int max);		//lets the user move through the maze.
};	

/* This class will as the node for the CLL implemented for the Kids class
 * Class is also derived from Kids -- will be able to access all functions all the way to the base class.
 */
class KidNode: public Kids
{
	public: 
		KidNode();		//default constructor
		KidNode(const KidNode & src);	//copy constructor
		~KidNode();		//destructor
		KidNode & operator=(const KidNode & src);	//assingment operator function
		void set_next(KidNode * new_next);	//sets the next to the passed in value.
		KidNode *& get_next();		//returns the next for recursion.
		bool has_next() const;		//returns true of there is a next.
	private:
		KidNode * next;
};


/* This class will manage the maze for attendee type kids, implemented using 
 * a Circular Linked List. 
 */
class CLL
{
	public:
		CLL();	//default constructor
		~CLL();		//destructor
		CLL(const CLL & src);	//copy constructor
		CLL & operator=(const CLL & src);	//assignment operator
		int build_CLL();	//builds the maze of a given size.
		int insert();	//inserts a new node into CLL
		int remove_all();	//removes all items in the CLL;
		int display_all() const;	//displays all items 
		int retrive(KidNode & dest);	//passed in obeject containes the retrived value
		int user_start();	//lets the user start the experience.
		int remove();		//lets the user remove the first node.
	private:
		KidNode * rear;		//points to the rear of the CLL.
		int candies_collected; 	//stores the candies collected.
		int insert(KidNode *& rear);
		int display_all(KidNode * rear) const; //displays all items of the list recursively
		int remove_all(KidNode *&rear);	//recursive for remove all
		int deep_copy(KidNode * src, KidNode * src_rear, KidNode *& dest);	//deep copies given src and dest.
		int build_rec(int & index, int size);	//helper for build function
};



/* This class manages the vector and operations for the Dogs class
 */
class Vec
{
	public:
		Vec();
		~Vec();
		int build_maze();	//build the maze of random size.
		int user_start();		//lets the dog move to next location.
		int interact(int index);		//lets the dog interact with the items in the maze.
		int display();		//displays all items.
	private:
		std::vector<Dogs> dogs_maze;	//vector as a simple maze.
		int treats_eaten;	//tracks the treats eaten by the dog.
		int size;	//size of the maze.
};
