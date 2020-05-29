#pragma once
#include <iostream>
#include "Publications.h"

class Books :
	public Publications
{
public:
	Books(std::string author, std::string title, int ID, int quantity);
	~Books();
private:
	using Publications::m_type;
	using Publications::m_borrowed;
	using Publications::m_ID;
	using Publications::m_author;
	using Publications::m_title;
	using Publications::m_quantity;
};

