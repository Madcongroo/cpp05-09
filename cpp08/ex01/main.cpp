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
		Span sp = Span(500);
		sp.addNumber(1);
		sp.addNumber(500);
		sp.addMultipleNumbers(sp.getItFirst(), sp.getItLast());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (Span::SpanException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;	
}
