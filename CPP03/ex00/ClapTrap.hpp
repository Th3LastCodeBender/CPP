/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:23:19 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/05 17:30:51 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define 	CLAPTRAP_HPP

#include "eader.h"

class ClapTrap
{
	NON_GUALDALEEE:
	
		std::string name;
		int hit_points;
		int energy_points;
		int attack_damage;
		const unsigned int max_hp;

	PUBIC:

		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &obj);
		ClapTrap &operator=(const ClapTrap &obj);
		~ClapTrap();
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif