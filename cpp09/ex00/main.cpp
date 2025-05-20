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

enum isValid	parseYearMonthDay( int year, int month, int day, Btc& dataBase, std::string date )
{
	//std::cout << "year = " << year << std::endl;
	//std::cout << "month = " << month << std::endl;
	//std::cout << "day = " << day << std::endl;
	if (year == 0 || month == 0 || day == 0)
	{
		dataBase.printValues("Error, date is wrong => " + date, NONVALID);
		return (NONVALID);
	}
	else if (year < 2009 && month < 02)
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
	else if ((month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) && day > 29)
	{
		dataBase.printValues("Error, february bissextile year => " + date, NONVALID);
		return (NONVALID);
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
	int	delimiter = 0;
	int	year = 0;
	int	month = 0;
	int	day = 0;

	delimiter = date.find('-');
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

enum isValid	parseValue( std::string line, float value, Btc& dataBase )
{
	if (value < 1)
	{
		dataBase.printValues("Error, value under 1 => " + line, NONVALID);
		return (NONVALID);
	}
	else if (value > 1000)
	{
		dataBase.printValues("Error, value over 1000 => " + line, NONVALID);
		return (NONVALID);
	}
	return (VALID);
}

std::string	trimLine( std::string& line )
{
	size_t		i = 0;
	size_t		j = 0;
	std::string	newLine;

	i = line.find_first_not_of(" \t");	
	j = line.find_last_not_of(" \t");

	newLine = line.substr(i, j + 1);

	return (newLine);
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

	while (std::getline(file, line))
	{
		value = 0;
		newValue.str("");
		newValue.clear();
		delim = line.find('|');
		if (delim == -1)
			dataBase.printValues("Date and value not separated with '|'", NONVALID);
		else
		{
			date = line.substr(0, delim);
			newLine = trimLine(date);
			if (parseDate(newLine, dataBase) == NONVALID)
				continue ;
			value = std::atof(line.substr(delim + 1, line.length()).c_str());
			if (parseValue(line.substr(delim + 1, line.length()), value, dataBase) == NONVALID)
				continue ;
			newValue << value;
			dataBase.printValues(newLine + '|' + newValue.str(), VALID);
		}
	}
}

int	main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cerr << "Error, wrong number of arguments" << std::endl;
		return (1);
	}

	std::ifstream file(av[1]);
	if (!file.is_open())
	{
		std::cerr << "Error, user input file failed to open" << std::endl;
		return (1);
	}
	parseUserInput(file);	
	
	return (0);
}
