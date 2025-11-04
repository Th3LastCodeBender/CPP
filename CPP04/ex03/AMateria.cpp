/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:45:15 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 22:57:08 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("null")
{
	DBG_MSG("AMateria constructor called");
}

AMateria::AMateria(std::string const &type) : type(type)
{
	DBG_MSG("AMateria constructor called");
}

AMateria::AMateria(const AMateria &obj)
{
	DBG_MSG("AMateria copy constructor called");
	
	this->type = obj.type;
}

AMateria& AMateria::operator=(const AMateria &obj)
{
	DBG_MSG("AMateria copy operator called\nPretty useless atm");
}

AMateria::~AMateria()
{
	DBG_MSG("AMateria destructor called");
}

const std::string& AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << target.name << " is very excited to exist!" << std::endl;
}