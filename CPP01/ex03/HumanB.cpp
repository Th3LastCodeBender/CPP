/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:18:57 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/01 11:20:06 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string startingName)
{
	this->name = startingName;
	std::cout << "HumanB constructor called" << std::endl;
}

void	HumanB::setWeapon( Weapon &weaponToSet )
{
	this->weapon = &weaponToSet;
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB deconstructor called" << std::endl;
}