/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:28:41 by bproton           #+#    #+#             */
/*   Updated: 2025/10/12 14:52:15 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("someone")
{
	std::cout << "in base constructor for class presidentail form" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm( "Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << "in direct assignation constructor of class presidential form" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy ) : AForm(copy), _target(copy._target)
{
	std::cout << "in copy constructor of class presidential form" << std::endl;
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& copy )
{
	std::cout << "in assignation operator constructor of class presidential form" << std::endl;
	if (this != &copy)
		this->_target = copy._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "in destructor of class presidential form" << std::endl;
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	if (this->getSignd() == "not signed")
		throw (AForm::NotSignedFormException());

	else if (this->getGradeToExec() < executor.getGrade())
		throw (AForm::GradeTooLowException());

	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

