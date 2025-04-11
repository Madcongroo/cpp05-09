/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:28:44 by bproton           #+#    #+#             */
/*   Updated: 2025/04/11 15:18:15 by bproton          ###   ########.fr       */
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
        bool		_signd;
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