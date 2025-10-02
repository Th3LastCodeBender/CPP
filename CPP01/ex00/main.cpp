/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:48:48 by lparolis          #+#    #+#             */
/*   Updated: 2025/09/30 11:43:29 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main( void )
{
	Zombie *giancarlo;
	Zombie giorgino("giorgino");
	
	giancarlo = newZombie("giancarlo");
	giorgino.announce();
	giancarlo->announce();
	delete giancarlo;
}
