/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teamplate.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:02:49 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/20 11:30:29 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEAMPLATE_HPP
#define 	TEAMPLATE_HPP

#include "eader.h"

template<typename T, typename F>void	iter(T *array, const std::size_t length, F func)
{
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

#endif
