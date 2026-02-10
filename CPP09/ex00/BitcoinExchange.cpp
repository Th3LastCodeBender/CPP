/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:10:42 by lparolis          #+#    #+#             */
/*   Updated: 2026/02/10 19:06:08 by lparolis         ###   ########.fr       */
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
		throw ParsingException("Failed to open the .csv file!");
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
	this->date = buffer.substr(0, sepPos );
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
		std::cout << "Skipped " << dest << " line [" << line << "] Cause of bad data format\n";
		return;
	}
	splitDateFromBtc(buffer, separator);
	if ((this->date.find('-') == std::string::npos || 
		this->date.find_first_of('-') == this->date.find_last_of('-')) && 
		buffer != "date | value")
	{
		std::cout << "Skipped  " << dest << " line [" << line << "] Cause of bad date format\n";
		return;
	}
	dateParser(this->date);
	// std::cout << sYear << "|" << sMonth << "|" << sDay << std::endl;
	if (dateChecker(line, this->iYear, this->iMonth, this->iDay) == false)
		return;
	if (checkValueChars(line, this->value) == false || checkValueLimits(line, value, separator) == false)
		return;
	if (separator == '|')
		this->input[this->date] = convertValue(this->value);
	else if (separator == ',')
		this->exchangeTable[this->date] = convertValue(this->value);
	if (DEBUG)
		std::cout << "Added line " << line << " in " << dest << " map" << std::endl;
}

float	BitcoinExchange::displayAmount()
{
    std::map<std::string, float>::const_iterator it;

    it = this->exchangeTable.lower_bound(this->input.);

    if (it == this->exchangeTable.end())
    {
        --it;
        return it->second;
    }

    if (it->first == date)
        return it->second;

    if (it == this->exchangeTable.begin())
        throw ParsingException("No earlier date available for exchange rate");

    --it;
    return it->second;
}

void	BitcoinExchange::inputProcess(std::string inputPath)
{
	std::ifstream	input(inputPath.c_str());
	std::string		buffer;

	if (input.fail())
		throw ParsingException("Failed to open the .txt input file!");
	line = 1;
	while (std::getline(input, buffer))
	{
		inputParsing(buffer, "input", '|');
		++line;
	}
	std::map<std::string, float>::const_iterator it = this->input.begin();
	std::cout << "VALORE: " << displayAmount() << std::endl;
	while (it != this->input.end())
	{
		// displayAmount();
		++it;
	}
}
