/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:23:19 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/10 15:54:43 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define 	CLAPTRAP_HPP

#include "eader.h"

class ClapTrap
{
	protected:
	
		std::string name;
		int hit_points;
		int energy_points;
		int attack_damage;
		const unsigned int max_hp;

	public:

		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &obj);
		ClapTrap& operator=(const ClapTrap &obj);
		virtual ~ClapTrap();
		
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif