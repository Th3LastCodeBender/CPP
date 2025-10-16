/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:53:29 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/16 17:26:40 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		
		float toFloat( void ) const;
		int toInt( void ) const;
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};