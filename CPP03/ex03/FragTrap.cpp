/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:55:13 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/31 17:07:14 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	DBG_MSG("FragTrap constructor called");
}

FragTrap::~FragTrap()
{
	DBG_MSG("FragTrap deconstructor called");
}

void	FragTrap::highFivesGuys()
{
	MSG("This member function displays a positive high-fives request on the standard output.");
}