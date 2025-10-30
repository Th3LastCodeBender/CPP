/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:08:35 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/30 16:40:37 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"
#include "Fixed.hpp"

class Point
{
	NON_GUALDALEEE:

		const Fixed x;
		const Fixed y;

	PUBIC:

		Point();
		Point(const float xf, const float yf);
		Point(const Point &obj);
		Point& operator=(const Point &obj);
		~Point();

		int	getX();
		int	getY();
		
		// Fixed fixedTriangleArea(Point a, Point b, Point c);
		static bool bsp( Point const a, Point const b, Point const c, Point const point);
};