/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:41:04 by wmari             #+#    #+#             */
/*   Updated: 2024/09/02 14:50:25 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <limits>
#include <climits>
#include <cctype>
#include <iomanip>


enum type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INF,
	ERROR
};

class ScalarConvert
{
public:
	ScalarConvert();
	ScalarConvert(ScalarConvert &copy);
	
	virtual ~ScalarConvert() = 0;
	
	ScalarConvert &operator=(ScalarConvert &copy);

	static void convert(std::string arg);
};