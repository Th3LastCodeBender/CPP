/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:11:41 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/10 15:55:24 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define 	CURE_HPP

#include "eader.h"
#include "AMateria.hpp"

class Cure : public AMateria
{
	private:

		const std::string type;
	
	public:

		Cure();
		Cure(const Cure &obj);
		Cure &operator=(const Cure &obj);
		~Cure();

		std::string const & getType() const;
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif
