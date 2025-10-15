/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:09:26 by proton            #+#    #+#             */
/*   Updated: 2025/10/15 15:23:02 by bproton          ###   ########.fr       */
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
	return 0;

}
