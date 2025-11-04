/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:36:28 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 13:57:25 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : type("Cat")
{
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
	DBG_MSG("Cat destructor called");
}

void	Cat::makeSound() const
{
	std::cout << "BAU" << std::endl;
	EEGG_MSG("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
}

std::string	Cat::getType() const
{
	return (this->type);
}