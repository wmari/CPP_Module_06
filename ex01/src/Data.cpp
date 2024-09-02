#include "Data.hpp"

Data::Data() : name("noname")
{
	return ;
}

Data::Data(std::string str) : name(str)
{
	return ;
}

Data::Data(Data &copy)
{
	(void)copy;
	*this = copy;
	return ;
}

Data::~Data()
{
	return ;
}

Data &Data::operator=(Data &copy)
{
	if (this == &copy)
		return *this;
	this->name = copy.name;
	return *this;
}

std::string Data::getname()
{
	return this->name;
}