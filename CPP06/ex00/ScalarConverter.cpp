/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:57:29 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/16 14:12:01 by lparolis         ###   ########.fr       */
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
	if (specialParsingCases(literal) == true)
		throw ScalarConverter::SpecialCaseException();
	else
		formatParsing(literal);
}

void	printLiteral(const std::string &literal)
{
	if (specialExecutionCases(literal) == true)
		throw ScalarConverter::SpecialCaseException();
	else
		execConversion(literal);
	
}

void	ScalarConverter::convert(const std::string &literal)
{
	try{
		// check the string input
		inputParsing(literal);
		// print the string
		printLiteral(literal);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';	
	}
	
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