/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:40:54 by proton            #+#    #+#             */
/*   Updated: 2025/04/15 14:04:35 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main()
{
	short a = 2000;
	int b;

	b = (int) a;
	std::cout << "first b :" << b << std::endl;
	b = int (a);
	std::cout << "second b :" << b << std::endl;
	return (0);
}
