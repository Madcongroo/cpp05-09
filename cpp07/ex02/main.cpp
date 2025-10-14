/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:11:29 by proton            #+#    #+#             */
/*   Updated: 2025/10/14 10:22:46 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 750
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
		test.modifyArray(2, "SALUT");
		std::cout << test[2] << std::endl;
		std::cout << "ASSIGNING TEST TO TEST2" << std::endl;
		test2 = test;
		std::cout << "MODIFIYING TEST2[0]" << std::endl;
		test2[0] = "NEW";
		test3[0] = 99;
		std::cout << test2[2] << std::endl;
		std::cout << test2[0] << std::endl;
		std::cout << test3[0] << std::endl;
		test[6] = "salut";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

    return 0;
}
