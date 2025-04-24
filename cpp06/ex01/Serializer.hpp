#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdint>
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
