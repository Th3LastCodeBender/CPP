/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:55:16 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/10 15:55:24 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define 	FRAGTRAP_HPP

#include "eader.h"
#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:

		
	public:

		FragTrap(const std::string &name);
		~FragTrap();
		
		void highFivesGuys(void);
};

#endif