/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:57:29 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/15 19:24:11 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ScalarConverterUtils.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &obj){(void)obj;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}


void	inputParsing(const std::string &literal)
{
	if (specialCases(literal) == true)
		throw ScalarConverter::SpecialCaseException();
	else
		formatParsing(literal);
}


void	ScalarConverter::convert(const std::string &literal)
{
	// check the string input
	try{
		inputParsing(literal);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';	
	}
	// print the values
	// printLiteral(literal);
	
}
// 231a
// a31
// 123ff
// 132.123ff
// 12..43
// 12.4.3
// .12
// 12.
// f23
// 12f43
// 123f.f
// 123.f