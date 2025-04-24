






#include "Data.hpp"


Data::Data() : name_("bonjour"), age_(25)
{
	std::cout << "in data base constructor" << std::endl;
}

Data::Data( const Data& copy )
{
	std::cout << "in copy constructor of Data" << std::endl;
	*this = copy;
}

Data& Data::operator=( const Data& copy )
{
	std::cout << "in copy operator of class data" << std::endl;
	if (this != &copy)
	{
		this->age_ = copy.age_;
		this->name_ = copy.name_;
	}
	return (*this);
}

Data::~Data()
{
	std::cout << "in data class destructor" << std::endl;
}

int		Data::getAge()
{
	return (this->age_);
}

std::string	Data::getName()
{
	return (this->name_);
}

