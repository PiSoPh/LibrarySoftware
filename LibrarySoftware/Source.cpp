#include "Publications.h"
#include "Audiobooks.h"
#include "Books.h"
#include "Computergames.h"
#include "Customer.h"
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	//Buffer for userinput
	char chCustInputBuffer;
	string strCustInputBuffer;// string to avoid buffer overflow error in login-function
	int iCustInputBuffer = 0;
	bool wrongInput = false;
	bool exit = false; //to skip out of the program prematurely
	int roundcount = 0; //ensuring that menu is not listed everytime
	int borrowCount = 0; //to ensure that customer can only borrow two items at a time

	//initialise library
	auto library = new Publications();
	library->fillLib();

	//Options that can be accessed without registration
	while (iCustInputBuffer != 6 && iCustInputBuffer != 5)
	{
		cout << "What would you like to do? " << endl;
		if ((roundcount == 0) || iCustInputBuffer == 4)
		{
			cout << "1. List all books available " << endl;
			cout << "2. List all Computer Games available " << endl;
			cout << "3. List all Audiobooks available " << endl;
			cout << "4. Menu" << endl;
			cout << "5. Login" << endl;
			cout << "6. Exit" << endl;
		}
		cin >> strCustInputBuffer;
		stringstream(strCustInputBuffer) >> iCustInputBuffer; //failsafe in case cust types in wrong value

		switch (iCustInputBuffer)
		{
		case 1: library->list(library->getVector("book")); break;
		case 2: library->list(library->getVector("computergame")); break;
		case 3: library->list(library->getVector("audiobook")); break;
		case 5: exit = false; break;
		case 6: exit = true; break;
		}
		roundcount++;


	}
	roundcount = 0;
	if (!exit)
	{
		do
		{
			cout << "Are you a returning customer? (y/n)" << endl; 
			cin >> strCustInputBuffer;
			stringstream(strCustInputBuffer) >> chCustInputBuffer; //Failsafe, in case customer types in "yes" or "no"
			{
				switch (chCustInputBuffer)
				{
				case 'y': library->login();
					break;
				case 'n': library->createCustomer();
					library->login();
					break;
				default: cout << "This is not a valid choice. Please choose between 'y' and 'n'." << endl;
					wrongInput = true;
					break;
				}
			}

		} while (wrongInput == true);
	}
	while ((library->loginSuccesfull == true) && iCustInputBuffer != 9)
	{
		cout << "What would you like to do? " << endl;
		if ((roundcount == 0)||iCustInputBuffer == 7)
		{
			cout << "1. List all books available " << endl;
			cout << "2. List all Computer Games available " << endl;
			cout << "3. List all Audiobooks available " << endl;
			cout << "4. Borrow an item" << endl;
			cout << "5. Return an item" << endl;
			cout << "6. Admin Function" << endl; //Function to doublecheck which users are currently in the DB
			cout << "7. Menu" << endl;
			cout << "9. Exit" << endl;
		}

		cin >> strCustInputBuffer;
		stringstream(strCustInputBuffer) >> iCustInputBuffer;

		switch (iCustInputBuffer)
		{
		case 1: library->list(library->getVector("book")); break;
		case 2: library->list(library->getVector("computergame")); break;
		case 3: library->list(library->getVector("audiobook")); break;
		case 4: library->borrowItem(borrowCount); borrowCount++; break;
		case 5: library->returnItem(); borrowCount--; break;
		case 6: library->adminFunct(); break;
		}
		roundcount++;
	}

	//clear memory
	library->~Publications();


}