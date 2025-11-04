/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:55:16 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/01 17:54:30 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define 	FRAGTRAP_HPP

#include "eader.h"
#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	NON_GUALDALEEE:

		
	PUBIC:

		FragTrap(const std::string &name);
		~FragTrap();
		
		void highFivesGuys(void);
};

#endif