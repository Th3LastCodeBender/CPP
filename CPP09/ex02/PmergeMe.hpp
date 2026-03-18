/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:10:37 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/15 18:27:12 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define 	PMERGEME_HPP

#include "eader.h"

class PmergeMe
{
	private:
	
		size_t				_elements;
		std::vector<int>	_vector;
		std::deque<int>		_deque; 

	public:

		PmergeMe(int argc, char *input[]);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void	Sorting();
	
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
