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
		Array( const Array& copy );
		Array& operator=( const Array& copy );
		~Array();

		T size();
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
	std::cout << "in copy constructor of array class" << std::endl;
	*this = copy;
}

template <class T>
Array<T>& Array<T>::operator=( const Array& copy )
{
	std::cout << "in copy operator of class array" << std::endl;
	if (this == &copy)
		return (*this);

	delete[] this->array_;
	this->array_ = new T[copy.size_];
	this->size_ = copy.size_;
	for (size_t i = 0; i < copy.size_; i++)
		this->array_[i] = copy.array_[i];
	return (*this);
}

template <class T>
Array<T>::~Array()
{
	delete this->array_;
}

template <class T>
T Array<T>::getArray( T pos )
{
	if (pos >= this->size_ || pos < 0)
		throw (OutOfBoundException());
	return (this->array_[pos]);
}

template <class T>
const char* Array<T>::OutOfBoundException::what() const throw()
{
	return ("Out of bound");
}

#endif
