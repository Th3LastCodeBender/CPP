/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:18:53 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/01 11:24:57 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string startingName, Weapon &startingWeapon) : weapon(startingWeapon)
{
	this->name = startingName;
	std::cout << "HumanA constructor called" << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA deconstructor called" << std::endl;
}