#pragma once
#include "Publications.h"
#include <iostream>

class Books :
	public Publications
{
public:
	Books(std::string author, std::string title, int ID);
	~Books();
	using Publications::m_type;
	using Publications::m_borrowed;
	using Publications::m_ID;
private:
	std::string m_author;
	std::string m_title;
};

