/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:00:47 by lparolis          #+#    #+#             */
/*   Updated: 2026/01/14 14:06:40 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define 	BITCOINEXCHANGE_HPP

#include "eader.h"

class BitcoinExchange
{
	private:

		std::map<std::string, float> exchangeTable;
		std::map<std::string, float> input;

		void	lineParsing(std::string buffer);
		void	inputParsing(std::string buffer);

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
