/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:30:52 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/27 17:58:42 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"
#include "Span.hpp"

Span::Span(unsigned int n)
{
	DBG_MSG("Span constructor called");
	this->_max_size = n;
}

Span::Span(const Span &obj)
{
	DBG_MSG("Span copy constructor called");
	
	this->_max_size = obj._max_size;
	
	this->_span = obj._span;
}

Span &Span::operator=(const Span &obj)
{
	DBG_MSG("Span copy operator called");
	if (this != &obj)
	{
		this->_max_size = obj._max_size;
		this->_span = obj._span;
	}
	return (*this);
}

Span::~Span()
{
	DBG_MSG("Span destructor called");
}

void	Span::addNumber(int num)
{
	try
	{
		if (this->_span.size() < this->_max_size)
		{
			this->_span.push_back(num);
			std::cout << "Number " << num << " succesfully added to span memory" << std::endl;
		}
		else
			throw SpanException("The limit capacity of span memory was reached!\n");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

unsigned int	Span::longestSpan()
{	
	if (this->_span.size() < 2)
		throw SpanException("LongestSpan: not enough numbers in the container");

	std::vector<int>::iterator min;
	std::vector<int>::iterator max;
	
	min = std::min_element(this->_span.begin(), this->_span.end());
	max = std::max_element(this->_span.begin(), this->_span.end());
	
	if (INFO)
	{
		std::cout << "span found at:\n";
		std::cout << "min value: " << *min << "\n";
		std::cout << "max value: " << *max << "\n";
	}
	return static_cast<unsigned int>(std::abs(*max - *min));
}

unsigned int	Span::shortestSpan()
{	
	if (this->_span.size() < 2)
		throw SpanException("ShortestSpan: not enough numbers in the container");

	std::vector<int> copy = this->_span;
	std::sort(copy.begin(), copy.end());
	
	std::vector<int>::iterator it = copy.begin();
	std::vector<int>::iterator next = it;
	++next;
	unsigned int interval = static_cast<unsigned int>(std::abs(*next - *it));

	for (; next != copy.end(); ++it, ++next)
	{
		unsigned int diff = static_cast<unsigned int>(std::abs(*next - *it));
		if (diff < interval)
		{
			interval = diff;
		}
		
	}

	return (interval);
}