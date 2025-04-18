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
#define	BAD_INPUT 0

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

long double	transformDouble( std::string input )
{
	size_t		comma = 0;
	size_t		special = 0;
	long double	num = 0;
	
	for (size_t i = 0; input[i]; i++)
	{
		if (input[i] == '+' || input[i] == '-')
			special += 1;
		else if (input[i] == '.')
			comma += 1;
		num = num * 10 + (input[i] - '0');
	}
	if (special > 1 || comma > 1)
		return (BAD_INPUT);

	return (num);
}

int	checkInput( std::string input )
{
	int	count = 0;
// if (input[0] != '-' && input[0] != '+' && (input[0] < 0 || input[0] > 9)) count += 1;
		
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
	std::cout << input << std::endl;	
	if (input.length() > 1)
	{
		if (checkInput(input) == -1)
			return (displayLiteral("Non displayable"), 0);
		long double num = transformDouble( input );
		if (num == BAD_INPUT)
			return (displayLiteral("Non displayable"), 0);
		std::cout << std::fixed;
		std::cout << num << std::endl;	
		if (num <= INT_MAX || num >= INT_MIN)
			return (isInt(static_cast<int>(num)));
	}


	return (0);
}
