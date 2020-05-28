#pragma once
#include "Publications.h"

class Audiobooks:
	public Publications
{
public:
	Audiobooks(std::string author, std::string title, int ID);
	~Audiobooks();
	using Publications::m_type;
	using Publications::m_borrowed;
	using Publications::m_ID;

private:
	std::string m_author;
	std::string m_title;
};

