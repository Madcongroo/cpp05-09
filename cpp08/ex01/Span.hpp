/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:27:20 by proton            #+#    #+#             */
/*   Updated: 2025/05/01 16:10:05 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <exception>

class	Span
{
	private:
		
		unsigned int maxNumbers;
		

	public:
		
		Span();
		Span( unsigned int n );
		Span( const Span& copy );
		Span& operator=( const Span& copy );

		void		addNumber();
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		

	class SpanException : std::exception
	{
		private:
			std::string message;
		public:
			SpanException();
			SpanException( std::string message );
			~SpanException();

			virtual const char* what() const throw();
	};
};

#endif
