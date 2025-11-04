/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:04:40 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 18:47:51 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "eader.h"
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	NON_GUALDALEEE:

		std::string type;
		Brain* scervelo;

	PUBIC:

		Cat();
		Cat(const Cat &obj);
		Cat &operator=(const Cat &obj);
		~Cat();

		virtual std::string getType() const;
		void				makeSound() const;
};

#endif