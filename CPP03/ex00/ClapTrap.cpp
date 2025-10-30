/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:23:17 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/30 17:41:55 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#if defined(DEBUG) && DEBUG
  #define DBG_MSG(msg) (std::cout << (msg) << std::endl)
#else
  #define DBG_MSG(msg) ((void)0)
#endif

ClapTrap::ClapTrap( std::string name )
{
	this->name = name;
	this->attack_damage = 10;
	this->energy_points = 10;
	this->hit_points = 10;
	DBG_MSG("ClapTrap constructor called");
}

ClapTrap::ClapTrap( const ClapTrap &obj)
{
	this->attack_damage = obj.attack_damage;
	this->energy_points = obj.energy_points;
	this->hit_points = obj.hit_points;
	DBG_MSG("ClapTrap copy constructor called");
}