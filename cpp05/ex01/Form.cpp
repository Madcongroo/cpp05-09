/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:42:31 by bproton           #+#    #+#             */
/*   Updated: 2025/04/10 15:19:20 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("base form"), _signd(0), _gradeToSign(21), _gradeToExec(42)
{
	std::cout << "in Form base constructor" << std::endl;

	return ;
}

Form::Form( const std::string name ) : _name(name), _signd(0), _gradeToSign(21), _gradeToExec(42)
{
	std::cout << "in direct assignation constructor of FORM" << std::endl;
	
	return ;
}

Form::Form( const Form& copy ) : _gradeToSign(21), _gradeToExec(42)
{
	*this = copy;
	return ;
}

Form& Form::operator=( const Form& copy )
{
	if (this != &copy)
		this->_signd = copy._signd;
	return (*this);
}

std::string	Form::getName() const
{
	return (this->_name);
}

std::string		Form::getSignd() const
{
	if (this->_signd == 0)
		return ("not signed");
	return ("signed");
}

int	Form::getGradeToSignd() const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

void	Form::beSigned( const Bureaucrat& instance )
{
	if (instance.getGrade() > this->getGradeToSignd())
	{
		std::cout << instance.getName() << " couldnt sign " << this->_name << " because " << "grade is not high enough" << std::endl;
		throw Form::GradeTooLowException();
	}
	this->_signd = 1;
	std::cout << instance.getName() << " signed " << this->_name << std::endl;
}

void	Form::beExec( const Bureaucrat& instance )
{
	if (instance.getGrade() < this->getGradeToExec())
	{
		std::cout << instance.getName() << " couldnt exec " << this->_name << " because " << "grade is not low enough" << std::endl;
		throw Form::GradeTooHighException();
	}
	std::cout << instance.getName() << " has executed the work very nicely" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream& operator<<( std::ostream& os, const Form& instance )
{
	os << "Form name :" << instance.getName() << " is " << instance.getSignd() << ", rank required to sign and to exec : " << instance.getGradeToSignd() << " : " << instance.getGradeToExec();
	return (os);
}
