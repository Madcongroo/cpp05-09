/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:07:07 by proton            #+#    #+#             */
/*   Updated: 2025/04/14 11:11:06 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "in Intern base constructor" << std::endl;
}

Intern::Intern( const Intern& copy )
{
    std::cout << "in Intern copy constructor" << std::endl;
    *this = copy;
}

Intern& Intern::operator=( const Intern& copy )
{
    std::cout << "in Intern assignation operator constructor" << std::endl;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "in Intern destructor" << std::endl;
}

void	Intern::makeForm( std::string formName, std::string target )
{
    
}

const char* Intern::InternFormCreationException::what() const throw()
{
    return ("The intern cant even create a form");
}

