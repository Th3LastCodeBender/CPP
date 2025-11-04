/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:12:35 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 18:22:50 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"

class Brain
{
	NON_GUALDALEEE:

		std::string ideas[100];

	PUBIC:

		Brain();
		Brain(const Brain &obj);
		Brain &operator=(const Brain &obj);
		~Brain();
};