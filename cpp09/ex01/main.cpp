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

int	parseUserInput(char **av)
{
	(void)av;
	return (1);	
}

int	main( int ac, char **av )
{
	if (ac < 2)
	{
		std::cerr << "not enough arguments" << std::endl;
		return (1);
	}
	std::cout << ac << std::endl;
	
	int i = 1;
	while (i < ac)
	{
		std::cout << av[i] << std::endl;
		i++;
	}
	//if (parseUserInput(av) == -1)
	//	return (1);
}

