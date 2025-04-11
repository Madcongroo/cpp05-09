/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:28:51 by bproton           #+#    #+#             */
/*   Updated: 2025/04/11 13:43:35 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target("home"), _gradeToSign(145), _gradeToExec(137)
{
	std::cout << "Base constructor in shrubbery" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : _target(target), _gradeToSign(145), _gradeToExec(137)
{
	std::cout << "in direct assignation constructor shrubbery" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy ) : _gradeToSign(145), _gradeToExec(137)
{
	std::cout << "in copy constructor of class shrubbery" << std::endl;
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& copy )
{
	std::cout << "in assignation operator constructor in class shrubbery" << std::endl;
	if (this != &copy)
		this->_target = copy._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "in destructor shrubbery" << std::endl;
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	
}
