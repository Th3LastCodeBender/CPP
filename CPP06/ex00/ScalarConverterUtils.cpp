/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:28:54 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/16 17:45:04 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverterUtils.hpp"
#include <cmath>

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
		if (std::isdigit(literal[index]) == false && literal[index] != '.' && literal[index] != 'f' && literal[index] != '-' && literal[index] != '+')
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
		throw ScalarConverter::FormatParsingException("Empty literal received by dotAtBeginning!");
	else if (literal[0] == '.')
		return (true);
	else
		return (false);
}

bool dotAtEnd(const std::string &literal)
{
	if (literal.empty())
		throw ScalarConverter::FormatParsingException("Empty literal received by dotAtEnd!");
	else if (literal[literal.size() - 1] == '.')
		return (true);
	else
		return (false);
}

bool fAtBeginning(const std::string &literal)
{
	if (literal.empty())
		throw ScalarConverter::FormatParsingException("Empty literal received by fAtBeginning!");
	else if (literal[0] == 'f')
		return (true);
	else
		return (false);
}

bool fAtEnd(const std::string &literal)
{
	if (literal.empty())
		throw ScalarConverter::FormatParsingException("Empty literal received by fAtEnd!");
	else if (literal[literal.size() - 1] == 'f')
		return (true);
	else
		return (false);
}

bool dotNearF(const std::string &literal)
{
	if (literal.empty())
		throw ScalarConverter::FormatParsingException("Empty literal received by dotNearF!");
	std::size_t pos = literal.find('.');
	return pos != std::string::npos && pos + 1 < literal.size() && literal[pos + 1] == 'f';
}

void formatParsing(const std::string &literal)
{
	if (literal.size() != 1 && charFinder(literal) == false)
	{
		if (literal.find('e') != std::string::npos && literal.find('e') != 0 && 
			literal.find('e') != literal.size() && literal[literal.find('e') + 1] == '+')
		{
			std::string temp = literal;
			temp.erase(temp.find('e'), 1);
			temp.erase(temp.find('+'), 1);
			if (charFinder(temp) == false)
				throw ScalarConverter::FormatParsingException("Passed a parameter with invalid letters!");
		}
		else if (charFinder(literal) == false)
			throw ScalarConverter::FormatParsingException("Passed a parameter with invalid letters!");
	}
	else if (literal.size() != 1 && (dotAtBeginning(literal) == true || dotAtEnd(literal) == true))
	{
		throw ScalarConverter::FormatParsingException("Passed a rational literal with misplaced dot!");
	}
	else if (literal.size() != 1 && moreThanOneChar(literal, '.') == true)
	{
		throw ScalarConverter::FormatParsingException("Passed a rational literal parameter with multiple dots!");
	}
	else if (literal.size() != 1 && moreThanOneChar(literal, 'f') == true)
	{
		throw ScalarConverter::FormatParsingException("Passed a rational literal parameter with multiple \"f\"!");
	}
	else if (literal.size() != 1 && fAtBeginning(literal) == true)
	{
		throw ScalarConverter::FormatParsingException("Passed a parameter with one \"f\" at the beginning!");
	}
	else if (literal.size() != 1 && literal.find('f') != std::string::npos && fAtEnd(literal) == false)
	{
		throw ScalarConverter::FormatParsingException("Passed a rational parameter with misplaced \"f\"!");
	}
	else if (literal.size() != 1 && dotNearF(literal) == true)
	{
		throw ScalarConverter::FormatParsingException("Passed a rational parameter with the dot near the \"f\"!");
	}
}

// EXECUTION FUNCTIONS

void	execFloatCase(const std::string &literal)
{
	std::string temp = literal;
	temp.erase(temp.size() - 1);
	char	*end = 0;
	float	originalValue = std::strtof(temp.c_str(), &end);
	if (end == temp.c_str() || (end && *end != '\0'))
	{
		throw ScalarConverter::ExecutionException("Error during float conversion of the string!");
		return;
	}
	ToPrint values;
	if (!std::isfinite(originalValue) || originalValue < std::numeric_limits<int>::min() || originalValue > std::numeric_limits<int>::max())
		values.setIntImpossible();
	else
		values.setInt(static_cast<int>(originalValue));
	values.setChar(static_cast<char>(originalValue));
	values.setFloat(originalValue);
	values.setDouble(static_cast<double>(originalValue));
	std::cout << values;
}

void	execDoubleCase(const std::string &literal)
{
	char	*end = 0;
	double	originalValue = std::strtod(literal.c_str(), &end);
	if (end == literal.c_str() || (end && *end != '\0'))
	{
		throw ScalarConverter::ExecutionException("Error during double conversion of the string!");
		return;
	}
	ToPrint values;
	if (!std::isfinite(originalValue) || originalValue < std::numeric_limits<int>::min() || originalValue > std::numeric_limits<int>::max())
		values.setIntImpossible();
	else
		values.setInt(static_cast<int>(originalValue));
	values.setChar(static_cast<char>(originalValue));
	values.setFloat(static_cast<float>(originalValue));
	values.setDouble(originalValue);
	std::cout << values;
}

void	execIntCase(const std::string &literal)
{
	char *end = 0;
	long lval = std::strtol(literal.c_str(), &end, 10);
	if (end == literal.c_str() || (end && *end != '\0'))
	{
		throw ScalarConverter::ExecutionException("Error during int conversion of the string!");
		return;
	}
	ToPrint values;
	if (lval < std::numeric_limits<int>::min() || lval > std::numeric_limits<int>::max())
	{
		values.setIntImpossible();
		char *end2 = 0;
		double tmp = std::strtod(literal.c_str(), &end2);
		if (end2 == literal.c_str() || (end2 && *end2 != '\0'))
		{
			throw ScalarConverter::ExecutionException("Error during double conversion of the string (in intExecCase)!");
			return;
		}
		values.setChar(static_cast<char>(tmp));	
		values.setFloat(static_cast<float>(tmp));	
		values.setDouble(static_cast<double>(tmp));
	}
	else
	{
		values.setInt(static_cast<int>(lval));
		values.setChar(static_cast<char>(lval));	
		values.setFloat(static_cast<float>(lval));	
		values.setDouble(static_cast<double>(lval));
	}
	std::cout << values;
}

