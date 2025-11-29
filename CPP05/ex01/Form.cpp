/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:42:44 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/29 16:17:39 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _gradeToSign(75), _gradeToExec(75)
{
	DBG_MSG("Form constructor called");
}

Form::Form(int gradeToSign, int gradeToExec) : _name("default"), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	DBG_MSG("Form constructor called");

	if (this->_gradeToExec < 1)
		throw GradeTooHighException(_name + " _gradeToExec is too high!\n");
	if (this->_gradeToSign < 1)
		throw GradeTooHighException(_name + "_gradeToSign is too high!\n");
	
	if(this->_gradeToExec > 150)
		throw GradeTooLowException(_name + " _gradeToExec is too low!\n");
	if(this->_gradeToSign > 150)
		throw GradeTooLowException(_name + " _gradeToSign is too low!\n");
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	DBG_MSG("Form constructor called");
	
	if (this->_gradeToExec < 1)
		throw GradeTooHighException(_name + " _gradeToExec is too high!\n");
	if (this->_gradeToSign < 1)
		throw GradeTooHighException(_name + "_gradeToSign is too high!\n");
	
	if(this->_gradeToExec > 150)
		throw GradeTooLowException(_name + " _gradeToExec is too low!\n");
	if(this->_gradeToSign > 150)
		throw GradeTooLowException(_name + " _gradeToSign is too low!\n");
}

Form::Form(const Form &obj) : _name(obj.getName()), _gradeToSign(obj.getGradeToSign()), _gradeToExec(obj.getGradeToExec())
{
	DBG_MSG("Copy constructor called!");
}

Form &Form::operator=(const Form &obj) //: _name(obj.getName()), _gradeToExec(obj.getGradeToExec()), _gradeToSign(obj.getGradeToSign())
{
	DBG_MSG("Copy operator called!");
	(void)obj;
	// Form copy(obj);
	// return (copy);
	return(*this);
}

Form::~Form()
{
	DBG_MSG("From destructor called!");
}

const std::string  Form::getName() const
{
	return (this->_name);
}

int	Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

bool	Form::getSignature() const
{
	return (this->_signed);
}

void	Form::beSigned(const Bureaucrat Bcrat)
{
	if (Bcrat.getGrade() <= this->getGradeToSign())
		this->_signed = true;
	else
		throw GradeTooLowException(Bcrat.getName() + " grade is too low to sign the form!\n");
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << "Form :" << obj.getName() << "grades are:\n" << "Execution grade: " << obj.getGradeToExec() << std::endl <<\
	"Signing grade: " << obj.getGradeToSign() << std::endl;
	return (os);
}