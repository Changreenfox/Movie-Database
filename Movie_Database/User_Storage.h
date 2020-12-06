#pragma once
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

#include "User.h"
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::unordered_map;
using std::vector;

class User_Storage
{
	//This section of the database involves storing usernames and passwords onto a file using maps
	//The original data structure should create the map from a file if one exists
	//If possible, write a function that stores any updated info back into the file
	/*
		The way it would work involves 2 steps:

		1)	seperate into to files, which are read as two arrays::: Username and password
		2)	The password is entered, matched to the location on file, run through the map, and then checked to see if the username map exists

		notes:	The password file will be in order of newly-entered user, whereas username is in order of index location after hash function
		*Use regex to check for valid inputs (all strings)
	*/

	//keys = passwords, values = usernames
	unordered_map<string, User*> database;

	//Adds a username & password to the map
	bool Add(string username, string password);
	//Removes a password & username pair from the map & vector
	bool Remove(string username, string password);
public:
	//Create the unordered map from a file if one exists, and leave blank if a file does not
	User_Storage();
	//Write the file of usernames and passwords, then end program (map deletes itself)
	~User_Storage();

	void printDatabase();
	User* login(string username, string password);
	User* createAccount();
};

