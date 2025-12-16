/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ToPrint.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:19:54 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/16 16:14:42 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOPRINT_HPP
#define TOPRINT_HPP

#include "eader.h"

class ToPrint 
{
	private:

	    char c;
	    int i;
	    float f;
	    double d;
	    unsigned imMask;
	
	public:
	
	    ToPrint();
	    ToPrint(char cVal, int iVal, float fVal, double dVal);
	    ToPrint(const ToPrint &other);
	    ToPrint &operator=(const ToPrint &other);
	    ~ToPrint();

	    void setCharImpossible();
	    void setIntImpossible();
	    void setFloatImpossible();
	    void setDoubleImpossible();

		void setChar(char value);
		void setInt(int value);
		void setFloat(float value);
		void setDouble(double value);

		char getChar() const;
		int getInt() const;
		float getFloat() const;
	    double getDouble() const;
		
	    bool isCharImpossible() const;
	    bool isIntImpossible() const;
	    bool isFloatImpossible() const;
	    bool isDoubleImpossible() const;
};
	
std::ostream &operator<<(std::ostream &os, const ToPrint &tp);

#endif
