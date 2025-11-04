/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:08:59 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 13:50:13 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	DBG_MSG("DiamondTrap constructor called");
}

DiamondTrap::~DiamondTrap()
{
	DBG_MSG("DiamondTrap destructor called");
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name : " << this->name << "\nClapTrap name : " << ClapTrap::name << std::endl;
}