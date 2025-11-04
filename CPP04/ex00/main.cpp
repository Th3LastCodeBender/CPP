/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:16:17 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 13:54:14 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"
#include "Cat.hpp"
#include "Dog.hpp"

// int main()
// {
// 	Cat gatto;
// 	Dog cane;

// 	gatto.makeSound();
// 	cane.makeSound();
// 	return (0);
// }

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete(i);
	delete(j);
	delete(meta);
	return 0;
}