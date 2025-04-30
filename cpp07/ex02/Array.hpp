/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 22:44:44 by proton            #+#    #+#             */
/*   Updated: 2025/04/29 15:21:42 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template <class T>
class Array
{
	private:

		T*	array_;
		size_t	size_;

	public:

		Array();
		Array( unsigned int n );
		Array( const Array& copy );
		Array& operator=( const Array& copy );
		~Array();

		T	size() const;
		T&	operator[]( int pos );
		void	modifyArray( T pos, T newValue );

		class OutOfBoundException : public std::exception
		{
			virtual const char* what() const throw();	
		};
};

#include "Array.tpp"

#endif
