/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:38:49 by proton            #+#    #+#             */
/*   Updated: 2025/10/15 15:18:48 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <list>

template<typename T, class Container = std::deque<T> >
class	MutantStack : public std::stack<T>
{
	public:

	MutantStack();
	MutantStack( const MutantStack& copy );
	MutantStack& operator=( const MutantStack& copy );
	~MutantStack();

	typedef typename Container::iterator iterator;
	iterator	begin() { return (this->c.begin()); }
	iterator	end() { return (this->c.end()); }
};

#include "MutantStack.tpp"


#endif
