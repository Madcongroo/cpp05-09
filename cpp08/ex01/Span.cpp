/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:53:55 by proton            #+#    #+#             */
/*   Updated: 2025/10/17 10:25:44 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : maxNumbers_(30)
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
	if (this != &copy)
	{
		this->maxNumbers_ = copy.maxNumbers_;
		this->container_ = copy.container_;
	}
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
	if (this->container_.size() <= 1)
		throw (SpanException("Not enough composants on the list"));

	unsigned int	shortSpan = -1;
	unsigned int	savedSpan = UINT_MAX;
	std::set<unsigned int>::iterator itFirst = this->container_.begin();
	std::set<unsigned int>::iterator itSecond = this->container_.begin();
	std::set<unsigned int>::iterator itEnd = this->container_.end();
	itSecond++;

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

	return (*std::max_element(this->container_.begin(), this->container_.end()) - *std::min_element(this->container_.begin(), this->container_.end()));
}

void	Span::addMultipleNumbers( std::set<unsigned int>::iterator first, std::set<unsigned int>::iterator last )
{
	if (first == last)
		throw (SpanException("Empty range"));
	else if (*last > this->maxNumbers_ || this->container_.size() + std::distance(first, last) > this->maxNumbers_)
		throw (SpanException("Range too high"));
	this->container_.insert(first, last);
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

