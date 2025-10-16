/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:09:26 by proton            #+#    #+#             */
/*   Updated: 2025/10/16 06:51:39 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << "stack top is " << mstack.top() << std::endl;

		mstack.pop();
		std::cout << "stack size after pop : " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);
		s.pop();
		std::cout << s.top() << std::endl;
		s.push(12);
		s.push(234);
		std::cout << "stack s size : " << s.size() << std::endl;

		std::stack<int> copy(mstack);
		std::cout << "stack top : " << copy.top() << std::endl;
		std::cout << "stack size : " << copy.size() << std::endl;
	}

	std::cout << "OTHER TEST WITH STD::LIST >>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;

	{
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << "stack top is " << mstack.back() << std::endl;

		mstack.pop_back();
		std::cout << "stack size after pop : " << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::list<int> s(mstack);
		s.pop_back();
		std::cout << s.back() << std::endl;
		s.push_back(12);
		s.push_back(234);
		std::cout << "stack s size : " << s.size() << std::endl;
	}
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(5);
		mstack.push(3);
		mstack.push(7);

		MutantStack<int>::const_iterator it = mstack.begin();
		MutantStack<int>::const_iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;

}
