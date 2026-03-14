/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:04:39 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/14 18:55:31 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"

bool	valid_chars(char *string)
{
	size_t length;
	
	length = std::strlen(string);
	for (size_t i = 0; i < length; i++)
	{
		if (std::isdigit(string[i]) == 0)
		{
			std::cerr << "Arguments Error: A non numerical character was found!" << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	convert_to_long(char *str, long &result, int line)
{
    char *endptr;
    errno = 0;

    long value = std::strtol(str, &endptr, 10);

    if (endptr == str)
    {
        DBG_ERR("Conversion Error: At line: " << line << " no digits were found!");
        return (false);
    }
    if (*endptr != '\0')
    {
        DBG_ERR("Conversion Error: At line: " << line << " invalid characters in number!");
        return (false);
    }
    if (errno == ERANGE)
    {
        DBG_ERR("Conversion Error: At line: " << line << " number out of range!");
        return (false);
    }
	if (value > INT_MAX || value < INT_MIN)
	{
		DBG_ERR("Conversion Error: At line: " << line << " number out of integer max/min range!");
		return (false);
	}
    result = value;
    return (true);
}

void	print_vec_couples(std::vector<std::pair<int, int> > couples)
{
	size_t couples_size = couples.size();
	
	std::cout << "------------------------\n";
	std::cout << "couples:\n";
	for (size_t i = 0; i < couples_size; i++)
	{
		std::cout << "|" << couples[i].first;
		std::cout << " , " << couples[i].second << '|' << std::endl;
	}
	std::cout << "------------------------\n";
}
void	print_stl(std::vector<int> vect){print_stl(vect, "");}

void	print_stl(std::deque<int> deque){print_stl(deque, "");}

void	print_stl(std::vector<int> vect, std::string msg)
{
	std::cout << msg;
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

void	print_stl(std::deque<int> deque, std::string msg)
{
	std::cout << msg;
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

std::vector<int>	decrease(std::vector<int> vect)
{
	size_t size = vect.size();
	for (size_t i = 0; i < size; i++)
		vect[i]--;
	return(vect);
}