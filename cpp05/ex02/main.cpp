/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:44:21 by proton            #+#    #+#             */
/*   Updated: 2025/04/13 11:23:52 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	try {
			Bureaucrat j("BUREAUCRAT", 1);
			AForm *shrub = new ShrubberyCreationForm("HUMANOID");
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
	

	return (0);
}
