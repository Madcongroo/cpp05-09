/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:57:53 by proton            #+#    #+#             */
/*   Updated: 2025/04/28 11:38:48 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

//void	displayArray( std::string& array, size_t len )
//{
//	for (size_t i = 0, 
//}

int main()
{
	size_t		len = 3;
	int		array[3] = {1, 2, 3};

	//for (size_t i = 0; i < len; i++)
	//{
	//	for (size_t j = 0; j < 5; j++)
	//	{
	//		array[i][j] = j + i + 3;
	//		std::cout << array[i][j] << std::endl;
	//	}
	//}

	::iter(array, len, &::f);

	return (0);
}
