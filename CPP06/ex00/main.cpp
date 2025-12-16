/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:56:29 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/16 17:46:31 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; ++i)
		{
			// std::cout << "Input: " << argv[i] << std::endl;
			ScalarConverter::convert(std::string(argv[i]));
			// std::cout << "-----------------------------" << std::endl;
		}
		return 0;
	}
	if (argc < 2)
	{
		const char* tests[] = {
			"A", "z", " ",
			"0", "42", "-42",
			"1.0f", "-3.14f", "123.456f",
			"1.0", "-2.71828", "0.0001",
			"nan", "nanf", "+inf", "+inff", "-inf", "-inff",
			"12..34", "..", ".12", "12.", "f12", "12f", "12.3ff", "abc",
			"340282346638528859811704183484516925440.0f",
			"1.7976931348623157e+308",
			"-1.7976931348623157e+308"
		};
	
		const size_t N = sizeof(tests)/sizeof(tests[0]);
		for (size_t i = 0; i < N; ++i)
		{
			std::cout << "Input: " << tests[i] << std::endl;
			ScalarConverter::convert(std::string(tests[i]));
			std::cout << "-----------------------------" << std::endl;
		}
	}
	return 0;
}