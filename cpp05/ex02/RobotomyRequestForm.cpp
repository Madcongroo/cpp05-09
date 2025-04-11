/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:28:46 by bproton           #+#    #+#             */
/*   Updated: 2025/04/11 13:43:16 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _target("someone"), _gradeToSign(72), _gradeToExec(45)
{
	std::cout << "in base constructor robotomy" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : _target(target), _gradeToSign(72), _gradeToExec(45)
{
    std::cout << "in direct assignation constructor robotomy" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy ) : _gradeToSign(72), _gradeToExec(45)
{
    std::cout << "in copy constructor of robotomy" << std::endl;
    *this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& copy )
{
    std::cout << "in assignation operator constructor in class robotomy" << std::endl;
    if (this != &copy)
        this->_target = copy._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "in destructor robotomy" << std::endl;
}


void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{

}
