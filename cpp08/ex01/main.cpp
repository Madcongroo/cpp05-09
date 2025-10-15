/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:03:34 by proton            #+#    #+#             */
/*   Updated: 2025/10/15 15:55:27 by bproton          ###   ########.fr       */
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
		std::cout << "end of subject main" << std::endl;
		Span sp = Span(150000);
		std::set<unsigned int> number;
		std::srand(std::time(NULL));
		
		for (size_t i = 0; i < 15000; i++)
			number.insert(std::rand());
	
		sp.addMultipleNumbers(number.begin(), number.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		for (size_t i = 0; i < 1600; i++)
			number.insert(std::rand());

		sp.addMultipleNumbers(number.begin(), number.end());	
	}
	catch (Span::SpanException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;	
}
