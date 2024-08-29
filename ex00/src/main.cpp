/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:50:44 by wmari             #+#    #+#             */
/*   Updated: 2024/08/29 09:23:46 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Program take one argument" << std::endl;
	else
	{
		std::string input(argv[1]);
		ScalarConvert::convert(input);
	}
	return 0; 
}