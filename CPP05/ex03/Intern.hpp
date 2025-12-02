/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:19:19 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/02 19:00:47 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define 	INTERN_HPP

#include "eader.h"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
	private:

		std::string which_one[3];
		
	public:
	
		Intern();
		Intern(const Intern &obj);
		Intern &operator=(const Intern &obj);
		~Intern();

		AForm *makeForm(std::string formName, std::string target);

		class WrongFormTypedef : public std::exception
		{
			private:
				std::string _msg;
			public:
				WrongFormTypedef(std::string msg) : _msg(msg) {};
				virtual const char *what() const throw() {return (_msg.c_str());}
				~WrongFormTypedef() throw() {};
		};
};

#endif
