/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:36:28 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 13:57:25 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : type("WrongCat")
{
	DBG_MSG("WrongCat constructor called");
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	this->type = obj.type;
	DBG_MSG("WrongCat copy constructor called");
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
	WrongAnimal::operator=(obj);
	this->type = obj.type;
	
	DBG_MSG("WrongCat copy operator called");
	return(*this);
}

WrongCat::~WrongCat()
{
	DBG_MSG("WrongCat destructor called");
}

void	WrongCat::makeSound() const
{
	std::cout << "WRONG MIAO" << std::endl;
	EEGG_MSG("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
}

std::string	WrongCat::getType() const
{
	return (this->type);
}