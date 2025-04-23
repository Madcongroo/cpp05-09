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

int	checkIfInt( std::string input )
{
	int	number = 0;
	size_t	i = 0;
	size_t	pointFlag = 0;

	if (input[0] == '-' || input[0] == '+')
		i = 1;

	else if (input.length() == 1 && isdigit(input[0]))
		return (ISINT);

	while (input[i])
	{
		if (input[i] == '.')
			pointFlag += 1;
		else if (!isdigit(input[i]))
			return (0);
	}

	std::cout << std::fixed;
	number = atof(input.c_str());

	if (pointFlag > 1)
		return (0);

	else if (number >= INT_MIN || number <= INT_MAX)
		return (ISINT);

	return (0);
}

int	parseInput( std::string input )
{
	size_t	point = 0;
	size_t	i = 0;

	if (input == "inff" || input == "-inff" || input == "+inff" || input == "nanf")
		return (ISFLOAT);

	else if (input == "inf" || input == "-inf" || input == "+inf" || input == "nan")
		return (ISDOUBLE);

	else if (input.length() == 1 && (input[0] > 0 && input[0] <= 127))
		return (ISCHAR);

	if (input[0] == '-' || input[0] == '+')
		i = 1;

	while (input[i])
	{
		if ((input[i] != 'f' && input[i] != '.') && (input[i] < '0' || input[i] > '9'))
			return (ISBAD);
		else if (input[i] == '.')
			point += 1;
		else if (input[i] == 'f' && i == input.length() - 1)
			return (ISFLOAT);
		i++;	
	}
	if (point == 1)
		return (ISDOUBLE);

	else if (checkIfInt( input ))
		return (ISINT);

	return (ISBAD);
}

void	dispatchInput( std::string input, int returnedValue )
{
	long double	newValue = 0;
	int		precision = 0;

	precision = getPrecision(input);

	switch (whatValue)
	{
		case (ISCHAR)
		(isChar(input, num);
		break ;
	}
	
}

int	parseScalar( std::string input )
{
	int	returnValue = 0;

	returnValue = parseInput( input );
	dispatchInput( input, returnValue );


	return (0);
}
