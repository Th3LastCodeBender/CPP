/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:47:50 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/02 19:08:57 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    Intern intern;
    Bureaucrat boss("Boss", 1);

    struct Case { const char* name; const char* target; };
    Case cases[] = {
        {"robotomy request", "Bender"},
        {"shrubbery creation", "garden"},
        {"presidential pardon", "Marvin"}
    };
    const int ncases = sizeof(cases) / sizeof(cases[0]);

    std::cout << "=== Intern create/execute tests ===\n";
    for (int i = 0; i < ncases; ++i)
    {
        AForm* form = NULL;
        try
        {
            form = intern.makeForm(cases[i].name, cases[i].target);
            std::cout << "Intern created form: " << form->getName()
                      << " (target: " << cases[i].target << ")\n";

            boss.signForm(*form);
            boss.executeForm(*form);
        }
        catch (const std::exception &e)
        {
            std::cout << "Errore test \"" << cases[i].name << "\": " << e.what() << '\n';
        }
        if (form)
            delete form;
    }

    std::cout << "\n=== Intern unknown-form test ===\n";
    try
    {
        AForm *bad = intern.makeForm("unknown form name", "Nobody");
        delete bad;
        std::cout << "ERRORE: intern ha creato una form per nome non valido\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "Comportamento atteso: eccezione per nome non valido: " << e.what() << '\n';
    }

    std::cout << "\nTest completati.\n";
    return 0;
}
