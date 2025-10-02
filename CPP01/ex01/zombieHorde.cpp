/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:23:50 by lparolis          #+#    #+#             */
/*   Updated: 2025/09/30 14:42:18 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	Zombie *horde;

	horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		horde[i].setName( name );
		horde[i].setIndex( i );	
	}
	
	return (horde);
}

void	iterator( Zombie *horde, int size, void (Zombie::*fx)() )
{
	for (int i = 0; i < size; i++)
	{
		(horde[i].*fx)();
	}
}

void	spread_democracy( Zombie *horde, int size )
{
	(void)size;
	delete[] horde;
}