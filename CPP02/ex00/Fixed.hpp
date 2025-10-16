/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:53:29 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/16 10:36:22 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"

class Fixed
{
	NON_GUALDALEEE:
	
		int					number_value;
		static const int	fractional_bits = 8;

	PUBIC:

		Fixed();
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed &obj);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw ) const;
};