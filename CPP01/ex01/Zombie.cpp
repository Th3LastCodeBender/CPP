/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:48:55 by lparolis          #+#    #+#             */
/*   Updated: 2025/09/30 14:39:35 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie Constructor called" << std::endl;
}

void	Zombie::setName( std::string chiu_le)
{
	this->name = chiu_le;
	
	if (DEBUG == true)
		std::cout << this->name << " Zombie's name set" << std::endl;
}

void	Zombie::setIndex( int index )
{
	this->index = index;
	
	if (DEBUG == true)
		std::cout << this->name << " " << this->index << " Zombie's index set" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::debugAnnounce( void )
{
	std::cout << this->name << "number " << this->index << \
			": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << ": Destructor called" << std::endl;
}