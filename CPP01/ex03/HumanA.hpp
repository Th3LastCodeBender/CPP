/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:18:56 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/01 10:39:17 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "eaderpuntoacca.h"
#include "Weapon.hpp"

class HumanA
{
	NON_GUALDALEEE:

		std::string name;
		Weapon		&weapon;
	
	PUBIC:
	
		HumanA( std::string name, Weapon &startingWeapon );
		~HumanA();
	
		void	attack();
};

#endif