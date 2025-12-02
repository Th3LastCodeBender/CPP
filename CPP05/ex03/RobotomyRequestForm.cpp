/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:54:17 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/02 17:33:19 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	DBG_MSG("RobotomyRequestForm constructor called!");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj), _target(obj.getTarget())
{
	DBG_MSG("RobotomyRequestForm constructor created!");
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    DBG_MSG("RobotomyRequestForm copy operator called!");
	(void)obj;	
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	DBG_MSG("RobotomyRequestForm destructor called!");
}

const std::string	RobotomyRequestForm::getTarget()const
{
	return (this->_target);
}

void	RobotomyRequestForm::executeAction() const
{
    std::cout << "BZZZZZ DRILLING...                 SUSANNAAAAAAAAAAAAAAAAAAAAAAA" << std::endl;

    int ran = std::rand() % 2;

    if (ran == 0)
        std::cout << this->_target << ": has been successfully robotomized!\n";
    else
        std::cout << this->_target << ": robotomisation failed!\n";

}