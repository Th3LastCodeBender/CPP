/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:53:29 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/30 16:50:28 by lparolis         ###   ########.fr       */
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
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed &obj);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
#endif /* FIXED_HPP_ */
