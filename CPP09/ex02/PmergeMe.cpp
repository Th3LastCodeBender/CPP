/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:10:43 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/13 18:37:57 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char *input[])
{
	DBG_MSG("PmergeMe constructor called");
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
	print_stl(this->_vector);
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

void	PmergeMe::vectorSorting()
{
	std::vector<int>	mainVec;
	vecIt				it;
	CoupVec				couples;
	std::vector<int>	pending;
	size_t				couples_size;

	mainVec = this->_vector;
	couples.resize(this->_vector.size() / 2);
	couples_size = couples.size();
	it = mainVec.begin();
	
	// couples splitting
	for (size_t i = 0; i < couples_size; i++)
	{
		couples[i].first = *(it++);
		couples[i].second = *(it++);
	}
	print_vec_couples(couples);
	
	//couples sorting
	for (size_t i = 0; i < couples_size; i++)
	{
		if (couples[i].first > couples[i].second)
			std::swap(couples[i].first, couples[i].second);
	}
	print_vec_couples(couples);
	
	// vectors refilling
	mainVec.clear();
	for (size_t i = 0; i < couples_size; i++)
		mainVec.push_back(couples[i].second);
	for (size_t i = 0; i < couples_size; i++)
		pending.push_back(couples[i].first);
	std::sort(mainVec.begin(), mainVec.end());
	print_stl(mainVec);
	print_stl(pending);

	//binary insertion
	size_t	main_size = mainVec.size();
	size_t	small_size = pending.size();
	size_t	left = 0;
	size_t	right = small_size;
	size_t	index = (left + right) / 2;
	
	while (small_size != 0)
	{
		if (pending[0] < mainVec[index])
		{
			right = index - 1;
			index = (left + right) / 2;
		}
		else
		{
			left = index + 1;
			index = (left + right) / 2;
		}				
	}
	
}


// 0 1 2 3 4 5 6 7
// 0 -> 0, 1
// 1 -> 2, 3
// 2 -> 4, 5
// 3 -> 6, 7