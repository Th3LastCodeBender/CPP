/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:08:44 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/10 15:55:24 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define 	DIAMONDTRAP_HPP

#include "eader.h"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, ScavTrap
{
	private:

		std::string name;
		
	public:

		DiamondTrap(const std::string &name);
		~DiamondTrap();

		using ScavTrap::attack;
		
		void	whoAmI();
};

#endif