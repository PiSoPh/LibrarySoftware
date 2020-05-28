#include "Publications.h"
#include "Audiobooks.h"
#include "Books.h"
#include "Computergames.h"
#include "Customer.h"
#include <iostream>

using namespace std;

int main()
{
	//Buffer for userinput
	char chCustInputBuffer;
	int iCustInputBuffer = 0;
	bool wrongInput = false;
	int roundcount = 0; //ensuring that menu is not listed everytime
	int borrowCount = 0;

	//initialise library
	auto library = new Publications();
	library->fillLib();

	do
	{
		cout << "Are you a returning customer? (y/n)" << endl;
		cin >> chCustInputBuffer;
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

	} while (wrongInput == true);

	while ((library->loginSuccesfull == true) && iCustInputBuffer != 8)
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
			cout << "8. Exit" << endl;
		}

		cin >> iCustInputBuffer;

		switch (iCustInputBuffer)
		{
		case 1: library->list(library->getVector("book")); break;
		case 2: library->list(library->getVector("computergame")); break;
		case 3: library->list(library->getVector("audiobook")); break;
		case 4: library->borrowItem(borrowCount); borrowCount++; break;
		}
		roundcount++;
	}


}