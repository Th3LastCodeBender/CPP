/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:10:42 by lparolis          #+#    #+#             */
/*   Updated: 2026/01/09 18:23:14 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int line = 0;
void	lineParsing(std::string buffer);

BitcoinExchange::BitcoinExchange()
{
	DBG_MSG("BitcoinExchange constructor called");
	
	std::ifstream	table("data.csv");
	std::string		buffer;

	if (table.fail())
		throw ParsingException("Failed to open the .csv file!");
	while (std::getline(table, buffer) && line < 10)
	{
		++line;
		lineParsing(buffer);	
	}
	
	
}

void	lineParsing(std::string buffer)
{
	if (buffer.compare("date,exchange_rate") == 0)
		return;
	if(buffer.empty() || buffer.find(',') == std::string::npos)
	{
		std::cout << "Skipped line [" << line << "] Cause of bad data format\n";
		return;
	}
	
	size_t		commaPos = buffer.find(',');
	std::string	date = buffer.substr(0, commaPos);
	std::string	value = buffer.substr(commaPos + 1, buffer.length() - (commaPos + 1));
	// std::cout << date << " | " << value << std::endl;
	
	if (date.find('-') == std::string::npos || date.find_first_of('-') == date.find_last_of('-'))
	{
		std::cout << "Skipped line [" << line << "] Cause of bad date format\n";
		return;
	}
	
	size_t		firstDateSeparator = date.find('-');
	size_t		lastDateSeparator = date.find_last_of('-');
	std::string	sYear = date.substr(0, firstDateSeparator);
	std::string	sMonth = date.substr(firstDateSeparator + 1, lastDateSeparator - (firstDateSeparator + 1));
	std::string	sDay = date.substr(lastDateSeparator + 1, date.size());
	std::cout << sYear << "|" << sMonth << "|" << sDay << std::endl;
	
	long int	iYear = std::atol(sYear.c_str());
	long int	iMonth = std::atol(sMonth.c_str());
	long int	iDay = std::atol(sDay.c_str());

	if (iYear > 2026 || iYear < 2009 || iMonth > 12 || iMonth < 1 || iDay > 31 || iDay < 1)
	{
		std::cout << "Skipped line [" << line << "] Cause of bad date values\n";
		return;
	}
		
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	DBG_MSG("BitcoinExchange copy constructor called");
	(void)obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	DBG_MSG("BitcoinExchange copy operator called");
	(void)obj;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	DBG_MSG("BitcoinExchange destructor called");
}