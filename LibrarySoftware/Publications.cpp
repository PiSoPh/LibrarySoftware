#include "Publications.h"
#include "Audiobooks.h"
#include "Books.h"
#include "Computergames.h"
#include "Customer.h"

using namespace std;

Publications::Publications()
{
	loginSuccesfull == false;
	
}

Publications::~Publications()
{
	for (auto& x : m_users)
	{
		delete x;
		cout << "User " << m_username << " deleted." << endl;
	}
}


//Adds books and stuff to the library, needs to be called right in beginning of main!
void Publications::fillLib()
{
	//Add Books to library
	m_books.push_back(new Books("Newt Scamander", "All you need to know about keeping Sentient Stick-Bugs", 1));
	m_books.push_back(new Books("All Might", "Go Beyond Plus Ultra", 2));
	

	//Add Computergames to library
	m_computergames.push_back(new Computergames("EA", "Fifa 19", 1));
	m_computergames.push_back(new Computergames("CD Project RED", "The Witcher 3: Wild Hunt", 2));

	//Add Audiobooks to library
	m_audiobooks.push_back(new Audiobooks("Monkey D. Ruffy", "Navigating the World Seas A-Z", 1));
	m_audiobooks.push_back(new Audiobooks("Donald Trump", "How to become the biggest Troll of them All - Read by the Master himself", 2));

	//add an admin user to the program (mainly for testing purposes)
	m_users.push_back(new Customer("admin", "youlose"));

}

void Publications::list(vector<Publications*> type)
{
	for (auto& i : type)
	{
		if(i->m_borrowed == false)
		cout << "ID:" << i->m_ID << " " << i->m_author << " - " << i->m_title << endl;
	}
}

void Publications::borrowItem(int borrowcount)
{
	int iBuffer = 0; 
	if (borrowcount < 2)
	{
		cout << "Which item would you like to borrow? " << endl;
		cout << "1. Book" << endl;
		cout << "2. Computergame" << endl;
		cout << "3. Audiobook" << endl;

		cin >> iBuffer;

		switch (iBuffer)
		{
		case 1: borrow(m_books);
			break;
		case 2: borrow(m_computergames);
			break;
		case 3: borrow(m_audiobooks);
			break;
		}
	}
	else
	{
		cout << "Sorry, you can't borrow anything more today." << endl;
	}
}

vector<Publications*> Publications::getVector(string type)
{
	if (type == "book")
	{
		return m_books;
	}
	else if (type == "computergame")
	{
		return m_computergames;
	}
	else
	{
		return m_audiobooks;
	}
}

void Publications::borrow(vector<Publications*> type)
{
	int iBuffer = 0;
	bool validChoice;
	cout << "Books available:" << endl;
	list(type);
	cout << "Please choose by typing in the ID" << endl;
	cin >> iBuffer;
	for (auto& i : type)
	{
		if (iBuffer == i->m_ID)
		{
			i->m_borrowed = true;
			cout << "You have successfully borrowed " << i->m_title << endl;
		}
	}
}

bool Publications::login()
{
	std::string username;
	std::string password;
	while (loginSuccesfull == false)
	{
		cout << "Please enter your username: " << endl;
		cin >> username;
		cout << "Please enter your password: " << endl;
		cin >> password;

		for (auto x : m_users)
		{
			if ((x->m_username == username) && (x->m_password == password))
			{
				cout << "Welcome back " << username << endl;
				loginSuccesfull = true;
				break;
			}
		}
	}
	return loginSuccesfull;
}

void Publications::createCustomer()
{
	bool usernameTaken = false;
	std::string username;
	std::string password;

	do
	{
		cout << "Please choose your username: " << endl;
		cin >> username;
		cout << "Please enter a password: " << endl;
		cin >> password;
		for (auto &i : m_users)
		{
			if (username == i->m_username)
			{
				cout << "Sorry, this username is taken." << endl;
				usernameTaken == true;
			}
			else
			{
				m_users.push_back(new Customer(username, password));
				usernameTaken == false;
			}
		}

	} while (usernameTaken == true);
}

