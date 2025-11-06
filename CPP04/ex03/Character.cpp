/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:01:04 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/06 11:10:11 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("Nobody"), size(0)
{
	DBG_MSG("Character constructor called");
	
	for (size_t i = 0; i < 4; i++)
		this->inventory[i] = NULL;	
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
	for (size_t i = 0; i < size; ++i)
        delete leftovers[i];
    delete[] leftovers;
	delete[] inventory;
}

const std::string &Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "Dude, what are you doing? Drugs!?" << std::endl;
		return;
	}
	
	for (size_t i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			DBUG_MSG("AMateria equipped in slot: ");
			std::cout << i << std::endl;
			this->inventory[i] = m;
			return;
		}
	}
	
	DBUG_MSG("Inventory full!");
}
void	Character::addLeftoverMateria(int idx)
{
	size_t newSize;
	AMateria** newLeftovers;
	
	newSize = this->size + 1;
	newLeftovers = new AMateria* [newSize];

	for (size_t i = 0; i < this->size && this->leftovers[i]; i++)
		newLeftovers[i] = this->leftovers[i];

	newLeftovers[newSize] = this->inventory[idx];

	delete[] this->leftovers;
	this->leftovers = newLeftovers;
	this->size = newSize;
	
	DBUG_MSG("Added a new leftover");
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Hellooooo? Did we turn on the brain this morning? Doesn't seem like it! <3" << std::endl;
		return;	
	}
	if (!this->inventory[idx])
	{
		std::cout << "This is a new dimension error... remove nothing?... NOTHING!?\nI am lost in your incompetence" << std::endl;
		return;
	}
	addLeftoverMateria(idx);
	this->inventory[idx] = NULL;
	DBUG_MSG("Removed AMateria from inventory");
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Hellooooo? Did we turn on the brain this morning? Doesn't seem like it! <3" << std::endl;
		return;	
	}
	if (!this->inventory[idx])
	{
		std::cout << "This is a new dimension error... use nothing?... NOTHING!?\nI am lost in your incompetence" << std::endl;
		return;
	}
	
	this->inventory[idx]->use(target);
}