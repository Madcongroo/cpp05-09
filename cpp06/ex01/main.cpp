/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 01:21:31 by proton            #+#    #+#             */
/*   Updated: 2025/10/13 17:05:41 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	
	Data		test(45, "Heinz");
	uintptr_t	ptr;
	Data*		test2;

	ptr = Serializer::serialize(&test);	
	if (!ptr)
	{
		std::cerr << "pointer is null" << std::endl;
		return (1);
	}
	std::cout << &ptr << std::endl;
	test2 = Serializer::deserialize(ptr);
	std::cout << test2->getAge() << std::endl;
	std::cout << test2->getName() << std::endl;
	
	return (0);
}
