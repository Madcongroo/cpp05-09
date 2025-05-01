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

class NoOccurenceFoundException : public std::exception
{
	virtual const char* what() const throw()
	{
		return ("No occurence has been found");
	}
};

template<typename T>
int	easyfind( T num1, int num2)
{
	for (std::list<int>::iterator it = num1.begin(); it != num1.end(); it++)
	{
		if (*it == num2)
			return (*it);
	}
	throw(NoOccurenceFoundException());
}



#endif
