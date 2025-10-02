/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:17:27 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/01 09:56:56 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include "eaderpuntoacca.h"

class Weapon
{
	NON_GUALDALEEE:

		std::string type;

	PUBIC:

		Weapon();
		Weapon( std::string startingWeapon );
		~Weapon();

		void setType( std::string newType);
		const std::string &getType();
};

#endif