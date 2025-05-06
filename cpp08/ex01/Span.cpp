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
	if (this->container_.size() == this->maxNumbers_)
			throw (SpanException("List already full"));

	this->container_.insert(n);
}

unsigned int	Span::shortestSpan()
{
	unsigned int	shortSpan = -1;
	unsigned int	savedSpan = UINT_MAX;
	std::set<unsigned int>::iterator itFirst = this->container_.begin();
	std::set<unsigned int>::iterator itSecond = this->container_.begin();
	std::set<unsigned int>::iterator itEnd = this->container_.end();
	itSecond++;

	if (this->container_.size() <= 1)
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
	if (this->container_.size() <= 1)
		throw (SpanException("Not enough composants on the list"));

	std::set<unsigned int>::iterator itStart = this->container_.begin();
	std::set<unsigned int>::reverse_iterator itEnd = this->container_.rbegin();

	return (*itEnd - *itStart);
}

void	Span::addMultipleNumbers( std::set<unsigned int>::iterator first, std::set<unsigned int>::iterator last )
{
	if (*first >= *last)
	{
		std::cerr << "couldnt add to list" << std::endl;
		return ;
	}

	unsigned int uinFirst = *first;
	unsigned int uinLast = *last;

	while (uinFirst < uinLast)
	{
		this->container_.insert(uinFirst);
		uinFirst++;
	}
	std::cout << this->container_.size() << std::endl;
}

std::set<unsigned int>::iterator Span::getItFirst()
{
	return (this->container_.begin());
}

std::set<unsigned int>::iterator Span::getItLast()
{
	return (this->container_.end());
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

