/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 22:44:44 by proton            #+#    #+#             */
/*   Updated: 2025/10/14 10:04:04 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <vector>

template <class T>
class Array
{
	private:

		T*		array_;
		size_t	size_;

	public:

		Array();
		Array( unsigned int n );
		Array( const Array& copy );
		Array& operator=( const Array& copy );
		~Array();

		unsigned int	size() const;
		T&	operator[]( unsigned int pos );
		void modifyArray( unsigned int pos, const T &newValue );

		class OutOfBoundException : public std::exception
		{
			virtual const char* what() const throw();	
		};
};

#include "Array.tpp"

#endif
