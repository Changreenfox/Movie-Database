
#include "User_Storage.h"
int main()
{
	User_Storage database;
	User* current;
	database.printDatabase();
	string option;
	string username, password;
	cout << "Login or Create an Account: (L or C)";
	cin >> option;
	if (option == "C")
		current = database.createAccount();
	else if (option == "L")
	{
		cout << "Username: ";
		cin >> username;
		cout << "\nPassword: ";
		cin >> password;
		current = database.login(username, password);
	}
	else
	{
		cout << "Not currently an option" << endl;
	}
}