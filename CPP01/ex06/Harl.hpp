/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:33:39 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/10 15:55:24 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include "eader.h"

class Harl
{
	private:

		void		(Harl::*complaints[4])();	
		std::string function[4];
		
		void		debug( void );
		void		info( void );
		void		warning( void );
		void		error( void );

	public:

		Harl();
		~Harl();

		void		complain( std::string level );
};

#endif