/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:41:05 by proton            #+#    #+#             */
/*   Updated: 2025/04/16 11:12:04 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <math.h>


class   ScalarConverter
{
	protected:

		ScalarConverter();
		ScalarConverter( const ScalarConverter& copy );
		ScalarConverter& operator=( const ScalarConverter& copy );
		~ScalarConverter();

	public:
	
		static void convert( std::string scalar );
};


#endif