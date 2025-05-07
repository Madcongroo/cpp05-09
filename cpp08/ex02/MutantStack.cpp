/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:06:57 by proton            #+#    #+#             */
/*   Updated: 2025/05/07 15:44:45 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T, class Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>::Stack()
{
	std::cout << "in base constructor" << std::endl;
}

template<typename T, class Container>
MutantStack<T, Container>::MutantStack( const MutantStack& copy )
{
	std::cout << "in copy constructor" << std::endl;
	*this = copy;
}

template<typename T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=( const MutantStack& copy )
{
	std::cout << "in copy operator class" << std::endl;

	if (this != &copy)
		std::stack<T, Container>::operator=(copy);

	return (*this);
}

template<typename T, class Container>
MutantStack<T, Container>::~MutantStack()
{
	std::cout << "in Mutant class destructor" << std::endl;
}



