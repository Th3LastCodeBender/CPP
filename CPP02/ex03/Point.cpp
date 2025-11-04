/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:08:08 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 13:50:13 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#if defined(DEBUG) && DEBUG
  #define DBG_MSG(msg) (std::cout << (msg) << std::endl)
#else
  #define DBG_MSG(msg) ((void)0)
#endif

Point::Point()
{
	DBG_MSG("Point constructor called");
}

Point::Point(const float xf, const float yf) : x(xf), y(yf)
{
	DBG_MSG("Point constructor called");
}

Point::Point(const Point &obj) : x(obj.x), y(obj.y)
{
	DBG_MSG("Point copy constructor called");
}

Point &Point::operator=(const Point &obj)
{
	(void)obj;
	DBG_MSG("BELIN QUI E' TUTTO CONST NON POSSO FARE NA BEGA");
	return (*this);
}

int	Point::getX()
{
	return (this->x.getRawBits());
}

int	Point::getY()
{
	return (this->y.getRawBits());
}

Point::~Point()
{
	DBG_MSG("Point destructor called");
}

static Fixed	fixedTriangleArea(Point a, Point b, Point c)
{
    Fixed term1 = a.getX() * (b.getY() - c.getY());
    Fixed term2 = b.getX() * (c.getY() - a.getY());
    Fixed term3 = c.getX() * (a.getY() - b.getY());
    
    Fixed area = (term1 + term2 + term3);
	
	if (area < 0)
		area = area * Fixed(-1);
	
    return (area / Fixed(2));
}

bool Point::bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC = fixedTriangleArea(a, b, c);
    Fixed areaABP = fixedTriangleArea(a, b, point);
    Fixed areaBCP = fixedTriangleArea(b, c, point);
    Fixed areaCAP = fixedTriangleArea(c, a, point);

    // se è su un lato -> non è "inside"
    if (areaABP == Fixed(0) || areaBCP == Fixed(0) || areaCAP == Fixed(0))
        return false;

    Fixed sum = areaABP + areaBCP + areaCAP;
    return (sum == areaABC);
}