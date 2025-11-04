/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:02:49 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/01 17:56:56 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define 	SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	NON_GUALDALEEE:

	PUBIC:
	
		ScavTrap(const std::string name);
		~ScavTrap();
		
		void	attack(const std::string &name);
		void	guardGate();	
};

#endif