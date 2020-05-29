#pragma once
#include <iostream>
#include <vector>

class Publications
{
public:
	Publications();
	~Publications();

	//Variables for derivative Classes:
	std::string m_type; //Type of Publication, inherited by Books, Audiobooks and Computergames
	bool m_borrowed; //Flag to show if book, audiobook or computergame is still available
	int m_ID; //needed to borrow and return items
	std::string m_author;
	std::string m_title;
	int m_quantity;
	std::vector<Publications*> m_books; //Collection of all books
	std::vector<Publications*> m_audiobooks; //Collection of all Audiobooks
	std::vector<Publications*> m_computergames; //Collection of all Computergames

	//Variables for User Management:
	bool loginSuccesfull;
	std::vector<Publications*> m_users;
	std::string m_username;
	std::string m_password;


	//Functions for Librarymanagement
	void fillLib(); //adds books and stuff to the library, needs to be called by main right at the beginning
	void list(std::vector<Publications*> type);
	void borrowItem(int borrowcount); //called in main
	void returnItem();
	std::vector<Publications*> getVector(std::string type);

private:
	void borrow(std::vector<Publications*> type);

public:
	//Functions for Usermanagement
	bool login(); //for returning customers
	void createCustomer();


};

