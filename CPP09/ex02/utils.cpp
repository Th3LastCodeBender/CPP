/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:04:39 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/12 20:14:42 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"

bool	valid_chars(char *string)
{
	size_t length;
	
	length = sizeof(string) / sizeof(string[0]);
	for (size_t i = 0; i < length; i++)
	{
		if (std::isdigit(string[i]) != 0)
		{
			std::cerr << "Arguments Error: A non numerica character was found!" << std::endl;
			return (false);
		}
	}
	return (true);
}