/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:02:49 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/31 17:35:32 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	NON_GUALDALEEE:

	PUBIC:
	
		ScavTrap(const std::string name);
		~ScavTrap();
		
		void	attack(const std::string &name);
		void	guardGate();	
};