/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 00:59:30 by proton            #+#    #+#             */
/*   Updated: 2025/10/14 10:19:54 by proton           ###   ########.fr       */
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
	size_ = n;
	array_ = new T[n];

}

template <class T>
Array<T>::Array( const Array& copy )
{
	std::cout << "in copy constructor of array class" << std::endl;
	this->size_ = copy.size_;
	this->array_ = new T[this->size_];
	for (unsigned int i = 0; i < this->size_; i++)
		this->array_[i] = copy.array_[i];
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
unsigned int Array<T>::size() const
{
	return (this->size_);	
}

template <class T>
void Array<T>::modifyArray( unsigned int pos, const T &newValue )
{
	if (pos >= this->size_)
		throw (OutOfBoundException());
	
	this->array_[pos] = newValue;
}

template <class T>
T& Array<T>::operator[]( unsigned int pos )
{
	if (pos >= this->size_)
		throw (OutOfBoundException());

	return (this->array_[pos]);
}

template <class T>
const char* Array<T>::OutOfBoundException::what() const throw()
{
	return ("Out of bound access");
}



