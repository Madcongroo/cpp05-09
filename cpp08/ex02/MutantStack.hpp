/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:38:49 by proton            #+#    #+#             */
/*   Updated: 2025/10/15 23:08:51 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <list>

template<typename T>
class	MutantStack : public std::stack<T>
{
	public:

	MutantStack();
	MutantStack( const MutantStack& copy );
	MutantStack& operator=( const MutantStack& copy );
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::iterator const_iterator;

	iterator	begin() { return (this->c.begin()); }
	iterator	end() { return (this->c.end()); }
	
	const_iterator	begin() const { return (this->c.begin()); }
	const_iterator	end() const { return (this->c.end()); }
};

#include "MutantStack.tpp"


#endif
