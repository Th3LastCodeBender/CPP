/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:10:46 by lparolis          #+#    #+#             */
/*   Updated: 2026/03/15 15:35:45 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"
#include "PmergeMe.hpp"

int main(int argc, char	*argv[])
{
	if (mainParsing(argc, argv) == false)
		return (0);
	try
	{
		PmergeMe container(argc, argv);
		container.Sorting();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
