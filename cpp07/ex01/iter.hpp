/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:57:09 by proton            #+#    #+#             */
/*   Updated: 2025/10/14 13:44:35 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void	f(T& value)
{
	value += 396;
}

template <typename T, typename T2>
void	iter(T* array, T2 size, void (*f)(T&))
{
	T2 i = 0;

	if (size <= 0)
		return ;
	
	while (i < size)
	{
		f(array[i]);
		i++;
	}
}

template <typename T, typename T2>
void	iter(T* array, T2 size, const void (*f)(T&))
{
	T2 i = 0;

	if (size <= 0)
		return ;
	
	while (i < size)
	{
		f(array[i]);
		i++;
	}
}

#endif
