








#include "Serializer.hpp"


Serializer::Serializer()
{
	std::cout << "in base Serializer constructor" << std::endl;
}

Serializer::Serializer( const Serializer& copy )
{
	std::cout << "in serializer copy constructor" << std::endl;
	*this = copy;
}

Serializer& Serializer::operator=( const Serializer& copy)
{
	std::cout << "in copy operator of class serializer" << std::endl;
	if (this != &copy)
		return (*this);
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "in serializer destructor" << std::endl;
}

static uintptr_t serialize(Data* ptr)
{
	
}

static Data* deserialize(uintptr_t raw)
{
	
}


