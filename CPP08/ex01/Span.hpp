/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:30:36 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/27 16:17:06 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define 	SPAN_HPP

#include "eader.h"

class Span
{
	private:

		std::vector<int>	_span;
		unsigned int		_max_size;

	public:

		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void			addNumber(int numToAdd);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		class SpanException : public std::exception
		{
			private:
				std::string _msg;
			public:
				SpanException(std::string msg): _msg(msg) {};
				virtual const char *what() const throw() {return (_msg.c_str());}
				~SpanException() throw() {};
		};
};

#endif
