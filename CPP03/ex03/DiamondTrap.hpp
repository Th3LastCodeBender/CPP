/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:08:44 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/31 17:45:58 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, ScavTrap
{
	NON_GUALDALEEE:

		std::string name;
		
	PUBIC:

		DiamondTrap(const std::string &name);
		~DiamondTrap();

		using ScavTrap::attack;
		
		void	whoAmI();
};