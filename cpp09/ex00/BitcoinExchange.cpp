/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:09:39 by proton            #+#    #+#             */
/*   Updated: 2025/05/08 14:10:39 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Btc::Btc()
{
	std::cout << "Base constructor" << std::endl;

	std::ifstream		dataBase("data.csv");
	std::string		line;
	std::string::size_type	delim = 0;

	if (!dataBase.is_open())
	{
		std::cerr << "couldn't open the file" << std::endl;
		exit(1);
	}

	while (std::getline(dataBase, line))
	{
		std::string		date;
		float			value = 0;
		std::string::size_type	end = line.size();

		date.erase();
		if (std::getline(dataBase, line).eof())
		{
			std::cerr << "An error has occured in getline" << std::endl;
			exit(1);
		}

		delim = line.find(',');
		if (line[delim] != ',')
		{
			std::cerr << "Did not found the delimiter" << std::endl;
			exit(1);
		}
		else
		{
			date = line.substr(0, delim);
			if (date.empty())
			{
				std::cerr << "Date is empty" << std::endl;
				exit (1);
			}
			value = std::strtof(line.substr(delim, end).c_str(), NULL);
			_dataBase.insert(date, value);
		}
	}
}

Btc::Btc( const Btc& copy )
{
	std::cout << "copy constructor" << std::endl;
	*this = copy;
}

Btc&	Btc::operator=( const Btc& copy )
{
	std::cout << "copy operator" << std::endl;

	if (this != &copy)
	{
			
	}
}

Btc::~Btc()
{
	std::cout << "destructor" << std::endl;
}



