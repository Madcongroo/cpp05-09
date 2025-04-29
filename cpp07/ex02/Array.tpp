/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 00:59:30 by proton            #+#    #+#             */
/*   Updated: 2025/04/29 01:00:43 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"`

template <class T>
Array<T>::Array() : array_( new[] T ) 
{
	std::cout << "in Array template base class constructor" << std::endl;
}

template <class T>
Array<T>::Array( unsigned int n ) : array_( new[n] T )
{
	std::cout << "in direct assignation of class template Array" << std::endl;
}

template <class T>
Array<T>::Array( const Array& copy )
{

}
