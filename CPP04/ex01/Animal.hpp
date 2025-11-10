/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:16:45 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/10 15:54:43 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "eader.h"

class Animal
{
	protected:

		std::string type;

	public:

		Animal();
		Animal(const Animal &obj);
		Animal &operator=(const Animal &obj);
		virtual ~Animal();

		virtual std::string	getType() const;
		virtual void		makeSound() const;
};

#endif