/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:10:42 by lparolis          #+#    #+#             */
/*   Updated: 2026/02/26 22:00:05 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "utils.hpp"

int line = 1;

BitcoinExchange::BitcoinExchange()
{
	DBG_MSG("BitcoinExchange constructor called");
	
	std::ifstream	table("data.csv");
	std::string		buffer;

	if (table.fail())
		throw ParsingException("Error: could not open file.");
	line = 1;
	while (std::getline(table, buffer))
	{
		inputParsing(buffer, "exchangeTable", ',');
		++line;		
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

void	 BitcoinExchange::splitDateFromBtc(std::string &buffer, char separator)
{
	size_t sepPos = buffer.find(separator);
	if (separator == '|')
		this->date = buffer.substr(0, sepPos - 1);
	else
		this->date = buffer.substr(0, sepPos);	
	if (sepPos + 1 != buffer.size() && separator == '|')
		this->value = buffer.substr(sepPos + 2, buffer.size() - (sepPos + 2));
	else if (sepPos != buffer.size() && separator == ',')
		this->value = buffer.substr(sepPos + 1, buffer.size());
}

void	BitcoinExchange::dateParser(std::string &date)
{
	size_t		firstDateSeparator = date.find('-');
	size_t		lastDateSeparator = date.find_last_of('-');
	std::string	sYear = date.substr(0, firstDateSeparator);
	std::string	sMonth = date.substr(firstDateSeparator + 1, lastDateSeparator - (firstDateSeparator + 1));
	std::string	sDay = date.substr(lastDateSeparator + 1, date.size());

	this->iYear = std::atol(sYear.c_str());
	this->iMonth = std::atol(sMonth.c_str());
	this->iDay = std::atol(sDay.c_str());
}

void	BitcoinExchange::inputParsing(std::string &buffer, std::string dest, char separator)
{
	if (buffer.compare("date,exchange_rate") == 0 || buffer.compare("date | value") == 0)
		return;
	if(buffer.empty() || buffer.find(separator) == std::string::npos)
	{
		std::cout << "Error: bad input => " << buffer << std::endl;
		return;
	}
	splitDateFromBtc(buffer, separator);
	if ((this->date.find('-') == std::string::npos || this->date.find_first_of('-') == this->date.find_last_of('-')) && buffer != "date | value")
	{
		std::cout << "Error: bad input => " << this->date << std::endl;
		return;
	}
	dateParser(this->date);
	// std::cout << sYear << "|" << sMonth << "|" << sDay << std::endl;
	if (dateChecker(this->iYear, this->iMonth, this->iDay) == false)
		return;
	if (checkValueChars(this->value) == false || checkValueLimits(value, separator) == false)
		return;
	if (separator == '|')
	{
		this->input[this->date] = convertValue(this->value);
		displayAmount(this->date);
	}
	else if (separator == ',')
		this->exchangeTable[this->date] = convertValue(this->value);
	if (DEBUG)
		std::cout << "Added line " << line << " in " << dest << " map" << std::endl;
}

void	BitcoinExchange::displayAmount(std::string date)
{
	std::map<std::string, float>::iterator index;
	std::map<std::string, float>::iterator input;
	
	index = this->exchangeTable.find(date);
	input = this->input.find(date);
	if (index == this->exchangeTable.end())
		index = this->exchangeTable.lower_bound(date);
	if (index == this->exchangeTable.end())
	{
		--index;
		std::cout << index->first << " => " << input->second << " = " << index->second * input->second << std::endl;
		return ;
	}
	else if (index->first == date)
	{
		std::cout << index->first << " => " << input->second << " = " << index->second * input->second << std::endl;
		return ;
	}
	else if (index == this->exchangeTable.begin())
        throw ParsingException("No earlier date available for exchange rate");
	std::cout << input->first << " => " << input->second << " = " << index->second * input->second << std::endl;
}

void	BitcoinExchange::inputProcess(std::string inputPath)
{
	try
	{
		std::ifstream	input(inputPath.c_str());
		std::string		buffer;
		
		if (input.fail())
			throw ParsingException("Error: could not open file.");
		line = 1;
		while (std::getline(input, buffer))
		{
			inputParsing(buffer, "input", '|');
			++line;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

// $> ./btc
// Error: could not open file.
// $> ./btc input.txt
// 2011-01-03 => 3 = 0.9
// 2011-01-03 => 2 = 0.6
// 2011-01-03 => 1 = 0.3
// 2011-01-03 => 1.2 = 0.36
// 2011-01-09 => 1 = 0.32
// Error: not a positive number.
// Error: bad input => 2001-42-42
// 2012-01-11 => 1 = 7.1
// Error: too large a number.
// $>