/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:32:30 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/02 17:51:58 by lparolis         ###   ########.fr       */
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
	
	this->function[0] = "debug";
	this->function[1] = "info";
	this->function[2] = "warning";
	this->function[3] = "error";
	
	std::cout << "Harl Constructor called" << std::endl;
}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle- specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	int i;
	
	i = 0;
	while (i < 4)
	{
		if (level.compare(this->function[i]) == 0)
			(this->*complaints[i])();
		i++;
	}	
}

Harl::~Harl()
{
	std::cout << "Harl Deconstructor called" << std::endl;
}