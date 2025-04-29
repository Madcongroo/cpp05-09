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
		T	size_;

	public:

		Array();
		Array( unsigned int n );
		//Array( const Array& copy );
		//Array& operator=( const Array& copy );
		~Array();

		//T size();
		T getArray( T pos );

		class OutOfBoundException : public std::exception
		{
			virtual const char* what() const throw();	
		};
};

template <class T>
Array<T>::Array() : size_(0), array_( new T[NULL] ) 
{
	std::cout << "in Array template base class constructor" << std::endl;
}

template <class T>
Array<T>::Array( unsigned int n ) : array_( new T[n] ), size_(n) 
{
	std::cout << "in direct assignation of class template Array" << std::endl;
}

template <class T>
Array<T>::Array( const Array& copy )
{
	*this = new 
}

template <class T>
Array<T>::~Array()
{
	delete this->array_;
}

template <class T>
T Array<T>::getArray( T pos )
{
	if (pos >= this->size_)
		throw (std::exception());
	return (this->array_[pos]);
}

template <class T>
Array<T>::OutOfBoundException::what() const throw()
{
	return ("Out of bound");
}

#endif
