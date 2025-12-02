/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:45:22 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/02 17:00:39 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(75)
{
	DBG_MSG("Bureaucrat constructor called");
}

Bureaucrat::Bureaucrat(int grade) : _name("default"), _grade(grade)
{
	DBG_MSG("Bureaucrat constructor called");

	if (this->_grade < 1)
		throw std::out_of_range(this->_name + " Grade is too high!\n");
	if(this->_grade > 150)
		throw std::out_of_range(this->_name + " Grade is too low!\n");
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	DBG_MSG("Bureaucrat constructor called");
	this->_grade = grade;

	if (name.empty())
		throw std::out_of_range("empty name brotha!\n");
	if (this->_grade < 1)
		throw std::out_of_range(name + " Grade is too high!\n");
	if(this->_grade > 150)
		throw std::out_of_range(name + " Grade is too low!\n");
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj.getName())
{
	DBG_MSG("Bureaucrat copy constructor called");
	this->_grade = obj.getGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	DBG_MSG("Bureaucrat copy operator called");
	this->_grade = obj.getGrade();

	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	DBG_MSG("Bureaucrat destructor called");
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

void	Bureaucrat::incrementGrade()
{
	this->_grade--;
	if (this->_grade < 1)
		throw std::out_of_range(this->_name + " Post-increment grade is too high!\n");
	if(this->_grade > 150)
		throw std::out_of_range(this->_name + " Post-increment grade is too low! (wut?)\n");
}

void	Bureaucrat::decrementGrade()
{
	this->_grade++;
	if (this->_grade < 1)
		throw std::out_of_range(this->_name + " Post-decrement grade is too high! (wut?)\n");
	if(this->_grade > 150)
		throw std::out_of_range(this->_name + " Post-decrement grade is too low!\n");
}

void	Bureaucrat::signForm(AForm &formToSign) const
{
	try 
	{
		formToSign.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cout << this->_name <<  " couldn’t sign " << formToSign.getName() << " because " << e.what();
		return;
	}
	std::cout << this->_name << " signed " << formToSign.getName() << std::endl;
}

void	Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	std::cout << this->_name << " executed " << form.getName() << std::endl;
	
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}