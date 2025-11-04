/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:32:30 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 13:50:13 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "eader.h"

Harl::Harl()
{
	this->complaints[0] = &Harl::debug;
	this->complaints[1] = &Harl::info;
	this->complaints[2] = &Harl::warning;
	this->complaints[3] = &Harl::error;
	
	this->function[0] = "DEBUG";
	this->function[1] = "INFO";
	this->function[2] = "WARNING";
	this->function[3] = "ERROR";
	
	std::cout << "Harl Constructor called" << std::endl;
}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle- specialketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void	Harl::complain( std::string level )
{
	int index;
	
	index = 0;
	while (index < 4 && level.compare(this->function[index]) != 0)
		index++;
	switch (index)
	{
	case DEBUG:
		this->debug();
	case INFO:
		this->info();
	case WARNING:
		this->warning();
	case ERROR:
		this->error();
		break;
	
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}

Harl::~Harl()
{
	std::cout << "Harl destructor called" << std::endl;
}