/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:33:43 by proton            #+#    #+#             */
/*   Updated: 2025/09/23 17:06:58 by proton           ###   ########.fr       */
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
	private:
		Rpn( const Rpn& copy );
		Rpn& operator=( const Rpn& copy );

	public:
		Rpn();
		~Rpn();

		int	processCalculation( std::string& userInput );
};


#endif
