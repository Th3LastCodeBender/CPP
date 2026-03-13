/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:10:37 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/13 17:24:49 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define 	PMERGEME_HPP

#include "eader.h"

typedef std::vector<std::pair<int, int> > CoupVec;
typedef std::vector<int>::iterator vecIt;

class PmergeMe
{
	private:
	
		std::vector<int>	_vector;
		std::deque<int>		_deque; 

	public:

		PmergeMe(int argc, char *input[]);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void	vectorSorting();
	
	class ConversionFail : public std::exception
	{
		private:
			std::string _msg;
		public:
			ConversionFail(std::string msg) : _msg(msg) {};
			virtual const char *what() const throw() {return (this->_msg.c_str());};
			~ConversionFail() throw() {};
	};
};


#endif
