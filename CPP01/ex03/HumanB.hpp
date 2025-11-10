/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:18:59 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/10 15:55:24 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "eaderpuntoacca.h"
#include "Weapon.hpp"

class HumanB
{
	private:

		std::string name;
		Weapon		*weapon;
	
	public:
	
		HumanB( std::string startingName );
		~HumanB();
	
		void	attack();
		void	setWeapon( Weapon &weaponToSet);
};

#endif