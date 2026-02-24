/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:00:47 by lparolis          #+#    #+#             */
/*   Updated: 2026/02/24 22:14:36 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define 	BITCOINEXCHANGE_HPP

#include "eader.h"
#include "utils.hpp"

class BitcoinExchange
{
	private:

		std::map<std::string, float>	exchangeTable;
		std::map<std::string, float>	input;
		std::string						date;
		std::string						value;
		long int						iYear;
		long int						iMonth;
		long int						iDay;

		void	inputParsing(std::string &buffer, std::string dest, char separator);
		void	splitDateFromBtc(std::string &buffer, char separator);
		void	dateParser(std::string &date);
		void	displayAmount(std::string date);

	public:

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void	inputProcess(std::string inputPath);
		
		class ParsingException : public std::exception
		{
			private:
				std::string _msg;
			public:
				ParsingException(std::string msg) : _msg(msg) {};
				virtual const char *what() const throw() {return (_msg.c_str());}
				~ParsingException() throw() {};
		};
};


#endif
