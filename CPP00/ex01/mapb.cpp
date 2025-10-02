/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapb.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:44:45 by lparolis          #+#    #+#             */
/*   Updated: 2025/09/10 16:40:25 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fonbook.h"
#include "phonebook.hpp"
#include "contact.hpp"

void	print_contact(Contact *phonebook);

int	main()
{
	PhoneBook giorgino;
	std::string input;
	
	std::cout << "------------------" << std::endl;
	std::cout << "Input your command" << std::endl;
	std::cout << "------------------" << std::endl;
	getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "------------------------------------" << std::endl;
		std::cout << "See you and thanks for all the fish!" << std::endl;
		std::cout << "------------------------------------" << std::endl;
	}
	while (input.compare("EXIT") != 0)
	{
		if (input.compare("ADD") == 0)
		{
			giorgino.add_command();
		}
		else if (input.compare("SEARCH") == 0)
		{
			giorgino.search_command();
		}
		else
		{
			std::cout << std::endl;
			std::cout << "Oh god.... you like like those kind of people who would mistake pyrite for gold" << std::endl;
			std::cout << "Come on, go outside and buy a pickaxe and start working in the mines" << std::endl;
			std::cout << std::endl;
		}
		std::cout << "------------------" << std::endl;
		std::cout << "Input your command" << std::endl;
		std::cout << "------------------" << std::endl;
		getline(std::cin, input);
	}
	return (0);
}

void	print_contact(Contact *phonebook)
{
	int 		index;
	std::string input;

	std::cout << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "Please insert the contact index you want to see the infos of" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	
	getline(std::cin, input);
	index = 0;
	index = std::atoi(input.c_str());
	while (!input.empty())
	{
		if (index != 0 && index < 9)
		{
			phonebook[index - 1].print_full_contact();
			return;
		}
		std::cout << std::endl;
		std::cout << "-----------------------------ERROR--------------------------" << std::endl;
		std::cout << "So funny dude... ever considered doing stand up comedy?" << std::endl;
		std::cout << "-----------------------------ERROR--------------------------" << std::endl;
		std::cout << std::endl;
		getline(std::cin, input);
		index = std::atoi(input.c_str());
	}
}