/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseScalar.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:11:28 by proton            #+#    #+#             */
/*   Updated: 2025/10/13 15:25:02 by bproton          ###   ########.fr       */
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
#include <math.h>

#include "ScalarConverter.hpp"

#define ISCHAR      1
#define ISINT       2
#define ISFLOAT     3
#define ISDOUBLE    4
#define ISINFNAN    5
#define ISNEGINFNAN 6
#define ISBAD       0

int	parseScalar( const std::string &input );

#endif
