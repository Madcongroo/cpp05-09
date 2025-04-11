/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:35:47 by bproton           #+#    #+#             */
/*   Updated: 2025/04/11 10:15:25 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class	Bureaucrat;

class   Form
{
	private:

		const std::string	_name;
		bool				_signd;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:

		Form();
		Form( const std::string name );
		Form( const Form& copy );
		Form& operator=( const Form& copy );
		~Form();
		
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

std::ostream& operator<<( std::ostream& os, const Form& instance );

#endif