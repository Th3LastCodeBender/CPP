/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:47:50 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/29 14:27:18 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat b1("Giorno", 0);
        std::cout << b1 << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Giovanna", 151);
        std::cout << b2 << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat giorgio("Giorgio", 2);
        std::cout << giorgio << std::endl;
        giorgio.incrementGrade();
        std::cout << giorgio << std::endl;
        giorgio.incrementGrade();
        std::cout << giorgio << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat maria("Maria", 149);
        std::cout << maria << std::endl;
        maria.decrementGrade();
        std::cout << maria << std::endl;
        maria.decrementGrade();
        std::cout << maria << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}