/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:44:21 by proton            #+#    #+#             */
/*   Updated: 2025/04/04 18:14:16 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "MyExpr.hpp"

int	main(void)
{
	try {
		Bureaucrat h("Paul", 0);
		if (h.getGrade() < 1)
			throw myexpr;
	}

	catch (std::exception& e)
	{
		std::cout << e << std::endl;
	}
	return (0);
}
