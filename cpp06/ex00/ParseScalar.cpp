/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseScalar.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:11:45 by proton            #+#    #+#             */
/*   Updated: 2025/10/13 15:52:22 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParseScalar.hpp"

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

int isFloat(long double num, int precision, const std::string &input)
{
    if (num >= 32 && num <= 126)
        std::cout << "char   : '" << static_cast<char>(num) << "'" << std::endl;
    else
        std::cout << "char   : Non displayable" << std::endl;
    if (input == "-inff" || input == "inff" || input == "+inff" || input == "-nanf" || input == "+nanf" || input == "nanf")
        std::cout << "int   : Impossible" << std::endl;
    else
        std::cout << "int    : " << static_cast<int>(num) << std::endl;
    std::cout << std::fixed << std::setprecision(precision);
    std::cout << "float  : " << static_cast<float>(num) << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(num) << std::endl;
    return 0;
}

int isDouble(long double num, int precision, const std::string &input)
{
    if (num >= 32 && num <= 126)
        std::cout << "char   : '" << static_cast<char>(num) << "'" << std::endl;
    else
        std::cout << "char   : Non displayable" << std::endl;
    if (input == "inf" || input == "+inf" || input == "nan" || input == "+nan" || input == "-nan" || input == "-inf")
        std::cout << "int   : Impossible" << std::endl;
    else
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
    long double value = atof(input.c_str());
    if (input == "inf" || input == "+inf" || input == "nan" || input == "+nan" || input == "-nan" || input == "-inf")
        return ISDOUBLE;

    else if (input == "-inff" || input == "inff" || input == "+inff" || input == "-nanf" || input == "+nanf" || input == "nanf")
        return ISFLOAT;

    if (input.length() == 1 && !isdigit(input[0]))
        return ISCHAR;

    if (checkIfInt(input))
        return ISINT;

    if ((input.find('.') != std::string::npos && input[input.size()-1] == 'f') || (value > FLT_MIN && value < FLT_MAX))
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
            isFloat(value, precision, input);
            break;
        case ISDOUBLE:
            isDouble(value, precision, input);
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
