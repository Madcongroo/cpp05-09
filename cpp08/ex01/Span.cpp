/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:53:55 by proton            #+#    #+#             */
/*   Updated: 2025/05/02 10:41:00 by proton           ###   ########.fr       */
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
	return (*this);
}

void	Span::addNumber( unsigned int n )
{
	if (this->mult_.size() == this->maxNumbers_)
			throw (SpanException("List already full"));

	this->mult_.insert(n);
}

unsigned int	Span::shortestSpan()
{
	unsigned int	shortSpan = -1;
	unsigned int	savedSpan = UINT_MAX;
	std::multiset<unsigned int>::iterator itFirst = this->mult_.begin();
	std::multiset<unsigned int>::iterator itSecond = this->mult_.begin();
	std::multiset<unsigned int>::iterator itEnd = this->mult_.end();
	itSecond++;

	if (this->mult_.size() <= 1)
		throw (SpanException("Not enough composants on the list"));	
	
	while (itSecond != itEnd)
	{
		shortSpan = *itSecond - *itFirst;

		if (shortSpan < savedSpan)
			savedSpan = shortSpan;

		if (shortSpan == 1)
			return (*itSecond - *itFirst);
		itSecond++;
		itFirst++;
	}
	return (savedSpan);
}

unsigned int	Span::longestSpan()
{
	if (this->mult_.size() <= 1)
		throw (SpanException("Not enough composants on the list"));

	std::multiset<unsigned int>::iterator itStart = this->mult_.begin();
	std::multiset<unsigned int>::reverse_iterator itEnd = this->mult_.rbegin();

	return (*itEnd - *itStart);
}

void	Span::addMultipleNumbers( std::multiset<unsigned int>::iterator first, std::multiset<unsigned int>::iterator last )
{
	
}

Span::SpanException::SpanException()
{
}

Span::SpanException::SpanException( std::string message )
{
	this->message_ = message;
}

Span::SpanException::~SpanException() throw()
{
}

const char* Span::SpanException::what() const throw()
{
	return (this->message_.c_str());
}

