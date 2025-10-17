/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:13:51 by proton            #+#    #+#             */
/*   Updated: 2025/10/17 13:23:06 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int firstInputParsing( std::string& userInput )
{
	std::string token;
	int		num;
	size_t	i = 0;

	while (i < userInput.size())
	{
		token = userInput[i];
		if (userInput[i] == ' ')
		{
			i++;
			continue ;
		}

		if (token != "+" && token != "-" && token != "*" && token != "/")
		{
			num = atoi(token.c_str());
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
		i++;
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

