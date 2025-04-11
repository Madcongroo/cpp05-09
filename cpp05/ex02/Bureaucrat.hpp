/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:34:24 by proton            #+#    #+#             */
/*   Updated: 2025/04/11 10:27:01 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
	private :

		const std::string	_name;
		int					_grade;

	public :

		Bureaucrat();
		Bureaucrat( std::string name, int grade );
		Bureaucrat( const Bureaucrat& copy );
		Bureaucrat& operator=( const Bureaucrat& copy );
		~Bureaucrat();

		std::string		getName() const;
		int				getGrade() const;
		void			incrementGrade();
		void			decrementGrade();
		void			signForm( AForm& instance );
		void			execForm( AForm& instance );
		void			executeForm( AForm const& form );

		class GradeTooHighException : std::exception
		{
			private:

				std::string _errorMsg;
				
			public:
				
				GradeTooHighException();
				GradeTooHighException( const std::string error );
				virtual ~GradeTooHighException() throw();
				virtual const char* what() const throw();
		};

		class GradeTooLowException : std::exception
		{
			private:

				std::string _errorMsg;

			public:

				GradeTooLowException();
				GradeTooLowException( const std::string error );
				virtual ~GradeTooLowException() throw();
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<( std::ostream& os, const Bureaucrat& instance );

#endif