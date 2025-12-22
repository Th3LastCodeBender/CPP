/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:30:52 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/22 18:30:58 by lparolis         ###   ########.fr       */
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
	if (this->_span.size() < this->_max_size)
	{
		this->_span.push_back(num);
		std::cout << "Number succesfully added to span memory" << std::endl;
	}
	else
		throw CapacityExceededException("The limit capacity of span memory was reached!\n");
}

