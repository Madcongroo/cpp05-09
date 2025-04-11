/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:28:51 by bproton           #+#    #+#             */
/*   Updated: 2025/04/11 11:19:04 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _gradeToSign(145), _gradeToExec(137)
{
	std::cout << "Base constructor in shrubbery" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : _gradeToSign(145), _gradeToExec(137)
{
	std::cout << "in direct assignation constructor shrubbery" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy ) : _gradeToSign(145), _gradeToExec(137)
{
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& copy )
{
	if (this != &copy)
		this->
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{

}
