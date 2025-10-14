/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:30:21 by proton            #+#    #+#             */
/*   Updated: 2025/10/14 11:57:12 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <exception>
#include <iterator>

class NoOccurenceFoundException : public std::exception
{
	virtual const char* what() const throw()
	{
		return ("No occurence has been found");
	}
};

template<typename T>
void	easyfind( T num1, int num2)
{
	typename T::iterator it = std::find(num1.begin(), num1.end(), num2);
	if (it == num1.end())
		throw(NoOccurenceFoundException());
	std::cout << "Occurence has been found : " << *it << std::endl;
}

#endif
