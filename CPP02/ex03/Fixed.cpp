/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:57:35 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/29 18:03:30 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#if defined(DEBUG) && DEBUG
  #define DBG_MSG(msg) (std::cout << (msg) << std::endl)
#else
  #define DBG_MSG(msg) ((void)0)
#endif

Fixed::Fixed()
{
	DBG_MSG("Fixed constructor called");
	this->raw_value = 0;
}

Fixed::Fixed(const int toConvert)
{
	DBG_MSG("Fixed constructor called");
	this->raw_value = toConvert << this->fractional_bits;
}

Fixed::Fixed(const float toConvert)
{
	DBG_MSG("Fixed constructor called");
	this->raw_value = static_cast<int>(roundf((toConvert * (1 << this->fractional_bits))));
}

Fixed::Fixed(const Fixed &obj)
{
	DBG_MSG("Fixed copy constructor called");
	this->raw_value = obj.raw_value;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	if (this == &obj)
	{
		DBG_MSG("Ma belin, ma cosa scrivi? Io = Io? Certo che la droga ti ha fatto parecchio male");
		return (*this);
	}
	this->raw_value = obj.raw_value;
	return (*this);
}

Fixed::~Fixed()
{
	DBG_MSG("Fixed deconstructor called");
}

int Fixed::getRawBits( void ) const
{
	return(this->raw_value);
}

void	Fixed::setRawBits ( int const raw )
{
	this->raw_value = raw;
}

float	Fixed::toFloat ( void ) const
{
	return (static_cast<float>(this->raw_value) / (1 << fractional_bits));
}	

int	Fixed::toInt ( void ) const
{
	return (this->raw_value >> this->fractional_bits);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &obj) 
{
    out << obj.toFloat();
    return (out);
}

bool	Fixed::operator>(const Fixed& other) const { return (raw_value > other.raw_value); }

bool	Fixed::operator<(const Fixed& other) const { return (raw_value < other.raw_value); }

bool	Fixed::operator>=(const Fixed& other) const { return (raw_value >= other.raw_value); }

bool	Fixed::operator<=(const Fixed& other) const { return (raw_value <= other.raw_value); }

bool	Fixed::operator==(const Fixed& other) const { return (raw_value == other.raw_value); }

bool	Fixed::operator!=(const Fixed& other) const { return (raw_value != other.raw_value); }

Fixed	Fixed::operator+(const Fixed& other) const 
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other) const 
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other) const 
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other) const 
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++()
{
	raw_value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);

    raw_value++;
    return (temp);
}

Fixed& Fixed::operator--()
{
    raw_value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);

    raw_value--;
    return (temp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}