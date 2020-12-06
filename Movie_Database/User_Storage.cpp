#include "User_Storage.h"
//Load the user database and create the object
User_Storage::User_Storage()
{
	cout << "Opening User Database" << endl;

	ifstream dfile = ifstream("Database.txt");
	//If passwords exist
	if (dfile.is_open())
	{
		string password;
		string username;
		string preferences;
		//Read in database
		while (getline(dfile, username, ' '))
		{
			getline(dfile, password, ' ');
			getline(dfile, preferences);
			User* curr = new User(username, password, preferences);
			database[password] = curr;
		}
	}

	cout << "User Database has been opened" << endl;
}

//When program is finished, write the User login information in-file
User_Storage::~User_Storage()
{
	cout << "Writing down database changes" << endl;

	ofstream dfile = ofstream("Database.txt");
	string line;
	if (dfile.is_open())
	{
		for (auto iter = database.begin(); iter != database.end(); ++iter)
		{
			line = iter->second->getUsername() + " " + iter->first + " " + iter->second->getPreferences();
			dfile << line.c_str() << endl;
		}
	}
}

//Simply prints database for testing purposes
void User_Storage::printDatabase()
{
	auto iter = database.begin();
	for (; iter != database.end(); ++iter)
	{
		cout << iter->second->getUsername() << " " << iter->first << endl;
	}
}

User* User_Storage::createAccount()
{
	string username, password, password2;
	do
	{
		cout << "Enter new username: ";
		cin >> username;
		cout << "\nEnter new password: ";
		cin >> password;
		cout << "\nVerify password: ";
		cin >> password2;
		if (password != password2)
			cout << "\nThose passwords do not match" << endl;
	} while (password != password2);
	Add(username, password);
	return login(username, password);
}

//Checks to see if the user exists
//Will also eventually load user preferences
User* User_Storage::login(string username, string password)
{
	auto iter = database.find(password);
	if (iter == database.end() || iter->second->getUsername() != username)
	{
		cout << "That login does not exist" << endl;
		return nullptr;
	}
	//Will load in user preferences here
	cout << "Login successful" << endl;
	return iter->second;
}

//Returns true if the database item was successfully removed
bool User_Storage::Add(string username, string password)
{
	auto iter = database.find(password);
	if (iter != database.end())
	{
		cout << "That password is already in use" << endl;
		return false;
	}
	User* newUser = new User(username, password);
	database[password] = newUser;
	return true;
}

//Returns true if the database item was successfully removed
bool User_Storage::Remove(string username, string password)
{
	auto iter = database.find(password);
	if (iter == database.end() || iter->second->getUsername() != username)
	{
		cout << "That login does not exist" << endl;
		return false;
	}
	delete iter->second;
	database.erase(iter);
	return true;
}