/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:54:21 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/29 17:59:11 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	DBG_MSG("ShrubberyCreationForm constructor called!");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj), _target(obj.getTarget())
{
	DBG_MSG("ShrubberyCreationForm constructor created!");
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    DBG_MSG("ShrubberyCreationForm copy operator called!");
	(void)obj;	
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	DBG_MSG("ShrubberyCreationForm destructor called!");
}

const std::string	ShrubberyCreationForm::getTarget()const
{
	return (this->_target);
}

void	ShrubberyCreationForm::executeAction()
{
	
}