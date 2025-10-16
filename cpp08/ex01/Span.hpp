/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:27:20 by proton            #+#    #+#             */
/*   Updated: 2025/10/15 17:05:39 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <exception>
#include <set>
#include <limits.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class	Span
{
	private:
		
		unsigned int			maxNumbers_;
		std::set<unsigned int>	container_;

	public:
		
		Span();
		Span( unsigned int n );
		Span( const Span& copy );
		Span& operator=( const Span& copy );

		void		addNumber( unsigned int n );

		void		addMultipleNumbers(std::set<unsigned int>::iterator first, std::set<unsigned int>::iterator last );

		unsigned int	shortestSpan();
		unsigned int	longestSpan();

	class SpanException : std::exception
	{
		private:
			std::string message_;
		public:
			SpanException();
			SpanException( std::string message );
			~SpanException() throw();

			virtual const char* what() const throw();
	};
};

#endif
