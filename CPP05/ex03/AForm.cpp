/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:42:44 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/02 17:47:35 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(75), _gradeToExec(75)
{
	DBG_MSG("AForm constructor called");
}

AForm::AForm(int gradeToSign, int gradeToExec) : _name("default"), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	DBG_MSG("AForm constructor called");

	if (this->_gradeToExec < 1)
		throw GradeTooHighException(_name + " _gradeToExec is too high!\n");
	if (this->_gradeToSign < 1)
		throw GradeTooHighException(_name + "_gradeToSign is too high!\n");
	
	if(this->_gradeToExec > 150)
		throw GradeTooLowException(_name + " _gradeToExec is too low!\n");
	if(this->_gradeToSign > 150)
		throw GradeTooLowException(_name + " _gradeToSign is too low!\n");
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	DBG_MSG("AForm constructor called");
	
	if (this->_gradeToExec < 1)
		throw GradeTooHighException(_name + " _gradeToExec is too high!\n");
	if (this->_gradeToSign < 1)
		throw GradeTooHighException(_name + "_gradeToSign is too high!\n");
	
	if(this->_gradeToExec > 150)
		throw GradeTooLowException(_name + " _gradeToExec is too low!\n");
	if(this->_gradeToSign > 150)
		throw GradeTooLowException(_name + " _gradeToSign is too low!\n");
}

AForm::AForm(const AForm &obj) : _name(obj.getName()), _signed(obj.getSignature()), _gradeToSign(obj.getGradeToSign()), _gradeToExec(obj.getGradeToExec())
{
	DBG_MSG("Copy constructor called!");
}

AForm &AForm::operator=(const AForm &obj) //: _name(obj.getName()), _gradeToExec(obj.getGradeToExec()), _gradeToSign(obj.getGradeToSign())
{
	DBG_MSG("Copy operator called!");
	(void)obj;
	// AForm copy(obj);
	// return (copy);
	return(*this);
}

AForm::~AForm()
{
	DBG_MSG("From destructor called!");
}

const std::string  AForm::getName() const
{
	return (this->_name);
}

int	AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}

bool	AForm::getSignature() const
{
	return (this->_signed);
}

void	AForm::beSigned(const Bureaucrat &Bcrat)
{
	if (Bcrat.getGrade() <= this->getGradeToSign())
		this->_signed = true;
	else
		throw GradeTooLowException(Bcrat.getName() + " grade is too low to sign the form!\n");
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (!this->_signed)
	{
		throw FormNotSigned(getName() + ": This form has not been signed yet!");
		return;
	}
	if (executor.getGrade() <= this->_gradeToExec)
		executeAction();
	else
		throw GradeTooLowException("Bureaucrat grade is too low to execute this form!");
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
	os << "AForm :" << obj.getName() << "grades are:\n" << "Execution grade: " << obj.getGradeToExec() << std::endl <<\
	"Signing grade: " << obj.getGradeToSign() << std::endl;
	return (os);
}