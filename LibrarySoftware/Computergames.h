#pragma once
#include "Publications.h"
#include <iostream>

class Computergames :
	public Publications
{
public:
	Computergames(std::string author, std::string title, int ID);
	~Computergames();
	using Publications::m_type;
	using Publications::m_borrowed;
	using Publications::m_ID;
private:
	using Publications::m_author;
	using Publications::m_title;
};

