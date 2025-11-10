/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:37:46 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/10 15:55:24 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "eader.h"
#include "Animal.hpp"

class Dog : public Animal
{
	private:

		std::string type;

	public:

		Dog();
		Dog(const Dog &obj);
		Dog &operator=(const Dog &obj);
		~Dog();

		virtual std::string getType() const;
		void				makeSound() const;
};

#endif