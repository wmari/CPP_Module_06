/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:41:04 by wmari             #+#    #+#             */
/*   Updated: 2024/08/29 16:18:57 by wmari            ###   ########.fr       */
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
public:
	ScalarConvert();
	ScalarConvert(ScalarConvert &copy);
	
	~ScalarConvert();
	
	ScalarConvert &operator=(ScalarConvert &copy);

	static void convert(std::string arg);

private:
	
	void	printINT(std::string arg);
};