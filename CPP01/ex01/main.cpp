/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:48:48 by lparolis          #+#    #+#             */
/*   Updated: 2025/09/30 14:41:44 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	iterator( Zombie *horde, int size, void (Zombie::*fx)());
void	spread_democracy( Zombie *horde, int size);
Zombie	*zombieHorde( int N, std::string name);

int main( void )
{
	Zombie *horde;
	int		size;
	
	size = 10;
	horde = zombieHorde(size, "FRANCESCO...VIRGOLINIII");
	if (DEBUG == true)
		iterator(horde, size, &Zombie::debugAnnounce);
	else
		iterator(horde, size, &Zombie::announce);
	spread_democracy(horde, size);
}
