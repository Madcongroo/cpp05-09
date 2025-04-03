/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaurat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:43:56 by proton            #+#    #+#             */
/*   Updated: 2025/04/03 11:16:23 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Base constructor BUREAUCRAT called" << std::endl;

    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy )
{
    std::cout << "copy constructor BUREAUCRAT called" << std::endl;
    
    *this = copy;

    return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy )
{
    std::cout << "assignation operator BUREAUCLAT called" << std::endl;

    if (this != &copy)
    {
        (std::string)this->name = copy.name;
        this->grade = copy.grade;
    }

    return (*this);
}
