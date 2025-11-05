/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:36:18 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/05 16:23:35 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define 	AMATERIA_HPP

#include "eader.h"
#include "ICharacter.hpp"

class AMateria
{
	protected:

		std::string type;

	public:
	
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria &obj);
		AMateria &operator=(const AMateria &obj);
		~AMateria();
		
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif