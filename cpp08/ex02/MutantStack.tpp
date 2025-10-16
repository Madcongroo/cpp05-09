/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:06:57 by proton            #+#    #+#             */
/*   Updated: 2025/10/15 23:08:45 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack()
{
	std::cout << "in base constructor" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack( const MutantStack& copy )
{
	std::cout << "in copy constructor" << std::endl;
	*this = copy;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=( const MutantStack& copy )
{
	std::cout << "in copy operator class" << std::endl;

	if (this != &copy)
		std::stack<T>::operator=(copy);

	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "in Mutant class destructor" << std::endl;
}
