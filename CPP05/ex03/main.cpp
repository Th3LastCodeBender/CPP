/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:47:50 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/02 17:35:25 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat giorgio("giorgio", 1);
        Bureaucrat byakuya("byakuya", 75);
        Bureaucrat susanna("susanna", 150);

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Marvin");

        std::cout << "=== Signing phase ===\n";
		
        byakuya.signForm(shrub);       // expected to succeed
        try { susanna.signForm(robot); } // expected to fail (grade too low)
        catch (const std::exception &e) { std::cout << "susanna failed to sign robot: " << e.what() << '\n'; }
        giorgio.signForm(robot);     // should succeed
        giorgio.signForm(pardon);    // should succeed

        std::cout << "\n=== Execution phase ===\n";
        // executing unsigned form should throw
        ShrubberyCreationForm unsignedForm("tmp_target");
        try {
            giorgio.executeForm(unsignedForm);
        } catch (const std::exception &e) {
            std::cout << "execute unsignedForm failed: " << e.what() << '\n';
        }

        // execute shrub (byakuya signed it)
        byakuya.executeForm(shrub);

        // robotomy multiple tries (random outcome)
        for (int i = 0; i < 3; ++i)
            giorgio.executeForm(robot);

        // presidential pardon requires very high grade (giorgio can)
        giorgio.executeForm(pardon);

        std::cout << "\nAll operations attempted.\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}




// int main()
// {
// //	Bureaucrat	giorgio("giorgio", 75);
// //	Form		pulizia_etnica("pulizia_etnica", 73, 75);

// 	Bureaucrat				giorgio("giorgio", 1);
// 	ShrubberyCreationForm	shrubbery("garden");
// 	RobotomyRequestForm 	robo("blipblip");
// 	PresidentialPardonForm	popopo("political");
   
// 	giorgio.signForm(shrubbery);
// 	giorgio.signForm(robo);
// 	giorgio.signForm(popopo);
// 	giorgio.executeForm(shrubbery);
// 	giorgio.executeForm(robo);
// 	giorgio.executeForm(popopo);
   
//    return 0;
// }