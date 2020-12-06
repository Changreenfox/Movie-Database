#include "User.h"

User::User()
{
	username = "";
	password = "";
	preferences = "";
}

User::User(string username_, string password_, string preferences_)
{
	username = username_;
	password = password_;
	preferences = preferences_;
}

string User::getUsername()
{
	return username;
}

string User::getPreferences()
{
	return preferences;
}