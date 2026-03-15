/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:04:39 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/15 16:14:27 by lparolis         ###   ########.fr       */
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

