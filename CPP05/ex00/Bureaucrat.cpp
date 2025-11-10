/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:45:22 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/10 19:00:19 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(75)
{
	DBG_MSG("Bureaucrat constructor called");
}

Bureaucrat::Bureaucrat(int grade) : name("default"), grade(grade)
{
	DBG_MSG("Bureaucrat constructor called");

	if (this->grade < 1)
		throw std::out_of_range(name + " Grade is too high!\n");
	if(this->grade > 150)
		throw std::out_of_range(name + " Grade is too low!\n");
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	DBG_MSG("Bureaucrat constructor called");
	this->grade = grade;

	if (name.empty())
		throw std::out_of_range("empty name brotha!\n");
	if (this->grade < 1)
		throw std::out_of_range(name + " Grade is too high!\n");
	if(this->grade > 150)
		throw std::out_of_range(name + " Grade is too low!\n");
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	DBG_MSG("Bureaucrat copy constructor called");
	this->grade = obj.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	DBG_MSG("Bureaucrat copy operator called");
	this->grade = obj.grade;

	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	DBG_MSG("Bureaucrat destructor called");
}

int	Bureaucrat::getGrade()
{
	return (this->grade);
}

std::string	Bureaucrat::getName()
{
	return (this->name);
}

void	Bureaucrat::incrementGrade()
{
	this->grade--;
	if (this->grade < 1)
		throw std::out_of_range(name + " Post-increment grade is too high!\n");
	if(this->grade > 150)
		throw std::out_of_range(name + " Post-increment grade is too low! (wut?)\n");
}

void	Bureaucrat::decrementGrade()
{
	this->grade++;
	if (this->grade < 1)
		throw std::out_of_range(name + " Post-decrement grade is too high! (wut?)\n");
	if(this->grade > 150)
		throw std::out_of_range(name + " Post-decrement grade is too low!\n");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.name << ", bureaucrat grade " << obj.grade << ".";
	return (os);
}