/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:52:07 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/12 20:13:45 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"

bool	argumentsParsing(int argc, char *argv[]);

bool	mainParsing(int argc, char *argv[])
{
	if(argumentsParsing(argc, argv) == false)
		return;
	// if()
}

bool	argumentsParsing(int argc, char *argv[])
{
	if (argc < 3)
	{
		std::cerr << "Arguments Error: not enough arguments passed!" << std::endl;
		return (false);
	}
	else if (argc % 2 == 0)
	{
		std::cerr << "Arguments Error: the program can only handle an even number of digits!" << std::endl;
		return (false);
	}
	size_t digits_number = sizeof(argv) / sizeof(argv[0]);
	for (size_t i = 0; i < digits_number; i++)
	{
		if (valid_chars(argv[i]) == false)
			return (false);
		
	}
	
}