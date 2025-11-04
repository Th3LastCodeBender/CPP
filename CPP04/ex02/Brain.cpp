/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:22:52 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 19:21:45 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	DBG_MSG("Brain constructor called");
}

Brain::Brain(const Brain &obj)
{
	DBG_MSG("Brain copy constructor called");
	
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = obj.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &obj)
{
	DBG_MSG("Brain copy operator called");
	
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = obj.ideas[i];
	}
	
	return (*this);
}

Brain::~Brain()
{
	DBG_MSG("Brain destructor called");	
}