/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:53:55 by proton            #+#    #+#             */
/*   Updated: 2025/05/01 20:27:50 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	std::cout << "in Span default constructor" << std::endl;
}

Span::Span( unsigned int n ) : maxNumbers_(n) 
{
	std::cout << "in Span direct assignator constructor" << std::endl;
}

Span::Span( const Span& copy )
{
	std::cout << "in Span copy constructor" << std::endl;
	*this = copy;
}

Span& Span::operator=( const Span& copy )
{
	std::cout << "in Span copy assignator" << std::endl;
	if (this == &copy)
		return (*this);

}

void		Span::addNumber()
{

}

unsigned int	Span::shortestSpan()
{

}

unsigned int	Span::longestSpan()
{

}



Span::SpanException::SpanException()
{

}

Span::SpanException::SpanException( std::string message )
{

}

Span::SpanException::~SpanException()
{

}

const char* Span::SpanException::what() const throw()
{

}

