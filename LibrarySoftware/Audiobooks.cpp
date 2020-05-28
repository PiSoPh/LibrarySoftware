#include "Audiobooks.h"

Audiobooks::Audiobooks(std::string author, std::string title, int ID)
{
	m_type = "Audiobook";
	m_borrowed = false;
	m_ID = ID;
	m_author = author;
	m_title = title;

	std::cout << "The " << m_type << " \"" << m_title << "\" by " << m_author << " has been added to the library." << std::endl;
}

Audiobooks::~Audiobooks()
{
	std::cout << "The " << m_type << " \"" << m_title << "\" by " << m_author << " has been lost to the library fire." << std::endl;
}
