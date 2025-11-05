/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:11:41 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/05 12:38:28 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define 	CURE_HPP

#include "eader.h"
#include "AMateria.hpp"

class Cure : public AMateria
{
	NON_GUALDALEEE:

		const std::string type;
	
	PUBIC:

		Cure();
		Cure(const Cure &obj);
		Cure &operator=(const Cure &obj);
		~Cure();

		std::string const & getType() const;
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif
