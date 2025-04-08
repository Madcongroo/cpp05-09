/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:43:56 by proton            #+#    #+#             */
/*   Updated: 2025/04/08 15:44:47 by bproton          ###   ########.fr       */
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
	std::cout << "assignation operator BUREAUCLAT called" << std::endl;

	if (this != &copy)
	{
		(std::string)this->_name = copy._name;
		this->_grade = copy._grade;
	}

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
	try
	{
		if (this->_grade == 1)
			throw (GradeTooHighException());
		this->_grade--;
	}
	catch( const GradeTooHighException& e )
	{
		std::cout << e.what() << std::endl;
		std::cout << this->_name << ", bureaucrat grade " << this->_grade << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	this->_grade++;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& instance)
{
	os << instance.getName() << ", bureaucrat grade " << instance.getGrade() << std::endl;

	return (os);
}

const	char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const	char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}
