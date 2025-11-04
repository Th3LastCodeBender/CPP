/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:02:20 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 13:50:13 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	DBG_MSG("ScavTrap constructor called");
}

ScavTrap::~ScavTrap()
{
	DBG_MSG("ScavTrap destructor called");
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->hit_points == 0)
	{
		std::cout << "ScavTrap " << this->name;
		MSG(" cannot attack, i'm dead, unlucky!");
		return;
	}
	if (this->energy_points == 0)
	{
		std::cout << "ScavTrap " << this->name;
		MSG("cannot attack, i'm out of energy points, damn it!");
		return;
	}
	this->energy_points--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->attack_damage << " points of damage!\n";
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is currently in Gate Keeper mode!\n";
}