/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:56:29 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/22 15:58:25 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"
#include "template.hpp"

void	tryEasyFind(std::vector<int> &vector, int value)
{
	try
	{
		easyFind(vector, value);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(void)
{
	std::vector<int> gionny;

	gionny.push_back(12);
	gionny.push_back(71);
	gionny.push_back(3);
	gionny.push_back(7);

	tryEasyFind(gionny, 12);
	tryEasyFind(gionny, 7);
	tryEasyFind(gionny, 71);
	tryEasyFind(gionny, 13);
	
	return(0);
}
