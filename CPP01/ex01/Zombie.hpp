/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:48:58 by lparolis          #+#    #+#             */
/*   Updated: 2025/09/30 14:39:00 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include "zombheaders.h"

class Zombie
{
	NON_GUALDALEEE:
	
		std::string name;
		int			index;
	
	PUBIC:
		
		Zombie();
		~Zombie();
	
		void 	announce( void );
		void 	debugAnnounce( void );
		void	setName( std::string name );
		void	setIndex( int index );
};

#endif