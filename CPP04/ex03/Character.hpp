/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:23:36 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/05 17:47:13 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define 	CHARACTER_HPP

#include "eader.h"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	NON_GUALDALEEE:

		std::string name;
		AMateria* inventory[4];
	
	PUBIC:
		
		Character();
		Character(const std::string name);
		Character(const Character &obj);
		Character &operator=(const Character &obj);
		~Character();
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
}

#endif
