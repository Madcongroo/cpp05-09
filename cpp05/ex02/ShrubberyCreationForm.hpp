/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:28:54 by bproton           #+#    #+#             */
/*   Updated: 2025/04/12 14:07:03 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class   ShrubberyCreationForm : public AForm
{
	private:
	
		std::string	_target;
		const int	_gradeToSign;
		const int	_gradeToExec;

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm& copy );
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& copy );
		~ShrubberyCreationForm();

		void	execute( Bureaucrat const & executor ) const;
};




#endif
