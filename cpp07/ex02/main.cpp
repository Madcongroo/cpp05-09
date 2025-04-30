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
	
	try {
		Array<std::string> test(5);
		Array<std::string> test2;
		Array<int> test3(6);
		std::cout << "PUTTING VALUES IN TEST" << std::endl;
		test[0] = "QWERT";
		test[1] = "ASDF";
		test[2] = "hut";
		test[3] = "klkj";
		test[4] = "mbjb";
		std::cout << test[2] << std::endl;
		std::cout << "ASSIGNING TEST TO TEST2" << std::endl;
		test2 = test;
		std::cout << "MODIFIYING TEST2[0]" << std::endl;
		test2[0] = "NEW";
		test3[0] = 99;
		std::cout << test2[2] << std::endl;
		std::cout << test2[0] << std::endl;
		std::cout << test3[0] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
