/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:03:34 by proton            #+#    #+#             */
/*   Updated: 2025/05/02 10:08:38 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try {
		Span sp = Span(15000);
		std::set<unsigned int> number;
		std::srand(std::time(NULL));

		for (size_t i = 0; i < 15000; i++)
		{
			number.insert(std::rand());
		}
		sp.addMultipleNumbers(number.begin(), number.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (Span::SpanException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;	
}
