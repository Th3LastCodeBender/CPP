/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:48:14 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/19 17:09:39 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include "Functions.hpp"

Base *generate(void)
{
	std::srand(static_cast<unsigned int>(time(0)));
    int r = std::rand() % 3;

	if (r == 0)
		return (new A);
	else if (r == 1)
		return (new B);
	else
		return (new C);

	std::cout << "r didn't behave well im afraid" << std::endl;
	return(NULL);
}

void	identify(Base *p)  //con puntatori restituisce NULL
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p) //con reference restituisce un'eccezione
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (...) {}
	// std::cout << "No type identified" << std::endl;
}

int main(void)
{
	Base *gen = generate();

	identify(*gen);
	identify(gen);
	
	delete gen;
	return (0);
}