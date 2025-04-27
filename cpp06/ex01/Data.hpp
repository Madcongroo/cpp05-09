/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 01:21:24 by proton            #+#    #+#             */
/*   Updated: 2025/04/26 01:21:26 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
