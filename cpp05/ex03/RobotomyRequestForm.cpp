/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:28:46 by bproton           #+#    #+#             */
/*   Updated: 2025/04/13 11:17:23 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm() : _target("someone"), _gradeToSign(72), _gradeToExec(45)
{
	std::cout << "in base constructor robotomy" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm( target, 72, 45), _gradeToSign(72), _gradeToExec(45)
{
    std::cout << "in direct assignation constructor robotomy" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy ) : AForm(), _gradeToSign(72), _gradeToExec(45)
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
	if (this->getSignd() == "not signed")
		throw (AForm::NotSignedFormException());

	else if (this->getGradeToExec() < executor.getGrade())
		throw (AForm::GradeTooLowException());

	std::cout << "Some drilling noises" << std::endl;
	
	srand(time(NULL)); // to generate the seed for rand() function
	int random_num = rand();
	if (random_num % 2 == 1)
		std::cout << this->getName() << " has been robotomized" << std::endl;
	else
		std::cout << "robotomy failed" << std::endl;
}
