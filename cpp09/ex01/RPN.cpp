/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:09:09 by proton            #+#    #+#             */
/*   Updated: 2025/09/23 15:41:17 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn()
{
	std::cout << "default constructor" << std::endl;
}

Rpn::Rpn( const Rpn& copy )
{
	std::cout << "copy operator constructor" << std::endl;
	*this = copy;
}

Rpn& Rpn::operator=( const Rpn& copy )
{
	std::cout << "copy assignation constructor" << std::endl;
	if (this != &copy)
	{
		
	}
	return (*this);
}

Rpn::~Rpn()
{
	std::cout << "rpn destructor" << std::endl;
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
		std::cout << token << std::endl;
		if (token != "+" && token != "-" && token != "*" && token != "/")
			stack.push(std::atoi(token.c_str()));
		else
		{
			if (token == "*")
			{
				value1 = stack.top();
				stack.pop();
				value2 = stack.top();
				result = value1 * value2;
				stack.pop();
			}
			else if (token == "-")
			{
				value1 = stack.top();
				stack.pop();
				value2 = stack.top();
				result = value1 - value2;
				stack.pop();
			}
			else if (token == "+")
			{
				value1 = stack.top();
				stack.pop();
				value2 = stack.top();
				result = value1 + value2;
				stack.pop();
			}
			else if (token == "/")
			{
				value1 = stack.top();
				stack.pop();
				value2 = stack.top();
				result = value1 / value2;
				stack.pop();
			}
			std::cout << "RESULT : " <<  result << std::endl;
			stack.push(result);
		}
	}
	return (result);
}
