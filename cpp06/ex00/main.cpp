/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:40:54 by proton            #+#    #+#             */
/*   Updated: 2025/04/16 11:18:06 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main()
{
	std::string input;

	std::cout << "Insert an input" << std::endl;
	std::cin >> input;

	if (std::cin.eof())
	{
		std::cerr << "Ctrl-D pressed" << std::endl;
		return (1);
	}

	ScalarConverter::convert(input);
	
	return (0);
}
