/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:13:51 by proton            #+#    #+#             */
/*   Updated: 2025/09/23 17:05:51 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int firstInputParsing( std::string& userInput )
{
	std::stringstream	ss;
	std::string			token;
	int					num;
	ss << userInput;

	while (ss >> token)
	{
		if (token != "+" && token != "-" && token != "*" && token != "/")
		{
			num = std::atoi(token.c_str());
			if (num == 0)
			{
				std::cerr << "Error" << std::endl;
				return (-1);
			}
			if (num > 9 || num < 0)
			{
				std::cerr << "Error" << std::endl;
				exit (1);
			}
		}
	}
	return (0);
}

int	main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cerr << "Error, wrong number of arguments" << std::endl;
		return (1);
	}
	Rpn j;
	std::string userInput = av[1];
	if (firstInputParsing( userInput ) == -1)
		return (1);
	std::cout << j.processCalculation(userInput) << std::endl;
	return (0);
}

