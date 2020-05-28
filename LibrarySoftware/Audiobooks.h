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
	using Publications::m_author;
	using Publications::m_title;
};

