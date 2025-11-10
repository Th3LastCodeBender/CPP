/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:04:40 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/10 15:55:24 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "eader.h"
#include "Animal.hpp"
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:

		std::string type;

	public:

		WrongCat();
		WrongCat(const WrongCat &obj);
		WrongCat &operator=(const WrongCat &obj);
		~WrongCat();

		virtual std::string getType() const;
		void				makeSound() const;
};

#endif