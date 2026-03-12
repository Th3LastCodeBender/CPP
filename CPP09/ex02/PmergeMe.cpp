/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:10:43 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/12 19:12:49 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	DBG_MSG("PmergeMe constructor called");
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	DBG_MSG("PmergeMe copy constructor called");
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	DBG_MSG("PmergeMe copy operator called");
	return (*this);
}

PmergeMe::~PmergeMe()
{
	DBG_MSG("PmergeMe destructor called");
}