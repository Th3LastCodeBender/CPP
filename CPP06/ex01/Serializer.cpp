/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:04:18 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/19 16:05:00 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	DBG_MSG("Serializer constructor called");
}

Serializer::Serializer(const Serializer &obj)
{
	(void)obj;
	DBG_MSG("Serializer copy constructor called");
}

Serializer &Serializer::operator=(const Serializer &obj)
{
	(void)obj;
	DBG_MSG("Serializer copy operator called");
	return (*this);
}

Serializer::~Serializer()
{
	DBG_MSG("Serializer destructor called");
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}