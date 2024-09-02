/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:40:46 by wmari             #+#    #+#             */
/*   Updated: 2024/09/02 16:08:30 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert()
{
	return ;
}

ScalarConvert::ScalarConvert(ScalarConvert &copy)
{
	(void)copy;
	return ;
}

ScalarConvert::~ScalarConvert()
{
	return ;
}

ScalarConvert &ScalarConvert::operator=(ScalarConvert &copy)
{
	return copy;
}

void ScalarConvert::convert(std::string arg)
{
	int type;
	if (arg.compare("-inff") == 0 || arg.compare("+inff") == 0 || arg.compare("-inf") == 0 ||
		arg.compare("+inf") == 0 || arg.compare("nan") == 0 || arg.compare("nanf") == 0)
		type = INF;
	else if (arg.length() == 1 &&
		(arg[0] == '+' || arg[0] == '-' || arg[0] == 'f' || arg[0] == '.'))
		type = CHAR;
	else if (arg.find_first_of("+-") != arg.find_last_of("+-") && arg.find_first_of("+-") != std::string::npos)
		type = ERROR;
	else if (arg.find_first_not_of("+-1234567890") == std::string::npos)
	{
		if (arg.find_first_of("+-") != 0 && arg.find_first_of("+-") != std::string::npos)
			type = ERROR;
		else
			type = INT;
	}
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
				(arg.length() == 1 && std::isalpha(arg[0])))
		type = CHAR;
	else
		type = ERROR;

	if (type == INT && (strtold(arg.c_str(), NULL) > INT_MAX || strtold(arg.c_str(), NULL) < INT_MIN))
		type = DOUBLE;

	if (type == DOUBLE && (strtold(arg.c_str(), NULL) > DBL_MAX || strtold(arg.c_str(), NULL) < -DBL_MAX))
		type = ERROR;

	if (type == INT)
	{
		int num = atoi(arg.c_str());
		if ((num < UCHAR_MAX && num >= 0) && isprint(num))
			std::cout << "char:\t'" << static_cast<char>(num) <<"'" << std::endl;
		else if (num < UCHAR_MAX && num >= 0)
			std::cout << "char:\tNon displayable" << std::endl;
		else
			std::cout << "char:\timpossible" << std::endl;
		std::cout << "int:\t" << num << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float:\t" << static_cast<float>(num) << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double:\t" << static_cast<double>(num) << std::endl;
	}
	else if (type == FLOAT)
	{
		float num = atof(arg.c_str());
		int prec;
		size_t pointpos = arg.find('.');
		if (pointpos == std::string::npos)
			prec = 1;
		else
			prec = arg.length() - pointpos - 2;
		if ((num < UCHAR_MAX && num >= 0) && isprint(num))
			std::cout << "char:\t'" << static_cast<char>(num) <<"'" << std::endl;
		else if (num < UCHAR_MAX && num >= 0)
			std::cout << "char:\tNon displayable" << std::endl;
		else
			std::cout << "char:\timpossible" << std::endl;
		std::cout << "int:\t" << static_cast<int>(num) << std::endl;
		std::cout << std::fixed << std::setprecision(prec) << "float:\t" << num << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(prec) << "double:\t" << static_cast<double>(num) << std::endl;
	}
	else if (type == DOUBLE)
	{
		double num = strtod(arg.c_str(), NULL);
		int prec;
		size_t pointpos = arg.find('.');
		if (pointpos == std::string::npos)
			prec = 1;
		else
			prec = arg.length() - pointpos - 1;
		if ((num < UCHAR_MAX && num >= 0) && isprint(num))
			std::cout << "char:\t'" << static_cast<char>(num) <<"'" << std::endl;
		else if (num < UCHAR_MAX && num >= 0)
			std::cout << "char:\tNon displayable" << std::endl;
		else
			std::cout << "char:\timpossible" << std::endl;
		std::cout << "int:\t" << static_cast<int>(num) << std::endl;
		std::cout << std::fixed << std::setprecision(prec) << "float:\t" << static_cast<float>(num) << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(prec) << "double:\t" << num << std::endl;
	}
	else if (type == CHAR)
	{
		char c = arg[0];
		std::cout << "char:\t'" << c << "'" << std::endl;
		std::cout << "int:\t" << static_cast<int>(c) << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float:\t" << static_cast<float>(c) << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double:\t" << static_cast<double>(c) << std::endl;
	}
	else if (type == INF)
	{
		std::cout << "char:\timpossible" << std::endl;
		std::cout << "int:\timpossible" << std::endl;
		if (arg.compare("-inff") == 0 || arg.compare("-inf") == 0)
			std::cout << "float:\t-inff" << std::endl;
		else if (arg.compare("+inf") == 0 || arg.compare("+inff") == 0)
			std::cout << "float:\t+inff" << std::endl;
		else
			std::cout << "float:\tnanf" << std::endl;
		if (arg.compare("-inff") == 0 || arg.compare("-inf") == 0)
			std::cout << "double:\t-inf" << std::endl;
		else if (arg.compare("+inf") == 0 || arg.compare("+inff") == 0)
			std::cout << "double:\t+inf" << std::endl;
		else
			std::cout << "double:\tnan" << std::endl;
	}
	else
		std::cout << "Error" << std::endl;
}
