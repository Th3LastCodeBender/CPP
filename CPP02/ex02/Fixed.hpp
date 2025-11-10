/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:53:29 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/10 15:55:24 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define		FIXED_HPP

#include "eader.h"

class Fixed
{
	private:
	
		int					raw_value;
		static const int	fractional_bits = 8;

	public:

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
