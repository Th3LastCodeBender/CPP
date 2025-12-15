/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:56:29 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/15 18:55:44 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc < 2 || !argv || argv[1][0] == '\0')
		std::cout << "Bad argument!\n";
	
	for (size_t i = 1; argv[i]; i++)
	{
		ScalarConverter::convert(argv[i]);
	}
	
	return (0);
}