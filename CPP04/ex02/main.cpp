/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:16:17 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 19:40:05 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal* packs[10];

	for (size_t i = 0; i < 10; i++)
	{
		if (i < 5)
			packs[i] = new Dog();
		else
			packs[i] = new Cat();
	}
	
	for (size_t i = 0; i < 10; i++)
		packs[i]->makeSound();
		
	for (size_t i = 0; i < 10; i++)
		delete packs[i];
}

// int main()
// {
// 	Cat gatto;
// 	Dog cane;

// 	gatto.makeSound();
// 	cane.makeSound();
// 	return (0);
// }

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const WrongAnimal* i = new WrongCat();
// 	std::cout << "type: " << j->getType() << " " << std::endl;
// 	std::cout << "type: " << i->getType() << " " << std::endl;
// 	i->makeSound();
// 	j->makeSound();
// 	meta->makeSound();

// 	delete(i);
// 	delete(j);
// 	delete(meta);
// 	return 0;
// }