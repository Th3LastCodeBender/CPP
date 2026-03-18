/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:50:58 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/18 18:38:40 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc < 2 || argv[1][0] == 0)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	
	try
	{
		BitcoinExchange test;
		test.inputProcess(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}
