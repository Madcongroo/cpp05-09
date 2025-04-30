/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:11:29 by proton            #+#    #+#             */
/*   Updated: 2025/04/29 15:54:58 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	//int * a = new int(5);
	Array<std::string> test(5);
	Array<std::string> test2;
	test2 = test;
	
	try {
		//for (int i = 0; i < 5; i++)
		//	std::cout << test.getArray(i) << std::endl;
		//test.modifyArray(0, 5);
		std::cout << test2.getArray(0) << std::endl;
		//std::cout << test.getArray(0) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	//std::cout << *a << std::endl;
	//delete a;
	return (0);
}
