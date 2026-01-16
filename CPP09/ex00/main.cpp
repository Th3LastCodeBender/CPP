/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:50:58 by lparolis          #+#    #+#             */
/*   Updated: 2026/01/14 14:30:02 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc < 2 || argv[1][0] == 0)
	{
		std::cout << "Hello hello?? Missing something? No im not talking about your brain, that's always missing\n";
		return (0);
	}
	
	BitcoinExchange test;

	test.inputProcess(argv[1]);
	(void)argc;
	return (0);
}