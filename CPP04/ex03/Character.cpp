/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:01:04 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/05 17:48:37 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("Nobody")
{
	for (size_t i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	
	DBG_MSG("Character constructor called");
}

Character::Character(const std::string name) : name(name)
{
	DBG_MSG("Character constructor called");	
}

Character::Character(const Character &obj)
{
	DBG_MSG("Character copy constructor called");
	
	this->name = obj.name;
	for (size_t i = 0; i < 4; i++)
		this->inventory[i] = obj.inventory[i]->clone();
}

Character &Character::operator=(const Character &obj)
{
	DBG_MSG("Character copy operator called");

	this->name = obj.name;
	
	delete[] inventory;
	
	for (size_t i = 0; i < 4; i++)
		this->inventory[i] = obj.inventory[i]->clone();
}

Character::~Character()
{
	DBG_MSG("Character deconstructor called");
	delete(inventory);
}