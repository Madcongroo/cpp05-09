/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:07:34 by proton            #+#    #+#             */
/*   Updated: 2025/10/17 10:08:40 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <exception>
#include <cstdlib>
#include <utility>
#include <sstream>
#include <iomanip>

enum	isValid
{
	VALID,
	NONVALID
};

class Btc
{
	private:
	
		std::map<std::string, float> _dataBase;

	public:

		Btc();
		Btc( const Btc& copy );
		Btc& operator=( const Btc& copy );
		~Btc();

		void	printValues( std::string value, enum isValid flag );	
};



#endif
