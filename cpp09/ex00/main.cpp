/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:10:05 by proton            #+#    #+#             */
/*   Updated: 2025/05/08 14:10:27 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	parseInputFile( std::ifstream& file )
{

}

int	main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cerr << "Error, wrong number of arguments" << std::endl;
		return (1);
	}

	std::ifstream file(av[1]);
	if (file.fail())
	{
		std::cerr << "Error, file failed to open" << std::endl;
		return (1);
	}
	

}
