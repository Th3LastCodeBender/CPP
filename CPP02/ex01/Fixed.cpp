/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:57:35 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/10 15:39:39 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Fixed constructor called" << std::endl;
	this->raw_value = 0;
}

Fixed::Fixed(const int toConvert)
{
	std::cout << "Fixed constructor called" << std::endl;
	this->raw_value = toConvert << this->fractional_bits;
}

Fixed::Fixed(const float toConvert)
{
	std::cout << "Fixed constructor called" << std::endl;
	this->raw_value = static_cast<int>(roundf((toConvert * (1 << this->fractional_bits))));
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Fixed copy constructor called" << std::endl;
	this->raw_value = obj.raw_value;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	if (this == &obj)
	{
		std::cout << "Belin, What the hell are you writing? Me = Me? The drugs have really messed you up." << std::endl;
		return (*this);
	}
	this->raw_value = obj.raw_value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Fixed destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return(this->raw_value);
}

void	Fixed::setRawBits ( int const raw )
{
	this->raw_value = raw;
}

float Fixed::toFloat ( void ) const
{
	return (static_cast<float>(this->raw_value) / (1 << fractional_bits));
}	

int	Fixed::toInt ( void ) const
{
	return (this->raw_value >> this->fractional_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj) 
{
    out << obj.toFloat();
    return (out);
}
