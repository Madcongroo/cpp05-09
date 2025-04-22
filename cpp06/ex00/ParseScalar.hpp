/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseScalar.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:11:28 by proton            #+#    #+#             */
/*   Updated: 2025/04/18 10:50:27 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSESCALAR_HPP
#define PARSESCALAR_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits.h>
#include <float.h>
#include <sstream>

#include "ScalarConverter.hpp"

enum	WhatValue
{
	ISCHAR		= 0,
	ISINT		= 1,
	ISFLOAT		= 2,
	ISDOUBLE	= 3,
	ISBAD		= 4,
	ISOTHER		= 5
};

int	parseScalar( std::string input );

#endif
