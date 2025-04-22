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

int	isInt( long double num )
{
	if (num > 31 && num < 127)
		std::cout << "char : " << "'" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;

	std::cout << "int : " << static_cast<int>(num) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float : " << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(num) << std::endl;
	std::cout << std::fixed << std::setprecision(0);
	return (0);
}

int	isFloat( float num )
{
	std::cout << "char : Non displayable" << std::endl;
	std::cout << "int : " << static_cast<int>(num) << std::endl;
	std::cout << "float : " << num << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(num) << std::endl;
	return (0);
}

int	parseInput( std::string input )
{
	size_t	isFloat = 0;
	size_t	point = 0;
	int	i = 0;
	
	if (input.length() == 1 && input[0] >= '0' && input[0] <= '9')
		return (ISINT);

	else if (input.length() == 1 && input[0] >= 0 && input[i] <= 127)
		return (ISCHAR);

	else if (input == "inff" || input == "-inff" || input == "+inff" || input == "nanf")
		return (ISFLOAT);

	else if (input == "inf" || input == "-inf" || input == "+inf" || input == "nan")
		return (ISDOUBLE);

	if (input[0] == '-' || input[0] == '+')
		i = 1;

	while (input[i])
	{
		if ((input[i] != 'f' && input[i] != '.') && (input[i] < '0' || input[i] > '9'))
 			return (ISBAD);
		if (input[i] == '.')
			point += 1;
		else if (input[i] == 'f' && i != input.length())
			return (ISBAD);
		else if (input[i] == 'f' && i == input.length())
			return (ISFLOAT);
		i++;	
	}
	if (point > 1)
		return (ISBAD);	
	return (ISOTHER);
}

void	dispatchInput( std::string input, int returnedValue )
{
	long double	newValue = 0;

	std::cout << std::fixed;
	newValue = atof(input.c_str());
	if (newValue == 0 || returnedValue == ISBAD)
		displayLiteral("Non displayable");
	else if ((newValue <= INT_MAX && newValue >= INT_MIN) || returnedValue == ISINT)
		isInt(newValue);
	else if (newValue <= FLT_MAX && newValue >= FLT_MIN || returnedValue == ISFLOAT)
		isFloat(newValue);
	else if ((new_value <= DOUBLE_MAX && newValue >= DOUBLE_MIN) || returnedValue == ISDOUBLE)

}

int	parseScalar( std::string input )
{
	double	newInput = 0;
	int	returnValue = 0;

	returnValue = parseInput( input );
	dispatchInput( input, returnValue );
	std::cout << std::fixed;
	newInput = atof(input.c_str());
	if (newInput == 0)
		displayLiteral("Non displayable");
	else if (newInput <= INT_MAX || newInput >= INT_MIN)
		return (isInt(newInput));
	else if (
		



	return (0);
}
