/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:33:43 by proton            #+#    #+#             */
/*   Updated: 2025/09/23 15:29:46 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include <sstream>
#include <cstdlib>

class	Rpn
{
	// private:
	// 	std::stack<int>	_calculation;

	public:
		Rpn();
		Rpn( const Rpn& copy );
		Rpn& operator=( const Rpn& copy );
		~Rpn();

		int	processCalculation( std::string& userInput );
};


#endif
