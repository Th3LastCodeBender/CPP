/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:37:46 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 13:47:15 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "eader.h"
#include "Animal.hpp"

class Dog : public Animal
{
	NON_GUALDALEEE:

		std::string type;

	PUBIC:

		Dog();
		Dog(const Dog &obj);
		Dog &operator=(const Dog &obj);
		~Dog();

		virtual std::string getType() const;
		void				makeSound() const;
};

#endif