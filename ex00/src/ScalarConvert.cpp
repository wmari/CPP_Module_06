/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:40:46 by wmari             #+#    #+#             */
/*   Updated: 2024/08/29 17:39:56 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert()
{
	return ;
}

ScalarConvert::ScalarConvert(ScalarConvert &copy)
{
	return ;
}

ScalarConvert::~ScalarConvert()
{
	return ;
}

ScalarConvert &ScalarConvert::operator=(ScalarConvert &copy)
{
	return ;
}
void	ScalarConvert::convert(std::string arg)
{
	int type;
	if (arg.compare("-inff") == 0 || arg.compare("+inff") == 0 || arg.compare("-inf") == 0 ||
		arg.compare("+inf") == 0 || arg.compare("nan") == 0)
		type = INF;
	else if (arg.length() == 1 &&
		(arg[0] == '+' || arg[0] == '-' || arg[0] == 'f' || arg[0] == '.'))
		type = CHAR;
	else if (arg.find_first_not_of("+-") != arg.find_last_of("+-"))
		type = ERROR;
	else if (arg.find_first_not_of("+-1234567890") == std::string::npos)
		type = INT;
	else if (arg.find_first_not_of("+-1234567890.") == std::string::npos)
	{
		if (arg.find_first_of(".") != arg.find_last_of(".") ||
				isdigit(arg[arg.find_first_of(".") + 1]) == false ||
				arg.find_first_of(".") == 0)
			type = ERROR;
		else
			type = DOUBLE;
	}
	else if (arg.find_first_not_of("+-1234567890.f") == std::string::npos)
	{
		if (arg.find_first_of(".") != arg.find_last_of(".") ||
				arg.find_first_of(".") == 0 ||
				arg.find_first_of("f") != arg.find_last_of("f") ||
				arg.find_first_of("f") == 0 ||
				arg[arg.find_first_of("f") + 1] != '\0' ||
				arg.find_first_of("f") - arg.find_first_of(".") == 1)
			type = ERROR;
		else
			type = FLOAT;
	}
	else if ((arg.length() == 1 && std::isprint(arg[0])) ||
				arg.length() == 1 && std::isalpha(arg[0]))
		type = CHAR;
	else
		type = ERROR;

	if (type == INT || type == DOUBLE || type == FLOAT)
	{
		double argdouble;
	}

}

