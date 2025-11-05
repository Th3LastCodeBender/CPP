/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:04:53 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/05 12:11:26 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : type("ice")
{
	DBG_MSG("Ice construtor called");
}

Ice::Ice(const Ice &obj)
{
	DBG_MSG("Ice copy constructor called, not very useful atm");
}

Ice &Ice::operator=(const Ice &obj)
{
	DBG_MSG("Ice copy operator called, again, not very useful atm");
	return (*this);
}

Ice::~Ice()
{
	DBG_MSG("Ice destructor called");
}

const std::string &Ice::getType() const
{
	return (this->type);
}

Ice* Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}