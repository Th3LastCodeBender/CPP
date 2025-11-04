/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:17:16 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 18:00:26 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("default")
{
	DBG_MSG("Animal constructor called");
}

Animal::Animal(const Animal &obj)
{
	this->type = obj.type;
	DBG_MSG("Animal copy constructor called");
}

Animal &Animal::operator=(const Animal &obj)
{
	this->type = obj.type;
	
	DBG_MSG("Animal copy operator called");
	return (*this);
}

Animal::~Animal()
{
	DBG_MSG("Animal destructor called");
}

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	return;
}