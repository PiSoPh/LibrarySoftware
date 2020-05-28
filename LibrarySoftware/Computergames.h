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
	std::string m_author;
	std::string m_title;
};

