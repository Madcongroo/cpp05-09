/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseScalar.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:11:45 by proton            #+#    #+#             */
/*   Updated: 2025/09/24 09:48:00 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParseScalar.hpp"

// int	getPrecision( std::string input )
// {
// 	int	i = 0;
// 	int	j = 0;
// 	int	count = 0;
	
// 	while (input[i])
// 	{
// 		if (input[i] == '.')
// 		{
// 			j = i + 1;
// 			while (input[j] && input[j] == 'f')
// 			{
// 				count++;
// 				j++;
// 			}
// 		}
// 		i++;
// 	}
// 	return (count);
// }

// void	nonDisplayable( std::string input )
// {
// 	std::cout << "char : " << input << std::endl;
// 	std::cout << "int : " << input << std::endl;
// 	std::cout << "float : " << input  << std::endl;
// 	std::cout << "double : " << input << std::endl;
// }

// int	isChar( std::string input, long double num )
// {
// 	if (input[0] >= 0 && input[0] <= 32 || input[0] == 127)
// 		std::cout << "char : Non displayable" << std::endl;
// 	else
// 		std::cout << "char : '" << input[0] << "'" << std::endl;
// 	std::cout << std::fixed << std::setprecision(0);
// 	std::cout << "int : " << static_cast<int>(num) << std::endl;
// 	std::cout << std::fixed << std::setprecision(1);
// 	std::cout << "float : " << static_cast<float>(num) << "f" << std::endl;
// 	std::cout << "double : " << static_cast<double>(num) << std::endl;
// 	return (0);
// }

// int	isInt( int num )
// {
// 	if (num > 31 && num < 127)
// 		std::cout << "char : " << "'" << static_cast<char>(num) << "'" << std::endl;
// 	else
// 		std::cout << "char : Non displayable" << std::endl;

// 	std::cout << "int : " << static_cast<int>(num) << std::endl;
// 	std::cout << std::fixed << std::setprecision(1) << "float : " << static_cast<float>(num) << "f" << std::endl;
// 	std::cout << "double : " << static_cast<double>(num) << std::endl;
// 	std::cout << std::fixed << std::setprecision(0);
// 	return (0);
// }

// int	isFloat( long double num, int precision )
// {
// 	std::cout << "char : Non displayable" << std::endl;
// 	std::cout << std::fixed << std::setprecision(0);
// 	std::cout << "int : " << static_cast<int>(num) << std::endl;
// 	std::cout << std::fixed << std::setprecision(precision);
// 	std::cout << "float : " << num << "f" << std::endl;
// 	std::cout << "double : " << static_cast<double>(num) << std::endl;
// 	std::cout << std::fixed << std::setprecision(0);
// 	return (0);
// }

// int	isDouble( long double num, int precision )
// {
// 	std::cout << "char : Non displayable" << std::endl;
// 	std::cout << std::fixed << std::setprecision(0);
// 	std::cout << "int : " << static_cast<int>(num) << std::endl; 
// 	std::cout << std::fixed << std::setprecision(precision);
// 	std::cout << "float : " << static_cast<float>(num) << "f" << std::endl;
// 	std::cout << "double : " << num << std::endl;
// 	std::cout << std::fixed << std::setprecision(0);
// 	return (0);
// }

// int	checkIfInt( std::string input )
// {
// 	int	number = 0;
// 	size_t	i = 0;
// 	size_t	pointFlag = 0;

// 	if (input[0] == '-' || input[0] == '+')
// 		i = 1;

// 	else if (input.length() == 1 && isdigit(input[0]))
// 		return (ISINT);

// 	while (input[i])
// 	{
// 		if (input[i] == '.')
// 			pointFlag += 1;
// 		else if (!isdigit(input[i]))
// 			return (0);
// 		i++;
// 	}

// 	std::cout << std::fixed;
// 	number = atof(input.c_str());

// 	if (pointFlag > 1)
// 		return (0);

// 	else if (number >= INT_MIN && number <= INT_MAX)
// 		return (ISINT);

// 	return (0);
// }

// int	parseInput( std::string input )
// {
// 	size_t	point = 0;
// 	size_t	i = 0;

// 	if (input == "inff" || input == "-inff" || input == "+inff" || input == "nanf")
// 		return (ISFLOAT);

// 	else if (input == "inf" || input == "-inf" || input == "+inf" || input == "nan")
// 		return (ISDOUBLE);

// 	else if (input.length() == 1 && (static_cast<int>(input[0]) > 0 && static_cast<int>(input[0]) <= 126))
// 		return (ISCHAR);

// 	if (input[0] == '-' || input[0] == '+')
// 		i = 1;

// 	while (input[i])
// 	{
// 		if ((input[i] != 'f' && input[i] != '.') && (input[i] < '0' || input[i] > '9'))
// 			return (ISBAD);
// 		else if (input[i] == '.')
// 			point += 1;
// 		else if (input[i] == 'f' && i == input.length() - 1)
// 			return (ISFLOAT);
// 		i++;	
// 	}
// 	if (point == 1)
// 		return (ISDOUBLE);

// 	else if (checkIfInt( input ))
// 		return (ISINT);

// 	return (ISBAD);
// }

// void	dispatchInput( std::string input, int returnedValue )
// {
// 	long double	newValue = 0;
// 	int		precision = 0;

// 	precision = getPrecision(input);
// 	std::cout << std::fixed;
// 	newValue = atof(input.c_str());

// 	switch (returnedValue)
// 	{
// 		case (ISCHAR):
// 		isChar(input, newValue);
// 		break ;

// 		case (ISINT):
// 		{
// 			int num = atoi(input.c_str());
// 			isInt(num);
// 			break ;
// 		}

// 		case (ISFLOAT):
// 		isFloat(newValue, precision);
// 		break ;

// 		case (ISDOUBLE):
// 		isDouble(newValue, precision);
// 		break ;

// 		default:
// 		nonDisplayable("Non displayable");
// 		break ;
// 	}	
// }

int getPrecision(const std::string &input)
{
    size_t dot = input.find('.');
    if (dot == std::string::npos)
        return 1;

    int count = 0;
    for (size_t i = dot + 1; i < input.size() && input[i] != 'f'; i++)
        count++;
    return (count > 0 ? count : 1);
}

void nonDisplayable()
{
    std::cout << "char   : Non displayable" << std::endl;
    std::cout << "int    : Non displayable" << std::endl;
    std::cout << "float  : Non displayable" << std::endl;
    std::cout << "double : Non displayable" << std::endl;
}

int isChar(const std::string &input, long double num)
{
	(void)num;
    char c = input[0];
    if ((c >= 0 && c <= 32) || c == 127)
        std::cout << "char   : Non displayable" << std::endl;
    else
        std::cout << "char   : '" << c << "'" << std::endl;

    std::cout << "int    : " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float  : " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(c) << std::endl;
    return 0;
}

int isInt(int num)
{
    if (num >= 32 && num <= 126)
        std::cout << "char   : '" << static_cast<char>(num) << "'" << std::endl;
    else
        std::cout << "char   : Non displayable" << std::endl;

    std::cout << "int    : " << num << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float  : " << static_cast<float>(num) << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(num) << std::endl;
    return 0;
}

int isFloat(long double num, int precision)
{
    std::cout << "char   : Non displayable" << std::endl;
    std::cout << "int    : " << static_cast<int>(num) << std::endl;
    std::cout << std::fixed << std::setprecision(precision);
    std::cout << "float  : " << static_cast<float>(num) << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(num) << std::endl;
    return 0;
}

int isDouble(long double num, int precision)
{
    std::cout << "char   : Non displayable" << std::endl;
    std::cout << "int    : " << static_cast<int>(num) << std::endl;
    std::cout << std::fixed << std::setprecision(precision);
    std::cout << "float  : " << static_cast<float>(num) << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(num) << std::endl;
    return 0;
}

int checkIfInt(const std::string &input)
{
    char *end;
    long val = strtol(input.c_str(), &end, 10);

    if (*end != '\0')
        return 0;
    if (val >= INT_MIN && val <= INT_MAX)
        return ISINT;
    return 0;
}

int parseInput(const std::string &input)
{
    if (input == "inff" || input == "-inff" || input == "+inff" || input == "nanf")
        return ISFLOAT;

    if (input == "inf" || input == "-inf" || input == "+inf" || input == "nan")
        return ISDOUBLE;

    if (input.length() == 1 && !isdigit(input[0]))
        return ISCHAR;

    if (checkIfInt(input))
        return ISINT;

    if (input.find('.') != std::string::npos && input[input.size()-1] == 'f')
        return ISFLOAT;

    if (input.find('.') != std::string::npos)
        return ISDOUBLE;

    return ISBAD;
}

void dispatchInput(const std::string &input, int returnedValue)
{
    long double value = atof(input.c_str());
    int precision = getPrecision(input);

    switch (returnedValue)
    {
        case ISCHAR:
            isChar(input, value);
            break;
        case ISINT:
            isInt(atoi(input.c_str()));
            break;
        case ISFLOAT:
            isFloat(value, precision);
            break;
        case ISDOUBLE:
            isDouble(value, precision);
            break;
        default:
            nonDisplayable();
            break;
    }
}

int parseScalar(const std::string &input)
{
    int type = parseInput(input);
    dispatchInput(input, type);
    return 0;
}
