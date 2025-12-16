/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ToPrint.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:18:38 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/16 13:24:10 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ToPrint.hpp"

static bool isCharDisplayable(char c)
{
    return std::isprint(static_cast<unsigned char>(c)) != 0;
}

ToPrint::ToPrint() : hasChar(false), hasInt(false), hasFloat(false), hasDouble(false), c(0), i(0), f(0.0f), d(0.0) 
{
	DBG_MSG("ToPrint constructor called");
}

ToPrint::ToPrint(char cVal, int iVal, float fVal, double dVal)
: hasChar(true), hasInt(true), hasFloat(true), hasDouble(true), c(cVal), i(iVal), f(fVal), d(dVal)
{
	DBG_MSG("ToPrint constructor called");
}

ToPrint::ToPrint(const ToPrint &other)
        : hasChar(other.hasChar), hasInt(other.hasInt), hasFloat(other.hasFloat), hasDouble(other.hasDouble),
            c(other.c), i(other.i), f(other.f), d(other.d) 
{
        DBG_MSG("ToPrint copy constructor called");
}

ToPrint &ToPrint::operator=(const ToPrint &other)
{
    DBG_MSG("ToPrint assignment operator called");
    if (this != &other)
    {
        hasChar = other.hasChar;
        hasInt = other.hasInt;
        hasFloat = other.hasFloat;
        hasDouble = other.hasDouble;
        c = other.c;
        i = other.i;
        f = other.f;
        d = other.d;
    }
    return *this;
}

ToPrint::~ToPrint() 
{
    DBG_MSG("ToPrint destructor called");
}

std::ostream &operator<<(std::ostream &os, const ToPrint &tp)
{
    os << "char: ";
    if (!tp.hasChar)
        os << "impossible" << std::endl;
    else if (!isCharDisplayable(tp.c))
        os << "Non displayable" << std::endl;
    else
        os << "'" << tp.c << "'" << std::endl;

    os << "int: ";
    if (!tp.hasInt)
        os << "impossible" << std::endl;
    else
        os << tp.i << std::endl;

    os << std::fixed;
    os << "float: ";
    if (!tp.hasFloat)
        os << "impossible" << std::endl;
    else
        os << tp.f << 'f' << std::endl;

    os << "double: ";
    if (!tp.hasDouble)
        os << "impossible" << std::endl;
    else
        os << tp.d << std::endl;

    return os;
}
