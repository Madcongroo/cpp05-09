/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseScalar.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:11:28 by proton            #+#    #+#             */
/*   Updated: 2025/04/16 14:40:03 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSESCALAR_HPP
#define PARSESCALAR_HPP

#include <iostream>
#include <string>

#include "ScalarConverter.hpp"

int	parseScalar( std::string input );
int detectType( std::string input );

#endif