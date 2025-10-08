/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:53:29 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/08 11:13:42 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"

class Fixed
{
	NON_GUALDALEEE:
	
		int					number_value;
		static const int	fractional_bits;

	PUBIC:

		Fixed();
		Fixed(const Fixed &obj);
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed &obj);
		int getRawbits( void ) const;
		void setRawbits( int const raw ) const;
};