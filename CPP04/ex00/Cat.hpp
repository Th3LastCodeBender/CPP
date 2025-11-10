/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:04:40 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/10 15:55:24 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "eader.h"
#include "Animal.hpp"

class Cat : public Animal
{
	private:

		std::string type;

	public:

		Cat();
		Cat(const Cat &obj);
		Cat &operator=(const Cat &obj);
		~Cat();

		virtual std::string getType() const;
		void				makeSound() const;
};

#endif