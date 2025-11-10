/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:54:40 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/10 15:33:07 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"


PhoneBook::PhoneBook( void )
{
	std::cout << "PhoneBook Constructor called" << std::endl;
	this->index = 0;
	this->added = 0;
	this->to_print = 0;
	return;	
}

int PhoneBook::index = 0;
int PhoneBook::added = 0;

PhoneBook::~PhoneBook( void )
{
	std::cout << "PhoneBook destructor called" << std::endl;
	return;	
}
void	PhoneBook::printanding(Contact phonebook[8])
{
	std::cout << "---------------------------------------------------" << std::endl;	
	std::cout << "INDEX      | FIRST_NAME | LAST NAME  | NICKNAME   |" << std::endl; 
	
	for (int i = 0; i < PhoneBook::to_print ; i++)
	{
		phonebook[i].print_contact();
	}
}

void	PhoneBook::add_command()
{
	this->phonebook[this->index].add_contact(this->index);
	this->index++;
	this->added++;
	this->to_print++;
	if (this->to_print > 8)
		this->to_print = 8;
	if (this->index > 7)
		this->index = 0;
}

void	PhoneBook::search_command()
{
	if (this->added < 1)
	{
		std::cout << "-----------------------------ERROR---------------------------------------------------------------------" << std::endl;
		std::cout << "You joker — now do one thing: find a bridge, lean out far to take a photo and accidentally fall." << std::endl;
		std::cout << "-----------------------------ERROR---------------------------------------------------------------------" << std::endl;
		return;
	}
	this->printanding(this->phonebook);
	this->print_contact();
}

void	PhoneBook::print_contact()
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
		if (index != 0 && index < 9 && index <= this->added)
		{
			this->phonebook[index - 1].print_full_contact();
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