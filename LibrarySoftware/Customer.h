#pragma once
#include <iostream>
#include "Publications.h"

class Customer:
	public Publications
{
public:
	Customer(std::string username, std::string password);
	~Customer();
private:
	using Publications::m_username;
	using Publications::m_password;



};

