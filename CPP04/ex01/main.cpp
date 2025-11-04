/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:16:17 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/04 18:04:58 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	
	return 0;
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