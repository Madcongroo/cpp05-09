/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:10:05 by proton            #+#    #+#             */
/*   Updated: 2025/10/22 14:56:49 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

enum isValid	parseYearMonthDay( int year, int month, int day, Btc& dataBase, std::string date )
{
	if (year == 0 || month == 0 || day == 0)
	{
		dataBase.printValues("Error, date is wrong => " + date, NONVALID);
		return (NONVALID);
	}
	else if (year < 2009 || (year == 2009 && day < 02))
	{
		dataBase.printValues("Error, date before bitcoin creation => " + date, NONVALID);
		return (NONVALID);
	}
	else if (month < 1 || month > 12)
	{
		dataBase.printValues("Error, month wrong format => " + date, NONVALID);
		return (NONVALID);
	}
	else if (day < 1 || day > 31)
	{
		dataBase.printValues("Error, day wrong format => " + date, NONVALID);
		return (NONVALID);
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		dataBase.printValues("Error, day wrong format => " + date, NONVALID);
		return (NONVALID);
	}
	else if ((month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)))
	{
		return (VALID);
	}
	else if (month == 2 && day > 28)
	{
		dataBase.printValues("Error, non bissextile year => " + date, NONVALID);
		return (NONVALID);
	}
	return (VALID);
}

enum isValid	parseDate( std::string date, Btc& dataBase )
{
	if (date.empty())
		return (NONVALID);
	
	int	pos = 0;
	std::string::size_type	delimiter = 0;
	int	year = 0;
	int	month = 0;
	int	day = 0;

	delimiter = date.find('-');
	if (delimiter == std::string::npos)
	{
		dataBase.printValues("Error, bad date format => " + date, NONVALID);
		return (NONVALID);
	}
	year = std::atoi(date.substr(0, delimiter).c_str());
	
	pos = delimiter + 1;
	delimiter = date.find('-', pos);

	month = std::atoi(date.substr(pos, delimiter).c_str());
	pos = delimiter + 1;
	day = std::atoi(date.substr(pos).c_str());
	
	if (parseYearMonthDay(year, month, day, dataBase, date) == NONVALID)
		return (NONVALID);
	return (VALID);
}

enum isValid	parseValue( float value, Btc& dataBase )
{
	if (value < 0)
	{
		dataBase.printValues("Error: not a positive number", NONVALID);
		return (NONVALID);
	}
	else if (value > 1000)
	{
		dataBase.printValues("Error: too large number", NONVALID);
		return (NONVALID);
	}
	return (VALID);
}

std::string	trimLine( std::string line )
{
	size_t		i = 0;
	size_t		j = 0;
	std::string	newLine;

	i = line.find_first_not_of(" \t");
	j = line.find_last_not_of(" \t");
	newLine = line.substr(i, j - i + 1);

	return (newLine);
}

int	ft_isDigit( std::string str )
{
	if (str.empty())
	{
		std::cerr << "Error: no value" << std::endl;
		return (-1);
	}
	std::stringstream ss;
	std::string	newstr;

	newstr = trimLine(str);

	ss.str(newstr);
	float	test = 0;
	
	ss >> test;
	if (!ss.eof())
	{
		std::cerr << "Error: number wrong format" << std::endl;
		return (-1);
	}

	return (0);
}

void	parseUserInput(std::ifstream& file)
{
	Btc			dataBase;
	std::string		line;
	int			delim;
	std::string		date;
	float			value;
	std::string		newLine;
	std::ostringstream	newValue;
	size_t			loopRound = 0;
	std::string		mockvalue;

	while (std::getline(file, line))
	{
		if (loopRound == 0 && line.find("date") != std::string::npos)
		{
			loopRound++;
			continue ;
		}
		if (line.empty())
		{
			std::cerr << "Error: empty line" << std::endl;
			continue;
		}
		value = 0;
		newValue.str("");
		newValue.clear();
		delim = line.find('|');
		if (delim == -1)
			dataBase.printValues("Error: bad input => " + line, NONVALID);
		else
		{
			date = line.substr(0, delim);
			newLine = trimLine(date);
			if (parseDate(newLine, dataBase) == NONVALID)
				continue ;
			if (ft_isDigit(line.substr(delim + 1, line.length())) == -1)
				continue ;
			mockvalue = trimLine(line.substr(delim + 1, line.length()).c_str());
			value = std::atof(mockvalue.c_str());
			if (parseValue( value, dataBase) == NONVALID)
				continue ;
			newValue << value;
			dataBase.printValues(newLine + '|' + newValue.str(), VALID);
		}
		loopRound++;
	}
}

int	main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (1);
	}

	std::ifstream file(av[1]);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (1);
	}
	if (file.peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << "Error: file is empty" << std::endl;
		file.close();
		return (1);
	}
	parseUserInput(file);

	file.close();
	
	return (0);
}
