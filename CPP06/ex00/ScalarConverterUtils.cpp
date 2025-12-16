/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:28:54 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/16 14:18:39 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverterUtils.hpp"

bool specialParsingCases(const std::string &literal)
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
	else if (literal[literal.size() - 1] == '.')
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
	else if (literal[literal.size() - 1] == 'f')
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

// EXECUTION FUNCTIONS

bool	specialExecutionCases(const std::string &literal)
{
	(void)literal;
	return false;
}

void	execConversion(const std::string literal)
{
	if (literal.find('.') != std::string::npos && literal.find('f') != std::string::npos)
	{
		std::string s = literal;
		if (!s.empty() && s[s.size() - 1] == 'f')
			s.erase(s.size() - 1);
		char *end = 0;
		
		float originalValue = std::strtof(s.c_str(), &end);
		if (end == s.c_str() || (end && *end != '\0'))
		{
			throw ScalarConverter::ExecutionException("Error during float conversion of the string!\n");
			return;
		}
		char   charValue = static_cast<char>(originalValue);
		int    intValue = static_cast<int>(originalValue);
		double doubleValue = static_cast<double>(originalValue);
		
		ToPrint values(charValue, intValue, originalValue, doubleValue);
		std::cout << values;
	}
	else if (literal.find('.') != std::string::npos && literal.find('f') == std::string::npos)
	{
		char *end = 0;
		double originalValue = std::strtod(literal.c_str(), &end);
		if (end == literal.c_str() || (end && *end != '\0'))
		{
			throw ScalarConverter::ExecutionException("Error during double conversion of the string!\n");
			return;
		}
		char  charValue = static_cast<char>(originalValue);
		int   intValue = static_cast<int>(originalValue);
		float floatValue = static_cast<float>(originalValue);
		
		ToPrint values(charValue, intValue, floatValue, originalValue);
		std::cout << values;
	}
	else
	{
		char	*end = 0;
		long	lval = ::strtol(literal.c_str(), &end, 10);
		if (end == literal.c_str() || (end && *end != '\0'))
		{
			throw ScalarConverter::ExecutionException("Error during int conversion of the string!\n");
			return;
		}
		if (lval < std::numeric_limits<int>::min() || lval > std::numeric_limits<int>::max())
		{
			throw ScalarConverter::ExecutionException("Integer out of range!\n");
			return;
		}
		int		originalValue = static_cast<int>(lval);
		char 	charValue = static_cast<char>(originalValue);
		float	floatValue = static_cast<float>(originalValue);
		double 	doubleValue = static_cast<double>(originalValue);

		ToPrint values(charValue, originalValue, floatValue, doubleValue);
		std::cout << values;
	}
	
}

