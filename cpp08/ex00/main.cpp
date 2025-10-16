/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:29:55 by proton            #+#    #+#             */
/*   Updated: 2025/10/16 10:52:10 by proton           ###   ########.fr       */
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
		}
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
		try {
			std::list<int> test2;
			for (size_t i = 0; i < 6; i++)
				test2.push_back(i + 1);
			easyfind(test2, 9);
		}
		catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
		try {
			std::vector<int> test;
			for (size_t i = 0; i < 6; i++)
				test.push_back(i + 1);
			easyfind(test, 4);
		}
		catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
		try {
			std::vector<int> test2;
			for (size_t i = 0; i < 6; i++)
				test2.push_back(i + 1);
			easyfind(test2, 9);
		}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try {
			std::deque<int> test;
			for (size_t i = 0; i < 6; i++)
				test.push_back(i + 1);
			easyfind(test, 4);
		}
		catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
		try {
			std::deque<int> test2;
			for (size_t i = 0; i < 6; i++)
				test2.push_back(i + 1);
			easyfind(test2, 9);
		}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}
