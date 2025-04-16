/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseScalar.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:11:45 by proton            #+#    #+#             */
/*   Updated: 2025/04/16 15:58:54 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParseScalar.hpp"

void	displayLiteral( std::string input )
{
	if (input == "Non displayable")
	{
		std::cout << "char : " << input << std::endl;
		std::cout << "int : " << 0 << std::endl;
		std::cout.precision(2) << "float : " << 0 << std::endl;
		std::cout.precision(2) << "double : " << 0.0 << std::endl;
		return ;
	}
}

int	detectType( std::string input )
{
	std::cout << input << std::endl;
	return (0);
}

int	parseScalar( std::string input )
{
	
	if (input.length() > 1)
	{
		double d = atof(input.c_str());
		std::cout << d << std::endl;
		if (d == 0)
			return (displayLiteral("Non displayable"), 0);
	}
	
	detectType( input );

	return (0);
}
