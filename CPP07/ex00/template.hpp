/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:48:56 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/19 18:13:05 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define 	TEMPLATE_HPP

#include "eader.h"

template<typename T> void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T> const T &min(const T &a, const T &b)
{
	return ((a < b) ? a : b);
}

template<typename T> const T &max(const T &a, const T &b)
{
	return ((a > b) ? a : b);
}

#endif
