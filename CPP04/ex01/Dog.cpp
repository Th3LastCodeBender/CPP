/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:36:28 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 22:26:11 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : type("Dog")
{
	this->scervelo = new Brain;
	DBG_MSG("Dog constructor called");
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	this->type = obj.type;

	if (obj.scervelo)
		this->scervelo = new Brain(*obj.scervelo);

	DBG_MSG("Dog copy constructor called");
}

Dog &Dog::operator=(const Dog &obj)
{
	this->type = obj.type;
	
	delete this->scervelo;
	this->scervelo = NULL;

	if (obj.scervelo)
		this->scervelo = new Brain(*obj.scervelo);

	DBG_MSG("Dog copy operator called");
	return(*this);
}

Dog::~Dog()
{
	delete (scervelo);
	DBG_MSG("Dog destructor called");
}

void	Dog::makeSound() const
{
	std::cout << "WOOF" << std::endl;
	EEGG_MSG("VERONICAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
}

std::string Dog::getType() const
{
	return (this->type);
}