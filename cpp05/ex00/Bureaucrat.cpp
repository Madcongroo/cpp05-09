/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:43:56 by proton            #+#    #+#             */
/*   Updated: 2025/04/08 12:35:45 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(100), _name("golem")
{
	std::cout << "Base constructor BUREAUCRAT called" << std::endl;

	return ;
}
Bureaucrat::Bureaucrat( std::string name, int grade )
{
	std::cout << "in constructor direct assignation grade / name" << std::endl;

	try
	{
		if (grade < 1)
			throw (GradeTooHighException( grade ));
	}
	catch( Bureaucrat::GradeTooHighException( int grade ))
	{
		std::cerr << e.what() << '\n';
	}
	
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
			throw (this->GradeTooHighException( this->_grade ));
		this->_grade--;
	}
	catch( int grade )
	{
		std::cout << grade << ": is the highest grade archievable" << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	this->_grade++;
}

std::ostream&	operator<<(std::ostream& os, const std::exception& e)
{
	os << e.what();
	
	return (os);
}

