/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:23:17 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/31 11:42:48 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name )
{
	this->name = name;
	this->attack_damage = 10;
	this->energy_points = 10;
	this->hit_points = 10;
	DBG_MSG("ClapTrap constructor called");
}

ClapTrap::ClapTrap( const ClapTrap &obj)
{
	this->attack_damage = obj.attack_damage;
	this->energy_points = obj.energy_points;
	this->hit_points = obj.hit_points;
	DBG_MSG("ClapTrap copy constructor called");
}

ClapTrap  &ClapTrap::operator=(const ClapTrap &obj)
{
	if (this == &obj)
	{
		DBG_MSG("Ma belin, ma cosa scrivi? Io = Io? Certo che la droga ti ha fatto parecchio male");
		return (*this);
	}
	this->attack_damage = obj.attack_damage;
	this->energy_points = obj.energy_points;
	this->hit_points = obj.hit_points;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	DBG_MSG("ClapTrap destructor called");
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->energy_points == 0)
	{
		std::cout << "ClapTrap " << this->name;
		MSG(" Seems to be out of energon and cannot attack anymore!\n");
		return;
	}
    if (this->hit_points == 0)
    {
        std::cout << "ClapTrap " << this->name << " is dead!\n";
        return;
    }

	std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attack_damage << " points of damage\n";
	this->energy_points--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > static_cast<unsigned int>(this->hit_points))
	{
		std::cout << "ClapTrap " << this->name << " gets hit by a fatal strike!\n";
		this->hit_points = 0;
		return;
	}
	
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!\n";
	this->hit_points -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " is out of energon and cannot repair itself anymore!\n";
		return;
	}
    if (this->hit_points == 0)
    {
        std::cout << "ClapTrap " << this->name << " is dead and cannot be repaired\n";
        return;
    }
	
	this->energy_points--;
	
	if (this->hit_points > 10)
	{
		amount -= (this->hit_points + amount) - 10;
		this->hit_points += amount;
	}
	else
		this->hit_points += amount;

	std::cout << "ClapTrap " << this->name << " gets repaired for " << amount << " points!\n"; 
}