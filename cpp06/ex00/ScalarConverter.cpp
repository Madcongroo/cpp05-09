/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:41:02 by proton            #+#    #+#             */
/*   Updated: 2025/04/15 12:04:31 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "in base constructor Scalar class" << std::endl;
}

ScalarConverter::ScalarConverter( const ScalarConverter& copy )
{
    std::cout << "in copy constructor of class scalar" << std::endl;
    *this = copy;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& copy )
{
    std::cout << "in assignation operator in class scalar" << std::endl;
    (void)copy;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "In scalarConverter destrucor" << std::endl;
    
}


void ScalarConverter::convert( std::string scalar )
{
    (void)scalar;
}

