/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:43:02 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/29 16:13:43 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define 	FORM_HPP

#include "eader.h"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:

		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:

		Form();
		Form(int gradeToSign, int gradeToExec);
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form &obj);
		Form &operator=(const Form &obj);
		~Form();
	
		const std::string	getName() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
		bool				getSignature() const;
		void				beSigned(const Bureaucrat Bcrat);

		class GradeTooHighException : public std::exception
		{
			private:
				std::string _msg;
			public:
				GradeTooHighException(std::string msg) : _msg(msg) {};
				virtual const char *what() const throw() {return (this->_msg.c_str());};
				~GradeTooHighException() throw() {};
		};
		
		class GradeTooLowException : public std::exception
		{
			private:
				std::string _msg;
			public:
				GradeTooLowException(std::string msg) : _msg(msg) {};
				virtual const char *what() const throw() {return (this->_msg.c_str());};
				~GradeTooLowException() throw() {};
		};
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif
