/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:28:41 by bproton           #+#    #+#             */
/*   Updated: 2025/04/11 15:31:24 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _target("someone"), _gradeToSign(25), _gradeToExec(5)
{
	std::cout << "in base constructor for class presidentail form" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : _target(target), _gradeToSign(25), _gradeToExec(5)
{
	std::cout << "in direct assignation constructor of class presidential form" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy ) : _gradeToSign(25), _gradeToExec(5)
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
		throw (PresidentialPardonForm::NotSignedFormException());

	else if ()
	
		
}

