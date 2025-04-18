/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseScalar.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:11:45 by proton            #+#    #+#             */
/*   Updated: 2025/04/18 11:36:58 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParseScalar.hpp"

void	displayLiteral( std::string input )
{
	if (input == "Non displayable")
	{
		std::cout << "char : " << input << std::endl;
		std::cout << "int : " << input << std::endl;
		std::cout << "float : " << input  << std::endl;
		std::cout << "double : " << input << std::endl;
		return ;
	}
}

int	isInt( int num )
{
	if (num > 31 && num < 127)
		std::cout << "char : " << "'" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;

	std::cout << "int : " << num << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float : " << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(num) << std::endl;
	std::cout << std::fixed << std::setprecision(0);
	return (0);
}

double	transformDouble( double num )
{
	(void)num;
	return (0);
}

int	checkInput( std::string input )
{
	int	count = 0;

	// if (input[0] != '-' && input[0] != '+' && (input[0] < 0 || input[0] > 9))
	// 	count += 1;
		
	for (size_t i = 0; input[i]; i++)
	{
		if (input[i] < '0' || input[i] > '9')
			count += 1;
	}
	if (count >= 2)
		return (-1);

	return (0);
}

int	parseScalar( std::string input )
{
	
	if (input.length() > 1)
	{
		if (checkInput(input) == -1)
			return (displayLiteral("Non displayable"), 0);
		double num = atof(input.c_str());
		// num = transformDouble(num);
		if (num <= INT_MAX || num >= INT_MIN)
			return (isInt(static_cast<int>(num)));
	}


	return (0);
}
