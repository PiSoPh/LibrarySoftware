#include "Publications.h"

Publications::Publications()
{
}

Publications::~Publications()
{
}

std::string Publications::getType()
{
	return m_type;
}


//Adds books and stuff to the library, needs to be called right in beginning of main!
void Publications::fillLib()
{
	//Add Books to library
	m_books.push_back("Newt Scamander", "All you need to know about keeping Sentient Stick-Bugs", 1);

}
