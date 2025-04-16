#include "Data.hpp"

Data::Data(void) : _name("Default")
{
	std::cout << "Data Default constructor called" << std::endl;
}

Data::Data(std::string name) : _name(name)
{
	std::cout << "Data Constructor called for: " << getName() << std::endl;
}

Data::Data(const Data &other) : _name(other.getName())
{
	std::cout << "Data Copy constructor called for: " << getName() << std::endl;
}

Data::~Data(void)
{
	std::cout << "Data Destructor called for: " << getName() << std::endl;
}

const Data &Data::operator=(const Data &other)
{
	if (this != &other)
		_name = other.getName();
	return (*this);
}

std::string	Data::getName(void) const
{
	return (_name);
}