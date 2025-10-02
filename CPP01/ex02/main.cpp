/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:50:37 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/01 11:14:00 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#define TUAMADRE &stringREF = string;

int main ( void )
{
	std::string string;
	std::string *stringPTR;
	std::string TUAMADRE;

	string = "HI THIS IS BRAIN";
	stringPTR = &string;
	stringREF = string;

	std::cout << "Memory address of string variable :";
	std::cout << &string << std::endl;
	std::cout << "Memory address held by stringPTR  :";
	std::cout << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF  :";
	std::cout << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Belin quanta roba da stampare" << std::endl;
	std::cout << std::endl;
	std::cout << "Value of string variable          :";
	std::cout << string << std::endl;
	std::cout << "Value pointed by stringPTR        :";
	std::cout << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF        :";
	std::cout << stringREF << std::endl;
}