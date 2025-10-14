/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 01:21:24 by proton            #+#    #+#             */
/*   Updated: 2025/10/13 17:07:41 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class	Data
{
	private:	
		
		int			_age;
		std::string	_name;

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
