/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 00:59:30 by proton            #+#    #+#             */
/*   Updated: 2025/04/29 15:54:50 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T>
Array<T>::Array() 
{
	std::cout << "in Array template base class constructor" << std::endl;
	size_ = 0;
	array_ = new T[0];
}

template <class T>
Array<T>::Array( unsigned int n )
{
	std::cout << "in direct assignation of class template Array" << std::endl;
	if (n <= 0)
		throw (std::exception());
	size_ = n;
	array_ = new T[n];

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
	delete[] this->array_;
}

template <class T>
T Array<T>::size() const
{
	return (this->size_);	
}

template <class T>
void Array<T>::modifyArray( T pos, T newValue )
{
	if (pos >= this->size_ || pos < 0)
		throw (OutOfBoundException());
	
	this->array_[pos] = newValue;
}

template <class T>
T& Array<T>::operator[]( int pos )
{
	if ((size_t)pos >= this->size_ || pos < 0)
		throw (OutOfBoundException());

	return (this->array_[pos]);
}

template <class T>
const char* Array<T>::OutOfBoundException::what() const throw()
{
	return ("Out of bound");
}



