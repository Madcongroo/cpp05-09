/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:09:09 by proton            #+#    #+#             */
/*   Updated: 2025/10/17 13:40:35 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn()
{
}

Rpn::Rpn( const Rpn& copy )
{
	std::cout << "copy operator constructor" << std::endl;
	*this = copy;
}

Rpn& Rpn::operator=( const Rpn& copy )
{
	(void)copy;
	std::cout << "copy assignation constructor" << std::endl;
	return (*this);
}

Rpn::~Rpn()
{
}

int	Rpn::processCalculation( std::string& userInput )
{
	std::string			token;
	std::stack<int>		stack;
	size_t				i = 0;
	int					value1 = 0;
	int					value2 = 0;
	int					result = 0;

	while (i < userInput.size())
	{
		token = userInput[i];
		if (userInput[i] == ' ')
		{
			i++;
			continue ;
		}
		if (token != "+" && token != "-" && token != "*" && token != "/")
			stack.push(std::atoi(token.c_str()));
		else
		{
			if (stack.size() != 2)
			{
				std::cout << "Error" << std::endl;
				exit(EXIT_FAILURE);
			}
			if (token == "*")
			{
				value2 = stack.top();
				stack.pop();
				value1 = stack.top();
				result = value1 * value2;
				stack.pop();
			}
			else if (token == "-")
			{
				value2 = stack.top();
				stack.pop();
				value1 = stack.top();
				result = value1 - value2;
				stack.pop();
			}
			else if (token == "+")
			{
				value2 = stack.top();
				stack.pop();
				value1 = stack.top();
				result = value1 + value2;
				stack.pop();
			}
			else if (token == "/")
			{
				value2 = stack.top();
				stack.pop();
				value1 = stack.top();
				result = value1 / value2;
				stack.pop();
			}
			stack.push(result);
		}
		i++;
	}
	if (stack.size() > 1)
	{
		std::cerr << "Error" << std::endl;
		exit(EXIT_FAILURE);
	}
	return (result);
}
