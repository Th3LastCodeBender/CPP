/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:39:35 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/02 15:39:05 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define		BUREAUCRAT_HPP

#include "eader.h"
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:

		const std::string	_name;
		int					_grade;

	public:	

		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		~Bureaucrat();
		
		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm &formToSign) const;
		void				executeForm(const AForm &form) const;
		
		class GradeTooHighException : public std::exception
		{
			private:
				std::string _msg;
			public:
				GradeTooHighException(std::string msg) : _msg(msg) {};
				virtual const char *what() const throw() {return (_msg.c_str());}
				~GradeTooHighException() throw() {};
		};
	
		class GradeTooLowException : public std::exception
		{
			private:
				std::string _msg;
			public:
				GradeTooLowException(std::string msg) : _msg(msg) {};
				virtual const char *what() const throw() {return (_msg.c_str());}
				~GradeTooLowException() throw() {};
		};
		
	};
	
std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif