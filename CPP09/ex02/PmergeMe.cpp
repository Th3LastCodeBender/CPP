/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:10:43 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/15 16:54:50 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	jacob_series(int range);
void 				binary_insertion(std::vector<int> &mainVec, std::vector<int> &min_values, CoupVec &pairs, std::vector<int> order);
void				vectorAlgorithm(std::vector<int> &mainVec);
// void				create_pairs(std::vector<int> &vec, CoupVec &pairs, bool &has_straggler, int &straggler);
// void				extract_max_chain(CoupVec &pairs, std::vector<int> &max_chain);
// void				insert_min_before_max(std::vector<int> &vec, std::pair<int,int> &p);
// void				insert_straggler(std::vector<int> &vec, int straggler);

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
	clock_t start = clock();
	vectorAlgorithm(this->_vector);
	clock_t end = clock();
	print_stl(this->_vector, "After: ");
	print_time(start, end, "std::vector<int>");
}

// void vectorAlgorithm(std::vector<int> &vec)
// {
//     if (vec.size() <= 1) return;

//     CoupVec pairs;
//     bool has_straggler = false;
//     int straggler = 0;

//     create_pairs(vec, pairs, has_straggler, straggler);

//     std::vector<int> max_chain;
//     extract_max_chain(pairs, max_chain);

//     vectorAlgorithm(max_chain);

//     vec.clear();
//     for (size_t i = 0; i < max_chain.size(); i++)
//     {
//         vec.push_back(max_chain[i]);
//         insert_min_before_max(vec, pairs[i]);
//     }

//     if (has_straggler)
//         insert_straggler(vec, straggler);
// }

// void create_pairs(std::vector<int> &vec, CoupVec &pairs, bool &has_straggler, int &straggler)
// {
//     has_straggler = (vec.size() % 2 != 0);
//     straggler = 0;
//     if (has_straggler)
//     {
//         straggler = vec.back();
//         vec.pop_back();
//     }
//     for (size_t i = 0; i < vec.size(); i += 2)
//     {
//         int a = vec[i];
//         int b = vec[i+1];
//         if (a > b)
// 			std::swap(a,b);
//         pairs.push_back(std::make_pair(a,b));
//     }
// }

// void extract_max_chain(CoupVec &pairs, std::vector<int> &max_chain)
// {
//     max_chain.clear();
//     for (size_t i = 0; i < pairs.size(); i++)
//         max_chain.push_back(pairs[i].second);
// }

// void insert_min_before_max(std::vector<int> &vec, std::pair<int,int> &p)
// {
//     int min_val = p.first;
//     int max_val = p.second;

//     size_t max_pos = 0;
//     for (size_t i = 0; i < vec.size(); i++)
//     {
//         if (vec[i] == max_val)
//         {
//             max_pos = i;
//             break;
//         }
//     }
//     size_t left = 0, right = max_pos;
//     while (left < right)
//     {
//         size_t mid = left + (right - left)/2;
//         if (min_val < vec[mid]) right = mid;
//         else left = mid + 1;
//     }
//     vec.insert(vec.begin() + left, min_val);
// }

// void insert_straggler(std::vector<int> &vec, int straggler)
// {
//     size_t left = 0, right = vec.size();
//     while (left < right)
//     {
//         size_t mid = left + (right - left)/2;
//         if (straggler < vec[mid]) right = mid;
//         else left = mid + 1;
//     }
//     vec.insert(vec.begin() + left, straggler);
// }

// Funzione principale ricorsiva


void vectorAlgorithm(std::vector<int> &vec)
{
    if (vec.size() <= 1)
        return;

    bool has_straggler = (vec.size() % 2 != 0);
    int straggler = 0;
    if (has_straggler)
    {
        straggler = vec.back();
        vec.pop_back();
    }

    // Creazione coppie (min,max)
    CoupVec couples;
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        int a = vec[i];
        int b = vec[i+1];
        if (a > b) std::swap(a,b);
        couples.push_back(std::make_pair(a,b));
    }

    // Ricorsione sui max
    std::vector<int> max_chain;
    for (size_t i = 0; i < couples.size(); i++)
        max_chain.push_back(couples[i].second);
    vectorAlgorithm(max_chain);

    // Ricostruzione mainVec con min/max
    vec.clear();
    for (size_t i = 0; i < max_chain.size(); i++)
    {
        int max_val = max_chain[i];

        // Trovo la coppia corrispondente
        std::pair<int,int> *found_pair = NULL;
        for (size_t j = 0; j < couples.size(); j++)
        {
            if (couples[j].second == max_val)
            {
                found_pair = &couples[j];
                break;
            }
        }
        int min_val = found_pair->first;

        // Inserisco max
        vec.push_back(max_val);

        // Inserisco min prima del max con binary search
        size_t left = 0, right = vec.size() - 1;
        while (left < right)
        {
            size_t mid = left + (right - left)/2;
            if (min_val < vec[mid]) right = mid;
            else left = mid + 1;
        }
        vec.insert(vec.begin() + left, min_val);
    }

    // Inserisco straggler se presente
    if (has_straggler)
    {
        size_t left = 0, right = vec.size();
        while (left < right)
        {
            size_t mid = left + (right - left)/2;
            if (straggler < vec[mid]) right = mid;
            else left = mid + 1;
        }
        vec.insert(vec.begin() + left, straggler);
    }
}

void binary_insertion(std::vector<int> &mainVec, std::vector<int> &min_values, CoupVec &pairs, std::vector<int> order)
{
	for (size_t k = 0; k < order.size(); k++)
	{
		int index = order[k];
		int value = min_values[index];
		int max_value = pairs[index].second;

		// Trovo la posizione del max
		size_t max_pos = 0;
		for (size_t i = 0; i < mainVec.size(); i++)
		{
			if (mainVec[i] == max_value)
			{
				max_pos = i;
				break;
			}
		}

		// Binary search limitata a [0, max_pos] per inserire il min
		size_t left = 0;
		size_t right = max_pos;
		while (left < right)
		{
			size_t mid = left + (right - left) / 2;
			if (value < mainVec[mid])
				right = mid;
			else
				left = mid + 1;
		}

		mainVec.insert(mainVec.begin() + left, value);
	}
}
