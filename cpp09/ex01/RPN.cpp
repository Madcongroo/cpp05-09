/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:09:09 by proton            #+#    #+#             */
/*   Updated: 2025/09/23 17:08:12 by proton           ###   ########.fr       */
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
	std::stringstream	sstream;
	std::stack<int>		stack;
	int					value1 = 0;
	int					value2 = 0;
	int					result = 0;

	sstream << userInput;

	while (sstream >> token)
	{
		if (token != "+" && token != "-" && token != "*" && token != "/")
			stack.push(std::atoi(token.c_str()));
		else
		{
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
	}
	return (result);
}
