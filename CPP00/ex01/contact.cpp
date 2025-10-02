/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:55:14 by lparolis          #+#    #+#             */
/*   Updated: 2025/09/10 15:04:50 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void	indenter(std::string to_indent);

Contact::Contact()
{
	std::cout << "Contact Constructor called" << std::endl;	
	return ;
}

Contact::~Contact()
{
	std::cout << "Contact Destructor called" << std::endl;
	return ;
}

void	Contact::add_contact(int index)
{
	std::string input;
	
	this->index = index + 1;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Please input the first name of the new contact" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Invisible characters don't exist you know...\nTry again you peasant" << std::endl;
		std::cout << std::endl;
		getline(std::cin, input);
	}
	this->first_name = input;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Please input the last name of the new contact" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "--------------------------------------------------------------" << std::endl;
		std::cout << "You really like to play games do you...\nTry again you peasant" << std::endl;
		std::cout << "--------------------------------------------------------------" << std::endl;
		getline(std::cin, input);
	}
	this->last_name = input;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Please input the nickname of the new contact" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "-----------------------------------------------------" << std::endl;
		std::cout << "Dumber than a sack of trash...\nTry again you peasant" << std::endl;
		std::cout << "-----------------------------------------------------" << std::endl;
		getline(std::cin, input);
	}
	this->nick_name = input;
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << "Please input the phone number of the new contact" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "-----------------------------------------------------------------" << std::endl;
		std::cout << "Do you have nuts instead of braincells?...\nTry again you peasant" << std::endl;
		std::cout << "-----------------------------------------------------------------" << std::endl;
		getline(std::cin, input);
	}
	this->phone_number = input;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Please input the darkest secret of the new contact" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "You are so trivial...\nStop trying please" << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		getline(std::cin, input);
	}
	this->darkest_secret = input;
}

void	Contact::print_contact() const
{
	std::cout << "         " << this->index << " | " ;
	indenter(this->first_name);
	indenter(this->last_name);
	indenter(this->nick_name);
	std::cout << std::endl;
}

void	Contact::print_full_contact() const
{
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "index: " << this->index << std::endl;
	std::cout << "first_name: " << this->first_name << std::endl;
	std::cout << "last_name: " << this->last_name << std::endl;
	std::cout << "nick_name " << this->nick_name << std::endl;
	std::cout << "phone_number: " << this->phone_number << std::endl;
	std::cout << "darkest_secret: " << this->darkest_secret << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
}

void	indenter(std::string to_indent)
{
	int to_print;

	to_print = 10 - to_indent.substr(0, 10).length();
	while (to_print > 0)
	{
		std::cout << " ";
		to_print--;
	}
	std::cout << to_indent.substr(0, 9);
	if (to_indent.substr(0, 10).length() >= 10)
	{
		std::cout << ".";
	}
	std::cout  << " | ";
}
