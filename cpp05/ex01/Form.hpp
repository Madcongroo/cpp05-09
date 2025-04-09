/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:35:47 by bproton           #+#    #+#             */
/*   Updated: 2025/04/09 15:43:38 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class   Form : public Bureaucrat
{
	private:

		const std::string	_name;
		bool				_signd;
		const int			_gradeToSing = 21;
		const int			_gradeToExec = 42;

	public:

		Form();
		Form( const std::string name );
		Form( const Form& copy );
		Form& operator=( const Form& copy );
		
		std::string	getName() const;
		bool		getSignd() const;
		const int	getGradeToSignd() const;
		const int	getGradeToExec() const;
		void		beSigned( Bureaucrat& instance );

		class	GradeTooHighException
		{
			virtual const char* what() const throw();
		};

		class GradeTooLowException
		{
			virtual const char* what() const throw();
		};
		
	
};

std::ostream& operator<<( std::ostream& os, const Form& instance );

#endif