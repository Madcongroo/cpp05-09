#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include <exception>
#include "Data.hpp"

class	Serializer
{
	protected:

		Serializer();
		Serializer( const Serializer& copy );
		Serializer& operator=( const Serializer& copy);
		~Serializer();

	public:

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};




#endif
