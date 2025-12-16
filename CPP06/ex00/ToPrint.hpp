/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ToPrint.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:19:54 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/16 13:20:57 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOPRINT_HPP
#define TOPRINT_HPP

#include "eader.h"

class ToPrint 
{
	private:
	
	    bool hasChar;
	    bool hasInt;
	    bool hasFloat;
	    bool hasDouble;
	
	    char c;
	    int i;
	    float f;
	    double d;
	
	public:
	
	    ToPrint();
	    ToPrint(char cVal, int iVal, float fVal, double dVal);
	    ToPrint(const ToPrint &other);
	    ToPrint &operator=(const ToPrint &other);
	    ~ToPrint();
	
	    friend std::ostream &operator<<(std::ostream &os, const ToPrint &tp);
};

#endif
