/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:57:29 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/20 11:04:59 by lparolis         ###   ########.fr       */
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


void	literalParsing(const std::string &literal)
{
	if (specialParsingCases(literal) == true)
		throw ScalarConverter::SpecialCaseException();
	else
		formatParsing(literal);
}

void	literalConversion(const std::string &literal)
{
	if (literal.find('.') != std::string::npos && literal.find('f') != std::string::npos)
		execFloatCase(literal);
	else if ((literal.find('.') != std::string::npos ||
			 literal.find('e') != std::string::npos ||
			 literal.find('E') != std::string::npos) && 
			 literal.find('f') == std::string::npos)
		execDoubleCase(literal);
	else
		execIntCase(literal);
}

void	ScalarConverter::convert(const std::string &literal)
{
	try{
		// check the string input
		literalParsing(literal);
		// print the string
		literalConversion(literal);
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