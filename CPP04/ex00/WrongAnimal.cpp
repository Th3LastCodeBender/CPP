/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:17:16 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 13:54:42 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("default")
{
	DBG_MSG("WrongAnimal constructor called");
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	this->type = obj.type;
	DBG_MSG("WrongAnimal copy constructor called");
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
	this->type = obj.type;
	
	DBG_MSG("WrongAnimal copy operator called");
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	DBG_MSG("WrongAnimal destructor called");
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const
{
	MSG("Wrong Animal");
	return;
}