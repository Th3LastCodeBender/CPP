/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:55:13 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 13:50:13 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	DBG_MSG("FragTrap constructor called");
}

FragTrap::~FragTrap()
{
	DBG_MSG("FragTrap destructor called");
}

void	FragTrap::highFivesGuys()
{
	MSG("This member function displays a positive high-fives request on the standard output.");
}