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

//enum isValid	parseYearMonthDay( int date, size_t round, Btc& dataBase )
//{
//	if (round == 1)
//	{
//		if (date < 2009)
//			dataBase.printValues("Bitcoin was not out at the moment", NONVALID);
//		else if (
//	}
//}

enum isValid	parseDate( std::string date, Btc& dataBase )
{
	if (date.empty())
		return (NONVALID);

	//size_t			i = 0;
	//std::string::size_type	pos;
	//size_t			round = 0;

	//while (date[i])
	//{
	//	if (date[i] == '-')
	//	{
	//		round += 1;
	//		if (parseYearMonthDay(std::atoi(date.substr(pos, i).c_str()), round, dataBase) == NONVALID)
	//			return (NONVALID);
	//	}
	//}
}

void	parseUserInput(std::ifstream& file)
{
	Btc			dataBase;
	std::string		line;
	std::string::size_type	delim;
	std::string		date;
	float			value = 0;

	while (std::getline(file, line))
	{
		delim = line.find('|');
		if (delim == line.length())
			dataBase.printValues("Date and value not separated with '|'", NONVALID);
		else
		{
			date = line.substr(0, delim);
			if (parseDate(date, dataBase) == NONVALID)
				continue ;
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
