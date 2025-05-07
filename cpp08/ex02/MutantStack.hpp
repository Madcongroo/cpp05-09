/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:38:49 by proton            #+#    #+#             */
/*   Updated: 2025/05/07 18:05:03 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <deque>
#include <stack>

template<typename T, class Container = std::deque<T>>
class	MutantStack : public std::stack<T>
{
	public:

	MutantStack();
	MutantStack( const MutantStack& copy );
	MutantStack& operator=( const MutantStack& copy );
	~MutantStack();

	typedef MutantStack<T, Container> iterator;
};


#endif
