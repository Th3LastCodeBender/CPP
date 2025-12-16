/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ToPrint.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:18:38 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/16 16:58:41 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ToPrint.hpp"

static bool isCharDisplayable(char c)
{
    return std::isprint(static_cast<unsigned char>(c)) != 0;
}

ToPrint::ToPrint() : c(0), i(0), f(0.0f), d(0.0), imMask(0)
{
	DBG_MSG("ToPrint constructor called");
}

ToPrint::ToPrint(char cVal, int iVal, float fVal, double dVal): c(cVal), i(iVal), f(fVal), d(dVal), imMask(0)
{
	DBG_MSG("ToPrint constructor called");
}

ToPrint::ToPrint(const ToPrint &other)
    : c(other.c), i(other.i), f(other.f), d(other.d), imMask(other.imMask) 
{
        DBG_MSG("ToPrint copy constructor called");
}

ToPrint &ToPrint::operator=(const ToPrint &other)
{
    DBG_MSG("ToPrint assignment operator called");
    if (this != &other)
    {
        c = other.c;
        i = other.i;
        f = other.f;
        d = other.d;
        imMask = other.imMask;
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
    if (tp.isCharImpossible())
        os << "impossible" << std::endl;
    else if (!isCharDisplayable(tp.getChar()))
        os << "Non displayable" << std::endl;
    else
        os << "'" << tp.getChar() << "'" << std::endl;
    os << "int: ";
    if (tp.isIntImpossible()) os << "impossible" << std::endl; else os << tp.getInt() << std::endl;
    os << "float: ";
    if (tp.isFloatImpossible()) os << "impossible" << std::endl; else os << tp.getFloat() << 'f' << std::endl;
    os << "double: ";
    if (tp.isDoubleImpossible()) os << "impossible" << std::endl; else os << tp.getDouble() << std::endl;
    return os;
}


void ToPrint::setChar(char value) { c = value; }
void ToPrint::setInt(int value) { i = value; }
void ToPrint::setFloat(float value) { f = value; }
void ToPrint::setDouble(double value) { d = value; }

void ToPrint::setCharImpossible() { imMask |= 1u << 0; }
void ToPrint::setIntImpossible() { imMask |= 1u << 1; }
void ToPrint::setFloatImpossible() { imMask |= 1u << 2; }
void ToPrint::setDoubleImpossible() { imMask |= 1u << 3; }

char ToPrint::getChar() const { return c; }
int ToPrint::getInt() const { return i; }
float ToPrint::getFloat() const { return f; }
double ToPrint::getDouble() const { return d; }

bool ToPrint::isCharImpossible() const { return (imMask & (1u << 0)) != 0; }
bool ToPrint::isIntImpossible() const { return (imMask & (1u << 1)) != 0; }
bool ToPrint::isFloatImpossible() const { return (imMask & (1u << 2)) != 0; }
bool ToPrint::isDoubleImpossible() const { return (imMask & (1u << 3)) != 0; }
