/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:30:52 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/18 17:16:56 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	operation(int first, int second, char op, int &result);

RPN::RPN()
{
	DBG_MSG("RPN constructor called");
	this->_result = 0;
}

RPN::RPN(const RPN &obj)
{
	DBG_MSG("RPN copy constructor called");
	this->_expression = obj._expression;
	this->_result = obj._result;
}

RPN &RPN::operator=(const RPN &obj)
{
	DBG_MSG("RPN copy operator called");
	if (&obj == this)
		return(*this);
	this->_expression = obj._expression;
	this->_result = obj._result;
	return (*this);
}

RPN::~RPN()
{
	DBG_MSG("RPN destructor called");
}

int	RPN::getResult() {return (this->_result);}

bool	RPN::inputProcess(const char *raw_input)
{
	std::string input(raw_input);

	if (inputParsing(input) == false)
		return false;
	return executeOps(input);
}

bool	RPN::executeOps(std::string input)
{
	std::stack<int> stack;
	int				digit;
	int				first;
	int				second;
	int				result;
	char			op;

	size_t size = input.length();
	for (size_t i = 0; i < size; i++)
	{
		if (std::isdigit(input[i]) != 0)
		{
			digit = input[i] - 48;
			stack.push(digit);
		}
		if (is_valid_operator(input[i]) == true)
		{
			op = input[i];
			if (stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return (false);
			}
			second = stack.top();
			stack.pop();
			first = stack.top();
			stack.pop();
			if(operation(first, second, op, result) == false)
				return (false);
			stack.push(result);
		}		
	}
	this->_result = stack.top();
	return (true);
}

bool	operation(int first, int second, char op, int &result)
{
	if (op == '/' && second == 0)
	{
		DBG_MSG("Division by zero is invalid!");
		std::cerr << "Error" << std::endl;
		return (false);
	}
	switch (op)
	{
	case '+':
		result = first + second;
		break;
		
	case '-':
		result = first - second;
		break;
		
	case '*':
		result = first * second;
		break;
		
	case '/':
		result = first / second;
		break;
		
	
	default:
		DBG_MSG("Invalid operator");
		std::cerr << "Error" << std::endl;
		return (false);
	}
	return (true);
}

bool	RPN::inputParsing(std::string &input)
{
	std::istringstream iss(input);
	std::string token;
	int stack_size = 0;

	while (iss >> token)
	{
		if (token.size() != 1)
		{
			std::cerr << "Error" << std::endl;
			return (false);
		}
		char c = token[0];
		if (std::isdigit(c) != 0)
			stack_size++;
		else if (is_valid_operator(c) == true)
		{
			if (stack_size < 2)
			{
				std::cerr << "Error" << std::endl;
				return (false);
			}
			stack_size--;
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return (false);
		}
	}
	if (stack_size != 1)
	{
		std::cerr << "Error" << std::endl;
		return (false);
	}
	return (true);
}
