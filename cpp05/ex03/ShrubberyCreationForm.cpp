/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:28:51 by bproton           #+#    #+#             */
/*   Updated: 2025/04/13 11:24:30 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target("home"), _gradeToSign(145), _gradeToExec(137)
{
	std::cout << "Base constructor in shrubbery" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm(target, 145, 137), _gradeToSign(145), _gradeToExec(137)
{
	std::cout << "in direct assignation constructor shrubbery" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy ) : AForm(), _gradeToSign(145), _gradeToExec(137)
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
	if (this->getSignd() == "not signed")
		throw (AForm::NotSignedFormException());

	else if (this->getGradeToExec() < executor.getGrade())
		throw (AForm::GradeTooLowException());
	
	std::string fileName = this->getName() + "_shrubbery";

	std::ofstream ostrm(fileName.c_str());

	int height = 0;
	int	leavesHeight = 6;
	int	tree = 1;

	while (height < 9)
	{
		for (int len = 0; len < 11; len++)
		{
			if (len == leavesHeight - 1)
				{
					for (int i = 0; i < tree; i++)
						ostrm << "*";
					tree += 2;
					leavesHeight -= 1;
				}
			if ((len == 11 / 2) && height > 5)
				ostrm << "&";
			ostrm << ' ';
		}
		ostrm << std::endl;
		height++;
	}
	ostrm.close();
}
