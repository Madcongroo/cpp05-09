/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:57:09 by proton            #+#    #+#             */
/*   Updated: 2025/04/28 11:38:50 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void	iter(T* array, T size, T f(T& value))
{
	T i = 0;

	if (size <= 0)
		return ;
	
	while (i < size)
	{
	}
}

template <typename T2>
void	f(T2 value)
{
	
}

#endif
