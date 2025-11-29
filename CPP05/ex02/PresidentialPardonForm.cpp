/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:54:13 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/29 18:05:17 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 145, 137), _target(target)
{
	DBG_MSG("PresidentialPardonForm constructor called!");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj), _target(obj.getTarget())
{
	DBG_MSG("PresidentialPardonForm constructor created!");
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
    DBG_MSG("PresidentialPardonForm copy operator called!");
	(void)obj;	
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	DBG_MSG("PresidentialPardonForm destructor called!");
}

const std::string	PresidentialPardonForm::getTarget()const
{
	return (this->_target);
}

void	PresidentialPardonForm::executeAction()
{
	
}