/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:43:56 by proton            #+#    #+#             */
/*   Updated: 2025/04/09 14:11:09 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("golem"), _grade(100)
{
	std::cout << "Base constructor BUREAUCRAT called" << std::endl;

	return ;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name)
{
	std::cout << "in constructor direct assignation grade / name" << std::endl;

		if (grade < 1)
			throw (GradeTooHighException());
		
		else if (grade > 150)
			throw (GradeTooLowException());
		
		else
			_grade = grade;
	
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
	std::cout << "assignation operator BUREAUCRAT called" << std::endl;

	if (this != &copy)
		this->_grade = copy._grade;

	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "destrcution of BUREAUCRAT" << std::endl;

	return ;
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{

	if (this->_grade == 1)
		throw (GradeTooHighException("Grade is too high it cannot be upgraded"));
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
	{
		throw (GradeTooLowException("Grade is too low it cannot be downgraded"));
	}
	this->_grade++;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& instance)
{
	os << instance.getName() << ", bureaucrat grade " << instance.getGrade();

	return (os);
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : _errorMsg("Grade is too high")
{
	std::cout << "In base constructor grade too high" << std::endl;
}

Bureaucrat::GradeTooHighException::GradeTooHighException( const std::string error ) : _errorMsg(error)
{
	std::cout << "In constructor direct assignation grade too high" << std::endl;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << "in grade too high destructor" << std::endl;
}

const	char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (this->_errorMsg.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException() : _errorMsg("Grade is too low")
{
	std::cout << "In base constructor grade too low" << std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException( const std::string error ) : _errorMsg(error)
{
	std::cout << "In constructor direct assignation grade too low" << std::endl;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << "in grade too low destructor" << std::endl;
}

const	char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (this->_errorMsg.c_str());
}
