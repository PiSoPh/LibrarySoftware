#pragma once
#include <iostream>
#include <vector>
#include "Books.h"
#include "Audiobooks.h"
#include "Computergames.h"

class Publications
{
public:
	Publications();
	~Publications();
	std::string m_type; //Type of Publication, inherited by Books, Audiobooks and Computergames
	bool m_borrowed; //Flag to show if book, audiobook or computergame is still available
	int m_ID; //needed to borrow and return items
	std::vector<Books> m_books; //Collection of all books
	std::vector<Audiobooks> m_audiobooks; //Collection of all Audiobooks
	std::vector<Computergames> m_computergames; //Collection of all Computergames
	std::string getType(); //returns type of publication
	void fillLib(); //adds books and stuff to the library, needs to be called by main right at the beginning

};

