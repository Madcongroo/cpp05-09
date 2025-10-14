/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:29:55 by proton            #+#    #+#             */
/*   Updated: 2025/10/14 11:34:31 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	try {
		{
			std::list<int> test;
			for (size_t i = 0; i < 6; i++)
				test.push_back(i + 1);
			easyfind(test, 4);
			std::cout << "the occurence has been found" << std::endl;
		}
		{
			std::list<int> test2;
			for (size_t i = 0; i < 6; i++)
				test2.push_back(i + 1);
			easyfind(test2, 9);
			std::cout << "the occurence has been found" << std::endl;
		}
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}
