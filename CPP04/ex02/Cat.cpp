/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:36:28 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 19:03:05 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : type("Cat")
{
	this->scervelo = new Brain;
	DBG_MSG("Cat constructor called");
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	this->type = obj.type;
	DBG_MSG("Cat copy constructor called");
}

Cat &Cat::operator=(const Cat &obj)
{
	Animal::operator=(obj);
	this->type = obj.type;
	
	DBG_MSG("Cat copy operator called");
	return(*this);
}

Cat::~Cat()
{
	delete(scervelo);
	DBG_MSG("Cat destructor called");
}

void	Cat::makeSound() const
{
	std::cout << "MEAOW" << std::endl;
	EEGG_MSG("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
}

std::string	Cat::getType() const
{
	delete(scervelo);
	return (this->type);
}