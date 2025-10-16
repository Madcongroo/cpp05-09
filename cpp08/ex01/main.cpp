/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:03:34 by proton            #+#    #+#             */
/*   Updated: 2025/10/16 11:02:35 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try {
		//////////////////////// main subject
		Span spa = Span(5);
		spa.addNumber(6);
		spa.addNumber(3);
		spa.addNumber(17);
		spa.addNumber(9);
		spa.addNumber(11);
		std::cout << spa.shortestSpan() << std::endl;
		std::cout << spa.longestSpan() << std::endl;

		std::cout << std::endl;
		std::cout << "end of subject main" << std::endl;
		std::cout << std::endl;
		
		Span sp = Span(15000);
		std::set<unsigned int> number;
		std::srand(std::time(NULL));
		
		for (size_t i = 0; i < 14500; i++)
			number.insert(std::rand());
	
		sp.addMultipleNumbers(number.begin(), number.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::set<unsigned int> number2;		
		for (size_t i = 0; i < 501; i++)
			number2.insert(std::rand());

		sp.addMultipleNumbers(number2.begin(), number2.end());	
	}
	catch (Span::SpanException& e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		Span sp2 = Span(0);
		sp2.longestSpan();
	}
	catch (Span::SpanException& e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		Span sp3 = Span(4);
		sp3.addNumber(1);
		sp3.addNumber(5);
		sp3.addNumber(6);
		sp3.addNumber(15);
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch (Span::SpanException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;	
}
