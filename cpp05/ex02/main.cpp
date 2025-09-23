/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:44:21 by proton            #+#    #+#             */
/*   Updated: 2025/09/23 11:33:31 by proton           ###   ########.fr       */
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
			AForm *robot = new RobotomyRequestForm("HUMAN");
			AForm *presi = new PresidentialPardonForm("GOD");
			j.signForm(*shrub);
			j.executeForm(*shrub);
			j.signForm(*robot);
			j.executeForm(*robot);
			j.signForm(*presi);
			j.executeForm(*presi);
			delete shrub;
			delete robot;
			delete presi;
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
