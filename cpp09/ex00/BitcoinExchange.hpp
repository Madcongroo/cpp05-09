/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:07:34 by proton            #+#    #+#             */
/*   Updated: 2025/05/08 14:09:33 by proton           ###   ########.fr       */
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

	//class	BtcException : public std::exception
	//{
	//	private:
	//		std::string _message;
	//	public:
	//		BtcException() throw();
	//		BtcException( std::string message ) throw ();
	//		~BtcException() throw();

	//		virtual const char* what() const throw();
	//};

		
};



#endif
