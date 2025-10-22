/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:09:39 by proton            #+#    #+#             */
/*   Updated: 2025/10/22 14:57:23 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Btc::Btc()
{
	std::cout << "Base constructor" << std::endl;

	std::ifstream		dataBase("data.csv");
	std::string		line;
	std::string::size_type	delim = 0;
	std::map<std::string, float>::iterator it = _dataBase.begin();

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

		delim = line.find(',');
		if (delim == std::string::npos)
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
			value = std::strtod(line.substr(delim + 1, end).c_str(), NULL);
			_dataBase.insert(it, std::pair<std::string, float>(date, value));
			it++;
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
		this->_dataBase = copy._dataBase;
	}
	return (*this);
}

Btc::~Btc()
{
	std::cout << "destructor" << std::endl;
}

void	Btc::printValues( std::string value, enum isValid flag )
{
	if (flag == NONVALID)
	{
		std::cerr << value << std::endl;
		return ;
	}

	std::string	date = value.substr(0, value.find('|'));
	float		BtcNumber = 0;	
	std::map<std::string, float>::iterator search;
	std::map<std::string, float>::iterator lowerBoundIt;

	BtcNumber = std::atof(value.substr(value.find('|') + 1, value.length()).c_str());
	search = this->_dataBase.find(date);
	if (this->_dataBase.find(date) == this->_dataBase.end())
	{
		lowerBoundIt = this->_dataBase.lower_bound(date);
		if (lowerBoundIt != this->_dataBase.begin())
			lowerBoundIt--;
		std::cout << lowerBoundIt->first << " => " << BtcNumber << " = " << lowerBoundIt->second * BtcNumber << std::endl;
		return ;
	}
	std::cout << search->first << " => " << BtcNumber << " = " << search->second * BtcNumber << std::endl;
	return ;
}


