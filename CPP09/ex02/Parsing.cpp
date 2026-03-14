/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:52:07 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/14 21:53:52 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"

bool	argumentsParsing(int argc, char *argv[]);

bool	mainParsing(int argc, char *argv[])
{
	if(argumentsParsing(argc, argv) == false)
		return (false);
	return (true);
}

bool	argumentsParsing(int argc, char *argv[])
{
	if (argc < 3)
	{
		std::cerr << "Arguments Error: not enough arguments passed!" << std::endl;
		return (false);
	}
	else if (argc > 10000)
	{
		std::cerr << "Arguments Error: wanna stay here all weeK?" << std::endl;
		return (false);
	}
	for (int i = 1; i < argc; i++)
	{
		if (valid_chars(argv[i]) == false)
			return (false);
	}
	return (true);
}