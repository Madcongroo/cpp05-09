/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:28:49 by bproton           #+#    #+#             */
/*   Updated: 2025/04/11 15:18:32 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class   RobotomyRequestForm : public AForm
{
	private:
	
		bool		_signd;
		std::string	_target;
		const int	_gradeToSign;
		const int	_gradeToExec;

	public:

		RobotomyRequestForm();
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm& copy );
		RobotomyRequestForm& operator=( const RobotomyRequestForm& copy );
		~RobotomyRequestForm();

		void	execute( Bureaucrat const & executor ) const;

};



#endif