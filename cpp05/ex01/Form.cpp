/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:42:31 by bproton           #+#    #+#             */
/*   Updated: 2025/04/09 15:55:08 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("base form"), _signd(0)
{
	std::cout << "in Form base constructor" << std::endl;

	return ;
}

Form::Form( const std::string name ) : _name(name), _signd(0)
{
	std::cout << "in direct assignation constructor of FORM" << std::endl;
	
	return ;
}

Form::Form( const Form& copy )
{
	*this = copy;
	return ;
}

Form& Form::operator=( const Form& copy )
{
	return (*this);
}

std::string	Form::getName() const
{
	return (this->_name);
}

bool		Form::getSignd() const
{
	return (this->_signd);
}

const int	Form::getGradeToSignd() const
{
	return (this->_gradeToSing);
}

const int	Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

void		Form::beSigned( Bureaucrat& instance )
{
	
}
