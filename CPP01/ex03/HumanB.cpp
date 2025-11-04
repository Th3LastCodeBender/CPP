/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:18:57 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 13:50:13 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string startingName)
{
	this->name = startingName;
	this->weapon = NULL;
	std::cout << "HumanB constructor called" << std::endl;
}

void	HumanB::setWeapon( Weapon &weaponToSet )
{
	this->weapon = &weaponToSet;
}

void	HumanB::attack()
{
	if (this->weapon == NULL || this->weapon->getType().empty())
	{
		std::cout << "e con cosa attaco io, con i tarzanelli?" << std::endl;
	}
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destructor called" << std::endl;
}