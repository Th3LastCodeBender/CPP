/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:36:18 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 22:44:38 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"

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
		
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};