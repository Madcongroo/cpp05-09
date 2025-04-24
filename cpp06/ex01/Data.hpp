


#ifndef DATA_HPP
#define DATA_HPP

#include "Serializer.hpp"

class	Data : public Serializer
{
	private:	
		
		int		age_;
		std::string	name_;

	public:

		Data();
		Data( const Data& copy );
		Data& operator=( const Data& copy );
		~Data();
		
		int		getAge();
		std::string	getName();
};



#endif
