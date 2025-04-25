








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

uintptr_t Serializer::serialize(Data* ptr)
{
	std::cout << "in serialize function" << std::endl;

	if (ptr)
		return (reinterpret_cast<uintptr_t>(ptr));

	return (0);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	std::cout << "in deserialize function" << std::endl;
	
	if (raw)
	{
		std::cout << "in raw not empty if condition" << std::endl;	
		return (reinterpret_cast<Data*>(raw));
	}

	return (NULL);
}


