/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:28:44 by bproton           #+#    #+#             */
/*   Updated: 2025/04/11 17:50:05 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class   PresidentialPardonForm : public AForm
{
	private:
    
		std::string	_target;
		const int	_gradeToSign;
		const int	_gradeToExec;

	public:

		PresidentialPardonForm();
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( const PresidentialPardonForm& copy );
		PresidentialPardonForm& operator=( const PresidentialPardonForm& copy );
		~PresidentialPardonForm();

		void	execute( Bureaucrat const & executor ) const;

};



#endif