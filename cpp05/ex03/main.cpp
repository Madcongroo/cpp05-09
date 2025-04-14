/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:44:21 by proton            #+#    #+#             */
/*   Updated: 2025/04/14 15:26:26 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	try {
			Intern	randomIntern;
			Bureaucrat j("BUREAUCRAT", 1);
			AForm *shrub = randomIntern.makeForm("ShrubberyCreationForm", "Bender");
			j.signForm(*shrub);
			j.executeForm(*shrub);
			delete shrub;
	}

	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	catch ( const AForm::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}

	catch ( const AForm::GradeTooLowException& e )
	{
		std::cout << e.what() << std::endl;
	}

	catch ( const AForm::NotSignedFormException& e )
	{
		std::cout << e.what() << std::endl;
	}

	catch ( const Intern::InternFormCreationException& e)
	{
		std::cout << e.what() << std::endl;
	}
	

	return (0);
}
