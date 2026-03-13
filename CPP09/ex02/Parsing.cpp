/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:52:07 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/13 11:51:26 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"

bool	argumentsParsing(int argc, char *argv[]);

bool	mainParsing(int argc, char *argv[])
{
	if(argumentsParsing(argc, argv) == false)
		return (false);
	// if()
	return (true);
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
	for (int i = 1; i < argc; i++)
	{
		if (valid_chars(argv[i]) == false)
			return (false);
	}
	return (true);
}