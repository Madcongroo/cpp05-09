/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:30:21 by proton            #+#    #+#             */
/*   Updated: 2025/04/30 17:31:02 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <exception>

template<typename T>
T	easyfind( T num1, int num2)
{
	//for (std::size_t i = 0; i < num1.size(); i++)
	//{
	//	if (num1.front() == num2)
	//		return ("value found");
	//}
	if (std::find(num1.begin(), num1.end(), num2) == num1.end())
		throw(std::exception());
	return (0);
}

#endif
