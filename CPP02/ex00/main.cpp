/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:51:52 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/16 11:21:50 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"
#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed b( a );
	// Fixed b( b );
	Fixed c;

	// c = c;
	c = b;
	c.setRawBits(INT_MIN);
	// c = b;
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return (0);
}