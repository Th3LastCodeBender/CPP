/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:48:58 by lparolis          #+#    #+#             */
/*   Updated: 2025/09/30 10:43:35 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include "zombheaders.h"

class Zombie
{
	NON_GUALDALEEE:
	
		std::string name;
	
	PUBIC:
		
		Zombie( std::string name );
		~Zombie();
	
		void 	announce( void );
};

#endif