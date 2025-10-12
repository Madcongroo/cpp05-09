/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:28:36 by bproton           #+#    #+#             */
/*   Updated: 2025/10/12 14:49:17 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("base AForm"), _signd(0), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "in AForm base constructor" << std::endl;

	return ;
}

AForm::AForm( const std::string name, const int sign, const int exec ) : _name(name), _signd(0), _gradeToSign(sign), _gradeToExec(exec)
{
	std::cout << "in direct assignation constructor of AForm" << std::endl;

	return ;
}

AForm::AForm( const AForm& copy ) : _name(copy._name), _signd(copy._signd), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
	return ;
}

AForm& AForm::operator=( const AForm& copy )
{
	if (this != &copy)
		this->_signd = copy._signd;
	return (*this);
}

AForm::~AForm()
{
    std::cout << "in AForm destructor" << std::endl;
}

std::string	AForm::getName() const
{
	return (this->_name);
}

std::string		AForm::getSignd() const
{
	if (this->_signd == 0)
		return ("not signed");
	return ("signed");
}

int	AForm::getGradeToSignd() const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}

void	AForm::beSigned( const Bureaucrat& instance )
{
	if (instance.getGrade() > this->getGradeToSignd())
	{
		std::cout << instance.getName() << " couldnt sign " << this->_name << " because " << "grade is not high enough" << std::endl;
		throw AForm::GradeTooLowException();
	}
	this->_signd = 1;
	std::cout << instance.getName() << " signed " << this->_name << std::endl;
}

void	AForm::beExec( const Bureaucrat& instance )
{
	if (instance.getGrade() < this->getGradeToExec())
	{
		std::cout << instance.getName() << " couldnt exec " << this->_name << " because " << "grade is not low enough" << std::endl;
		throw AForm::GradeTooHighException();
	}
	std::cout << instance.getName() << " has executed the work very nicely" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* AForm::NotSignedFormException::what() const throw()
{
    return ("Form is unfortunatly no signed");
}

std::ostream& operator<<( std::ostream& os, const AForm& instance )
{
	os << "AForm name :" << instance.getName() << " is " << instance.getSignd() << ", rank required to sign and to exec : " << instance.getGradeToSignd() << " : " << instance.getGradeToExec();
	return (os);
}