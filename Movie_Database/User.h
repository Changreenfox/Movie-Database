#pragma once
#include <string>
using std::string;
class User
{
	string username;
	string password;
	string preferences;
public:
	User();
	User(string username_, string password_, string preferences_ = "none");
	string getUsername();
	string getPreferences();
};

