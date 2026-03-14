/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:10:43 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/14 21:58:40 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	jacob_series(int range);
void	binary_insertion(std::vector<int> &mainVec, std::vector<int> &pending, std::vector<int> order);

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
	print_stl(this->_vector, "Before: ");
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
void	PmergeMe::vectorSorting()
{
	std::vector<int>	mainVec;
	vecIt				it;
	CoupVec				couples;
	std::vector<int>	pending;
	size_t				couples_size;
	bool				has_straggler = false;
	int					straggler = 0;

	mainVec = this->_vector;

	if (mainVec.size() % 2 != 0)
	{
		has_straggler = true;
		straggler = mainVec.back();
		mainVec.pop_back();
	}

	couples.resize(mainVec.size() / 2);
	couples_size = couples.size();
	it = mainVec.begin();
	
	// couples splitting
	for (size_t i = 0; i < couples_size; i++)
	{
		couples[i].first = *(it++);
		couples[i].second = *(it++);
	}

	// couples sorting
	for (size_t i = 0; i < couples_size; i++)
	{
		if (couples[i].first > couples[i].second)
			std::swap(couples[i].first, couples[i].second);
	}

	// vectors refilling
	mainVec.clear();
	for (size_t i = 0; i < couples_size; i++)
		mainVec.push_back(couples[i].second);
	for (size_t i = 0; i < couples_size; i++)
		pending.push_back(couples[i].first);
	if (has_straggler)
		pending.push_back(straggler);

	std::sort(mainVec.begin(), mainVec.end());
	print_stl(mainVec, "MainVec after split: ");
	print_stl(pending, "Pending after split: ");
	binary_insertion(mainVec, pending, jacob_blocks(pending.size()));
	print_stl(mainVec, "After: ");
}

void	binary_insertion(std::vector<int> &mainVec, std::vector<int> &pending, std::vector<int> order)
{
	std::vector<int>::iterator it = order.begin();
	std::vector<int>::iterator end = order.end();
	while (it != end)
	{
		size_t	left = 0;
		size_t	right = mainVec.size() - 1;
		int		value = pending[*it++];

		while (left <= right)
		{
			size_t mid = left + (right - left) / 2;

			if (value < mainVec[mid])
			{
				if (mid == 0)
					break;
				right = mid - 1;
			}
			else
				left = mid + 1;
		}
		std::vector<int>::iterator pos = mainVec.begin() + left;
		mainVec.insert(pos, value);
	}	
}

// 1 3 2 5 4 6

// 10 1 9 2 8 3 7 4 6 5

// 10 1 -> 1 10
// 9 2  -> 2  9
// 8 3  -> 3  8
// 7 4  -> 4  7
// 6 5  -> 5  6

// 1 2 3 4 5
// 10 9 8 7 6