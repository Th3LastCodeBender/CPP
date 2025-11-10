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
#define 	FIXED_HPP

#include "eader.h"

class Fixed
{
	private:
	
		int					raw_value;
		static const int	fractional_bits = 8;

	public:

		Fixed();
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed &obj);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
