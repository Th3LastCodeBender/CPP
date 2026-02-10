/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:18:12 by lparolis          #+#    #+#             */
/*   Updated: 2026/02/10 18:50:46 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "BitcoinExchange.hpp"

bool	dateChecker(int line, long int Year, long int Month, long int Day)
{
	// std::cout << "GIORNI: " << Year << "-" << Month << "-" << Day << std::endl;
	if (Year > 2022 || Year < 2009 || Month > 12 || Month < 1 || Day > 31 || Day < 1)
	{
		// std::cout << "Year: " << Year << " Month: " << Month << " Day: " << Day << std::endl;
		std::cout << "Skipped line [" << line << "] Cause of bad date values\n";
		return false;
	}
	if ((Month == 4 || Month == 6 || Month == 9 || Month == 11) && Day == 31)
	{
		std::cout << "Skipped line [" << line << "] Cause of bad day values ... (31 not compatible with current month!)\n";
		return false;
	}
	if ((isLeapYear(Year) == true && Month == 2 && Day > 29) || (isLeapYear(Year) == false && Month == 2 && Day > 28))
	{
		std::cout << "Skipped line [" << line << "] Cause of bad Day/Month values ... (Leap years dude!)\n";
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

bool	checkValueChars(int line, std::string const &value)
{	
	if (value.empty())
	{
		std::cout << "Passed value at line " << line << " is empty!" << std::endl;
		return false;
	}
	
	bool dot_seen = false;
		
	for (size_t i = 0; i < value.size(); i++)
	{
		if (value[i] == '.')
		{
			if (dot_seen == true)
			{
				std::cout << "Too many dots at line " << line << std::endl;
				return false;
			}
			if (i == 0 || i == value.size() - 1)
			{
				std::cout << "Misplaced dots at line " << line << std::endl;
				return false;
			}
			dot_seen = true;
		}
		else if (std::isdigit(value[i]) == 0)
		{
			std::cout << "One of line " << line << " value chars is not a number!" << std::endl;
			return false;
		}
	}
	return true;
}


bool	checkValueLimits(int line, std::string const &value, char separator)
{
	char *end = 0;
	long int convertedValue = std::strtof(value.c_str(), &end);
	
	if (end == value.c_str() || (end && *end != '\0'))
	{
		std::cout << "Error during value conversion at line " << line << std::endl;
		return false;
	}
	if (separator == '|' && (convertedValue > 1000|| convertedValue < 0))
	{
		std::cout << "ExchangeTable value of input database out of acceptable range at line " << line << std::endl;
		return false;
	}
	else if (separator == ',' && (convertedValue > 66063.56 || convertedValue < 0))
	{
		std::cout << "Input value out of record at line " << line << std::endl;
		return false;
	}
	return true;
}

float	convertValue(std::string value)
{
	char *end = 0;
	float convertedValue = std::strtof(value.c_str(), &end);
	
	if (end == value.c_str() || (end && *end != '\0'))
		throw BitcoinExchange::ParsingException("Error during conversion of value!");
	return convertedValue;
}