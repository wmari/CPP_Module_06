/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:41:04 by wmari             #+#    #+#             */
/*   Updated: 2024/08/29 12:36:10 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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

private:
	void	convertINT(std::string arg);
	void	convertCHAR(std::string arg);
	void	convertFLOAT(std::string arg);
	void	convertDOUBLE(std::string arg);
	void	convertINF(std::string arg);
public:
	static void convert(std::string arg);
};