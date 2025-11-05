/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:05:14 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/05 12:17:55 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : type("cure")
{
	DBG_MSG("Cure constructor called");
}

Cure::Cure(const Cure &obj)
{
	DBG_MSG("Cure copy constructor called, veeery useful");
}

Cure &Cure::operator=(const Cure &obj)
{
	DBG_MSG("Cure copy operator called, WOW");
}

Cure::~Cure()
{
	DBG_MSG("Cure destructor called");
}

Cure* Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter& target)
{
	std::cout << "heals " << target.getName() << "'s wounds *" << std::endl;
}