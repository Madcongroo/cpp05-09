/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 01:20:54 by proton            #+#    #+#             */
/*   Updated: 2025/10/13 19:27:24 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "B.hpp"
#include "A.hpp"
#include "C.hpp"

Base* generate( void )
{
	unsigned int	seed = 0;

	Base*		newBase;

	srand(time(NULL));
	seed = rand();

	switch (seed % 3)
	{
		case 0:
		newBase = new A;
		return (newBase);

		case 1:
		newBase = new B;
		return (newBase);

		case 2:
		newBase = new C;
		return (newBase);
	}
	return (NULL);
}

void	identify( Base* p )
{
	if (dynamic_cast<A*>(p) == NULL)
		std::cout << "Class is not type A" << std::endl;
	else
	{
		std::cout << "Class is of type A" << std::endl;
		return ;
	}
	if (dynamic_cast<B*>(p) == NULL)
		std::cout << "Class is not type B" << std::endl;
	else
	{
		std::cout << "Class is of type B" << std::endl;
		return ;
	}
	if (dynamic_cast<C*>(p) == NULL)
		std::cout << "Class is not type C" << std::endl;
	else
	{
		std::cout << "Class is of type C" << std::endl;
		return ;
	}
}

void	identify( Base& p )
{

		try{
			A test = dynamic_cast<A&>(p);
			std::cout << "Class is of type A in identify function of reference" << std::endl;
		}	
		catch (std::exception& e)
		{
		}

		try{
			B test = dynamic_cast<B&>(p);
			std::cout << "Class is of type B in identify function of reference" << std::endl;
		}	
		catch (std::exception& e)
		{
		}
		try{
			C test = dynamic_cast<C&>(p);
			std::cout << "Class is of type C in identify function of reference" << std::endl;
		}	
		catch (std::exception& e)
		{
		}
	
}

int main()
{
	std::cout << "TEST PTR" << std::endl;
	Base* test;

	test = generate();
	identify( test );

	Base* test2;
	std::cout << "TEST REF" << std::endl;
	test2 = generate();
	identify(*test2);
	delete test2;

	return (0);	
}
