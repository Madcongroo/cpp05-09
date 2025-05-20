/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:09:09 by proton            #+#    #+#             */
/*   Updated: 2025/05/20 15:13:47 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn()
{
	std::cout << "default constructor" << std::endl;
}

Rpn::Rpn( const Rpn& copy )
{
	std::cout << "copy operator constructor" << std::endl;
	*this = copy;
}

Rpn& Rpn::operator=( const Rpn& copy )
{
	std::cout << "copy assignation constructor" << std::endl;
	if (this != &copy)
	{
		
	}
	return (*this);
}

Rpn::~Rpn()
{
	std::cout << "rpn destructor" << std::endl;
}

