/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:25:38 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/02 19:05:06 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	DBG_MSG("Intern constructor called!");
	
	which_one[0] = "shrubbery creation";
	which_one[1] = "robotomy request";
	which_one[2] = "presidential pardon";
}

Intern::Intern(const Intern &obj)
{
	DBG_MSG("Intern copy constructor called!");
	(void)obj;
}

Intern &Intern::operator=(const Intern &obj)
{
	DBG_MSG("Intern copy operator called!");
	(void)obj;
	return (*this);
}

Intern::~Intern()
{
	DBG_MSG("Intern destructor called!");
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	int	type = 0;

	while (type < 3 && formName.compare(this->which_one[type]) != 0)
		type++;
	
	switch (type)
	{
	case 0:
		return(new ShrubberyCreationForm(target));
	case 1:
		return(new RobotomyRequestForm(target));
	case 2:
		return(new PresidentialPardonForm(target));
		break;
	
	default:
		throw WrongFormTypedef("intern was unable to create a form for: " + target);
		break;
	}
}