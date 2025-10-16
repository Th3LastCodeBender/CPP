/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:57:35 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/16 11:01:56 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Fixed constructor called" << std::endl;
	this->number_value = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Fixed copy constructor called" << std::endl;
	this->number_value = obj.number_value;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	if (this == &obj)
	{
		std::cout << "Ma belin, ma cosa scrivi? Io = Io? Certo che la droga ti ha fatto parecchio male" << std::endl;
		return (*this);
	}
	this->number_value = obj.number_value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Fixed deconstructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << 
}