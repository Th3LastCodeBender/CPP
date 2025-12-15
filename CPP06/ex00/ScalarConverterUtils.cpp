/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:28:54 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/15 19:28:55 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverterUtils.hpp"

bool specialCases(const std::string &literal)
{
	if (literal.size() == 1 && std::isdigit(literal[0]) == false)
	{
		std::cout << "char: " << literal << std::endl;
		std::cout << "int: " << "Not displayable" << std::endl;
		std::cout << "float: " << "Not displayable" << std::endl;
		std::cout << "double: " << "Not displayable" << std::endl;
		return (true);
	}
	else if (literal.compare("nan") == 0 || literal.compare("nanf") == 0)
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
		return(true);
	}
	else if (literal.compare("-inf") == 0 || literal.compare("-inff") == 0)
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
		return(true);
	}
	else if (literal.compare("+inf") == 0 || literal.compare("+inff") == 0)
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "+inff" << std::endl;
		std::cout << "double: " << "+inf" << std::endl;
		return(true);
	}
	return (false);
}

bool charFinder(const std::string &literal)
{
	int index;
	int end;

	index = 0;
	end = literal.size();
	
	while (!literal.empty() && index < end)
	{
		if (std::isdigit(literal[index]) == false && literal[index] != '.' && literal[index] != 'f')
			return (false);
		index++;
	}
	return (true);
}

bool moreThanOneChar(const std::string &literal, char c)
{
	int	index;
	int	times;

	index = 0;
	times = 0;
	
	while (!literal.empty() && index < (int)literal.size())
	{
		if (literal[index] == c)
			times++;
		index++;
	}
	return times > 1;
}

bool dotAtBeginning(const std::string &literal)
{
	if (literal.empty())
		throw ScalarConverter::FormatParsingException("Empty literal received by dotAtBeginning!\n");
	else if (literal[0] == '.')
		return (true);
	else
		return (false);
}

bool dotAtEnd(const std::string &literal)
{
	if (literal.empty())
		throw ScalarConverter::FormatParsingException("Empty literal received by dotAtEnd!\n");
	else if (literal.back() == '.')
		return (true);
	else
		return (false);
}

bool fAtBeginning(const std::string &literal)
{
	if (literal.empty())
		throw ScalarConverter::FormatParsingException("Empty literal received by fAtBeginning!\n");
	else if (literal[0] == 'f')
		return (true);
	else
		return (false);
}

bool fAtEnd(const std::string &literal)
{
	if (literal.empty())
		throw ScalarConverter::FormatParsingException("Empty literal received by fAtEnd!\n");
	else if (literal.back() == 'f')
		return (true);
	else
		return (false);
}

bool dotNearF(const std::string &literal)
{
	if (literal.empty())
		throw ScalarConverter::FormatParsingException("Empty literal received by dotNearF!\n");
	std::size_t pos = literal.find('.');
	return pos != std::string::npos && pos + 1 < literal.size() && literal[pos + 1] == 'f';
}

void formatParsing(const std::string &literal)
{
	if (literal.size() != 1 && charFinder(literal) == false)
	{
		throw ScalarConverter::FormatParsingException("Passed a parameter with invalid letters!\n");
	}
	else if (literal.size() != 1 && (dotAtBeginning(literal) == true || dotAtEnd(literal) == true))
	{
		throw ScalarConverter::FormatParsingException("Passed a rational literal with misplaced dot!\n");
	}
	else if (literal.size() != 1 && moreThanOneChar(literal, '.') == true)
	{
		throw ScalarConverter::FormatParsingException("Passed a rational literal parameter with multiple dots!\n");
	}
	else if (literal.size() != 1 && moreThanOneChar(literal, 'f') == true)
	{
		throw ScalarConverter::FormatParsingException("Passed a rational literal parameter with multiple \"f\"!\n");
	}
	else if (literal.size() != 1 && fAtBeginning(literal) == true)
	{
		throw ScalarConverter::FormatParsingException("Passed a parameter with one \"f\" at the beginning!\n");
	}
	else if (literal.size() != 1 && literal.find('f') != std::string::npos && fAtEnd(literal) == false)
	{
		throw ScalarConverter::FormatParsingException("Passed a rational parameter with misplaced \"f\"!\n");
	}
	else if (literal.size() != 1 && dotNearF(literal) == true)
	{
		throw ScalarConverter::FormatParsingException("Passed a rational parameter with the dot near the \"f\"!\n");
	}
}

