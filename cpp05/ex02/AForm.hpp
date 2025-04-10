/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:28:33 by bproton           #+#    #+#             */
/*   Updated: 2025/04/10 15:30:56 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class	Bureaucrat;

class   AForm
{
	private:

		const std::string	_name;
		bool				_signd;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:

		AForm();
		AForm( const std::string name );
		AForm( const AForm& copy );
		AForm& operator=( const AForm& copy );
		
		std::string	getName() const;
		std::string	getSignd() const;
		int			getGradeToSignd() const;
		int			getGradeToExec() const;
		void		beSigned( const Bureaucrat& instance );
		void		beExec( const Bureaucrat& instance );

		class	GradeTooHighException : std::exception
		{
			public:
			virtual const char* what() const throw();
		};

		class GradeTooLowException : std::exception
		{
			public:
			virtual const char* what() const throw();
		};
};

std::ostream& operator<<( std::ostream& os, const AForm& instance );

#endif