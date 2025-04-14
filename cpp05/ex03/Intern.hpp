/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:57:14 by proton            #+#    #+#             */
/*   Updated: 2025/04/14 14:42:36 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class	Intern
{
	public:

		Intern();
		Intern( const Intern& copy );
		Intern& operator=( const Intern& copy );
		~Intern();

		AForm*	makeForm( std::string formName, std::string target );
		
		class	InternFormCreationException : std::exception
		{
			public:

				virtual const char* what() const throw();
		};
};

#endif