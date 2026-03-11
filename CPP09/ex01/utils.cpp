/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:31:28 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/11 16:36:43 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"

size_t	count_operators(std::string input)
{
	size_t input_size = input.size();
	size_t operators = 0;
	
	for (size_t i = 0; i < input_size; i++)
	{
		if (is_valid_operator(input[i]) != 0)
			operators++;
	}
	return (operators);
}

size_t	count_digits(std::string input)
{
	size_t input_size = input.size();
	size_t digits = 0;
	
	for (size_t i = 0; i < input_size; i++)
	{
		if (std::isdigit(input[i]) != 0)
			digits++;
	}
	return (digits);
}

bool	is_valid_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	else
		return (false);
}

bool	is_valid_char(char c)
{
	if (std::isdigit(c) != 0 || is_valid_operator(c) || c == ' ')
		return (true);
	else
		return (false);
}

bool	are_chars_valid(std::string input)
{
	size_t size = input.length();
	
	for (size_t i = 0; i < size; i++)
	{
		if (is_valid_char(input[i]) == false)
		{
			DBG_MSG("Invalid chars in input");
			std::cerr << "Error" << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	check_order(std::string input)
{
	size_t operators;
	size_t digits;
	size_t size;
	
	size = input.length();
	operators = 0;
	digits = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (is_valid_operator(input[i]) == true)
			operators++;
		if (std::isdigit(input[i]) == true)
			digits++;
		if (digits <= operators)
		{
			DBG_MSG("Wrong operators and digits order");
			std::cerr << "Error" << std::endl;
			return (false);
		}
	}
	if (operators == 0 || digits == 0)
	{
		DBG_MSG("No operators or digits");
		std::cerr << "Error" << std::endl;
		return (false);
	}
	return (true);
}