/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateValue.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:27:02 by proton            #+#    #+#             */
/*   Updated: 2025/05/16 11:38:42 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATEVALUE_HPP
#define DATEVALUE_HPP

#include <iostream>
#include <map>
#include <string>

class	DateValue
{
	private:
		int	_year;
		int	_month;
		int	_day;

	public:
		DateValue();
		DateValue( int year, int month, int day );
		DateValue( const DateValue& copy );
		DateValue& operator=( const DateValue& copy );

		void	setYear( int year );
		void	setMonth( int month );
		void	setDay( int day );
		getDate();
};

#endif
