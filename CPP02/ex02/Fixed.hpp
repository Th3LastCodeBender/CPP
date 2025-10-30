/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:53:29 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/30 16:55:03 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP_
#define FIXED_HPP_
#include "eader.h"

class Fixed
{
	NON_GUALDALEEE:
	
		int					raw_value;
		static const int	fractional_bits = 8;

	PUBIC:

		Fixed();
		Fixed( const int toConvert);
		Fixed( const float toConvert);
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed &obj);
		friend std::ostream &operator<<(std::ostream &out, const Fixed &obj);
		~Fixed();

    	bool operator>(const Fixed& other) const;
    	bool operator<(const Fixed& other) const;
    	bool operator>=(const Fixed& other) const;
    	bool operator<=(const Fixed& other) const;
    	bool operator==(const Fixed& other) const;
    	bool operator!=(const Fixed& other) const;

    	Fixed operator+(const Fixed& other) const;
    	Fixed operator-(const Fixed& other) const;
    	Fixed operator*(const Fixed& other) const;
    	Fixed operator/(const Fixed& other) const;

    	Fixed& operator++();
    	Fixed operator++(int);
    	Fixed& operator--();
    	Fixed operator--(int);
		
    	static Fixed& min(Fixed& a, Fixed& b);
    	static const Fixed& min(const Fixed& a, const Fixed& b);
    	static Fixed& max(Fixed& a, Fixed& b);
    	static const Fixed& max(const Fixed& a, const Fixed& b);
		float toFloat( void ) const;
		int toInt( void ) const;
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};	
#endif
