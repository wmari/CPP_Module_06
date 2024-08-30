/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:41:04 by wmari             #+#    #+#             */
/*   Updated: 2024/08/30 13:47:32 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <limits>
#include <climits>
#include <iomanip>
#include <cctype>


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
	
	~ScalarConvert();
	
	ScalarConvert &operator=(ScalarConvert &copy);

	static void convert(std::string arg)
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
		// std::cout << std::setprecision(13);
		if (type == INT || type == DOUBLE || type == FLOAT)
		{
			double argdouble = std::strtod(arg.c_str(), NULL);
			if (argdouble < UCHAR_MAX && argdouble >= 1)
				std::cout << "char:\t'" << static_cast<char>(argdouble) <<"'" << std::endl;
			else if (arg.length() > 1)
				std::cout << "char:\timpossible" << std::endl;
			else
				std::cout << "char:\tNon displayable" << std::endl;
			if (argdouble >= std::numeric_limits<int>::min() && argdouble <= std::numeric_limits<int>::max())
				std::cout << "int:\t" << static_cast<int>(argdouble) << std::endl;
			else
				std::cout << "int:\timpossible" << std::endl;
			std::cout << "float:\t" << static_cast<float>(argdouble) << std::endl;
			std::cout << "double:\t" << argdouble << std::endl;
		}
		else if (type == CHAR)
		{
			char c = arg[0];
			std::cout << "char:\t" << c << std::endl;
			std::cout << "int:\t" << static_cast<int>(c) << std::endl;
			std::cout << "float:\t" << static_cast<float>(c) << std::endl;
			std::cout << "double:\t" << static_cast<double>(c) << std::endl;
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
};