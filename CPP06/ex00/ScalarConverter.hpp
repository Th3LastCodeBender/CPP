/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:56:40 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/20 15:48:58 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define 	SCALARCONVERTER_HPP

#include "eader.h"

// riguardarsi le conseguenze di aver messo il costruttore nel private, significa 
// che a differenza di una classe astratta perchè ha solo un metodo = 0 (che significa 
// che non può mai essere istanziata punto) questa classe può essere 
// instanziata all'interno dei prorpi metodi ma non all'esterno.

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