/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:17:46 by lparolis          #+#    #+#             */
/*   Updated: 2025/09/30 17:54:31 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon()
{
	std::cout << "Weapon constructor called" << std::endl;
}

Weapon::Weapon( std::string startingWeapon)
{
	this->type = startingWeapon;
	std::cout << "Weapon constructor called" << std::endl;
}

void	Weapon::setType( std::string newType )
{
	this->type = newType;
}

const std::string& Weapon::getType()
{
	return (this->type);
}

Weapon::~Weapon()
{
	std::cout << "Weapon deconstructor called" << std::endl;
}