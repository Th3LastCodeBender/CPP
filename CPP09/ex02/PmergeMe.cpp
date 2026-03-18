/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:10:43 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/18 17:22:58 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char *input[])
{
	DBG_MSG("PmergeMe constructor called");
	this->_elements = argc - 1;
	for (int i = 1; i < argc; i++)
	{
		long	result;
		if (convert_to_long(input[i], result, argc) == true)
		{
			this->_vector.push_back(result);
			this->_deque.push_back(result);
		}
		else
			throw ConversionFail("PmergeMe.cpp:27: Conversion Error: Number conversion aborted!");
	}
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	DBG_MSG("PmergeMe copy constructor called");
	this->_vector = obj._vector;
	this->_deque = obj._deque;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	DBG_MSG("PmergeMe copy operator called");
	if (this != &obj)
	{
		this->_vector = obj._vector;
		this->_deque = obj._deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	DBG_MSG("PmergeMe destructor called");
}

/**
 * @brief This class function calls the recursive sorting function
 * 
 */
void	PmergeMe::Sorting()
{
	print_stl(this->_vector, "Before: ");
	timespec start;
	timespec end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	vectorAlgorithm(this->_vector);
	clock_gettime(CLOCK_MONOTONIC, &end);
	print_stl(this->_vector, "After: ");
	print_time(start, end, "std::vector<int>", this->_elements);

	clock_gettime(CLOCK_MONOTONIC, &start);
	dequeAlgorithm(this->_deque);
	clock_gettime(CLOCK_MONOTONIC, &end);
	print_time(start, end, "std::deque<int>", this->_elements);
}
