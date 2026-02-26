/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:18:12 by lparolis          #+#    #+#             */
/*   Updated: 2026/02/26 22:01:21 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "BitcoinExchange.hpp"

bool	dateChecker(long int Year, long int Month, long int Day)
{
	// std::cout << "GIORNI: " << Year << "-" << Month << "-" << Day << std::endl;
	if (Year > 2022 || Year < 2009 || Month > 12 || Month < 1 || Day > 31 || Day < 1)
	{
		std::cout << "Error: bad input => " << Year << "-" << Month << "-" << Day << std::endl;
		return false;
	}
	if ((Month == 4 || Month == 6 || Month == 9 || Month == 11) && Day == 31)
	{
		std::cout << "Error: bad input => " << Year << "-" << Month << "-" << Day << std::endl;
		return false;
	}
	if ((isLeapYear(Year) == true && Month == 2 && Day > 29) || (isLeapYear(Year) == false && Month == 2 && Day > 28))
	{
		std::cout << "Error: bad input => " << Year << "-" << Month << "-" << Day << std::endl;
		return false;
	}
	return true;
}

bool	isLeapYear(long int Year)
{
    if (Year % 400 == 0)
        return true;
    if (Year % 100 == 0)
        return false;
    if (Year % 4 == 0)
        return true;
    return false;
}

bool	checkValueChars(std::string const &value)
{	
	if (value.empty())
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	
	bool dot_seen = false;
		
	for (size_t i = 0; i < value.size(); i++)
	{
		if (value[i] == '.')
		{
			if (dot_seen == true)
			{
				std::cout << "Error: bad input => " << value << std::endl;
				return false;
			}
			if (i == 0 || i == value.size() - 1)
			{
				std::cout << "Error: bad input => " << value << std::endl;
				return false;
			}
			dot_seen = true;
		}
		else if (std::isdigit(value[i]) == 0 && value[i] != '-')
		{
			std::cout << "Error: bad input => " << value << std::endl;
			return false;
		}
	}
	return true;
}


bool	checkValueLimits(std::string const &value, char separator)
{
	char *end = 0;
	long int convertedValue = std::strtof(value.c_str(), &end);
    
	if (end == value.c_str() || (end && *end != '\0'))
	{
		std::cout << "Error: bad input => " << value << std::endl;
		return false;
	}
	if (separator == '|' && (convertedValue > 1000 || convertedValue < 0))
	{
		if (convertedValue < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else
			std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	else if (separator == ',' && (convertedValue > 66063.56 || convertedValue < 0))
	{
		std::cout << "Error: bad input => " << value << std::endl;
		return false;
	}
	return true;
}

float	convertValue(std::string value)
{
	char *end = 0;
	float convertedValue = std::strtof(value.c_str(), &end);
	
	if (end == value.c_str() || (end && *end != '\0'))
		throw BitcoinExchange::ParsingException(std::string("Error: bad input => ") + value);
	return convertedValue;
}