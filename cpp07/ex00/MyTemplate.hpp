/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyTemplate.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 01:18:12 by proton            #+#    #+#             */
/*   Updated: 2025/10/13 19:32:29 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYTEMPLATE_HPP
#define MYTEMPLATE_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T& a, T& b)
{
	T temp = b;

	b = a;
	a = temp;
}

template <typename T>
T min(T &a, T &b)
{
	if (a < b)
		return (a);

	return (b);
}

template <typename T>
T max(T &a, T &b)
{
	if (a > b)
		return (a);
	
	return (b);
}

#endif
