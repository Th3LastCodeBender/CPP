/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:14:59 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/05 15:21:00 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define 	ICE_HPP

#include "eader.h"
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	NON_GUALDALEEE:

		const std::string type;

	PUBIC:

		Ice();
		Ice(const Ice &obj);
		Ice &operator=(const Ice &obj);
		~Ice();

		std::string const & getType() const;
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif
