/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:41:05 by proton            #+#    #+#             */
/*   Updated: 2025/10/12 14:59:23 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <math.h>
#include "ParseScalar.hpp"


class   ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter( const ScalarConverter& copy );
		ScalarConverter& operator=( const ScalarConverter& copy );
		~ScalarConverter();

	public:
	
		static void convert( std::string scalar );
};


#endif