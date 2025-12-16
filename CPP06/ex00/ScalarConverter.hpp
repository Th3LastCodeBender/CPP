/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:56:40 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/16 14:19:43 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define 	SCALARCONVERTER_HPP

#include "eader.h"

class ScalarConverter {
	
	private:
	
	    ScalarConverter();
	    ScalarConverter(const ScalarConverter &);
	    ScalarConverter &operator=(const ScalarConverter &);
	    ~ScalarConverter();
		
	public:
	
	    static void convert(const std::string &literal);

		class SpecialCaseException : public std::exception
		{
			public:
				SpecialCaseException(){};
				virtual const char *what() const throw() { return NULL; }
				~SpecialCaseException() throw() {};
		};

		class FormatParsingException : public std::exception
		{
			private:
				std::string _msg;
			public:
				FormatParsingException(std::string msg) : _msg(msg) {};
				virtual const char *what() const throw() {return (_msg.c_str());}
				~FormatParsingException() throw() {};
		};
		class ExecutionException : public std::exception
		{
			private:
				std::string _msg;
			public:
				ExecutionException(std::string msg) : _msg(msg) {};
				virtual const char *what() const throw() {return (_msg.c_str());}
				~ExecutionException() throw() {};
		};
}; 

#endif