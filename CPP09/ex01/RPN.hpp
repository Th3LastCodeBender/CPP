/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:10:46 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/11 17:16:04 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define 	RPN_HPP

#include "eader.h"

class RPN
{
	private:

		std::stack<int> _stack;
		std::string 	_expression;
		int				_result;
	
	public:

		RPN();
		RPN(const RPN &obj);
		RPN& operator=(const RPN &obj);
		~RPN();

		bool	inputProcess(const char *raw_input);
		bool	inputParsing(std::string &input);
		bool	executeOps(std::string input);
		int		getResult();
};

#endif
