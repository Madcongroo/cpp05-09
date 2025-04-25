


#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class	Data
{
	private:	
		
		int		age_;
		std::string	name_;

	public:

		Data();
		Data( int age, std::string name );
		Data( const Data& copy );
		Data& operator=( const Data& copy );
		~Data();
		
		int		getAge();
		std::string	getName();
};



#endif
