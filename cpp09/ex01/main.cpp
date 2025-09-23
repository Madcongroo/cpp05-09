/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:13:51 by proton            #+#    #+#             */
/*   Updated: 2025/05/20 15:56:44 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	firstInputParsing( std::string& userInput )
{
	size_t	i = 0;

	while (userInput[i])
	{
		if (userInput[i] != ' ' && (userInput[i + 1] == '*' || userInput[i + 1] == '/'
			|| userInput[i + 1] == '+' || userInput[i + 1] == '-'))
				userInput.insert(i, 1, ' ');
		std::cout << "sadf" << std::endl;
		i++;
	}
}

int	main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cerr << "Error, wrong number of arguments" << std::endl;
		return (1);
	}
	std::string userInput = av[1];
	firstInputParsing( userInput );
	std::cout << userInput << std::endl;
	return (0);
}

