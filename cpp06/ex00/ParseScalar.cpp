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

int	getPrecision( std::string input )
{
	int	i = 0;
	int	j = 0;
	int	count = 0;
	
	while (input[i])
	{
		if (input[i] == '.')
		{
			j = i + 1;
			while (input[j] || input[j] == 'f')
			{
				count++;
				j++;
			}
		}
		i++;
	}
	return (count);
}

void	nonDisplayable( std::string input )
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

int	isChar( std::string input, long double num )
{
	if (input[0] >= 0 && input[0] <= 32 && input[0] == 127)
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : '" << static_cast<char>(num) << "'" << std::endl;
	std::cout << std::fixed << std::setprecision(0);
	std::cout << "int : " << static_cast<int>(num) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float : " << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(num) << std::endl;
	return (0);
}

int	isInt( long double num )
{
	std::cout << "is in int" << std::endl;
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

int	isFloat( long double num, int precision )
{
	std::cout << "is in float" << std::endl;
	std::cout << "char : Non displayable" << std::endl;
	std::cout << std::fixed << std::setprecision(0);
	std::cout << "int : " << static_cast<int>(num) << std::endl;
	std::cout << std::fixed << std::setprecision(precision);
	std::cout << "float : " << num << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(num) << std::endl;
	std::cout << std::fixed << std::setprecision(0);
	return (0);
}

int	isDouble( long double num, int precision )
{
	std::cout << "is in double" << std::endl;
	std::cout << "char : Non displayable" << std::endl;
	std::cout << std::fixed << std::setprecision(0);
	std::cout << "int : " << static_cast<int>(num) << std::endl; 
	std::cout << std::fixed << std::setprecision(precision);
	std::cout << "float : " << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double : " << num << std::endl;
	std::cout << std::fixed << std::setprecision(0);
	return (0);
}

int	parseInput( std::string input )
{
	size_t	point = 0;
	size_t	i = 0;
	
	if (input.length() == 1 && input[0] >= '0' && input[0] <= '9')
		return (ISINT);

//	else if (input.size() == 1 && (input[0] >= 0 && input[0] <= 127))
//		return (ISCHAR);
//
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
		else if (input[i] == 'f' && i != (input.length() - 1))
		{
			std::cout << "i value " << i << std::endl;
			std::cout << "input len " << input.length() << std::endl;
			return (ISBAD);
		}
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
	int		precision = 0;

	std::cout << std::fixed;
	newValue = atof(input.c_str());
	if (newValue == 0 || returnedValue == ISBAD)
	{
		nonDisplayable("Non displayable");	
		return ;
	}

	precision = getPrecision(input);

	if (returnedValue == ISCHAR)
		isChar(input, newValue);
	else if ((newValue <= INT_MAX && newValue >= INT_MIN) || returnedValue == ISINT)
		isInt(newValue);
	else if ((newValue <= FLT_MAX && newValue >= FLT_MIN) || returnedValue == ISFLOAT)
		isFloat(newValue, precision);
	else if ((newValue <= DBL_MAX && newValue >= DBL_MIN) || returnedValue == ISDOUBLE)
		isDouble(newValue, precision);	
}

int	parseScalar( std::string input )
{
	int	returnValue = 0;

	returnValue = parseInput( input );
	dispatchInput( input, returnValue );


	return (0);
}
