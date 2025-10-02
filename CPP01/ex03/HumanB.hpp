/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:18:59 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/01 11:11:52 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "eaderpuntoacca.h"
#include "Weapon.hpp"

class HumanB
{
	NON_GUALDALEEE:

		std::string name;
		Weapon		*weapon;
	
	PUBIC:
	
		HumanB( std::string startingName );
		~HumanB();
	
		void	attack();
		void	setWeapon( Weapon &weaponToSet);
};

#endif