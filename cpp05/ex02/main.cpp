/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:44:21 by proton            #+#    #+#             */
/*   Updated: 2025/04/10 15:24:39 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try {
			Form	f;
			Bureaucrat j("nom", 42);
			j.signForm(f);
			j.execForm(f);
			std::cout << f << std::endl;
	}

	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	catch ( const Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}

	catch ( const Form::GradeTooLowException& e )
	{
		std::cout << e.what() << std::endl;
	}
	

	return (0);
}
