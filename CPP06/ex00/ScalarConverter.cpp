/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:57:29 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/15 15:38:24 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &obj){}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	return (*this);
}

ScalarConverter::~ScalarConverter(){}

bool	specialCases(const std::string &literal)
{
	if (literal.size() == 1 && std::isdigit(literal[0]) == false)
	{
		std::cout << "char: " << literal << std::endl;
		std::cout << "int: " << "Not displayable" << std::endl;
		std::cout << "float: " << "Not displayable" << std::endl;
		std::cout << "double: " << "Not displayable" << std::endl;
		return (true);
	}
	else if (literal.compare("nan") || literal.compare("nanf"))
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
		return(true);
	}
	else if (literal.compare("-inf") || literal.compare("-inff"))
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
		return(true);
	}
	else if (literal.compare("+inf") || literal.compare("+inff"))
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "+inff" << std::endl;
		std::cout << "double: " << "+inf" << std::endl;
		return(true);
	}	
}
void	inputParsing(const std::string &literal)
{
	if (specialCases(literal) == true)
		throw ScalarConverter::SpecialCaseException();
	// else
		// formatParsing(literal);
}

// 231a
// a31
// 123ff
// 132.123ff
// 12f43
// 12..43
// 12.4.3
// .12
// 12.

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
	// std::cout << toFloat(literal)
	
}