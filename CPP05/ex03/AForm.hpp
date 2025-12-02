/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:43:02 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/29 17:04:24 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define 	AFORM_HPP

#include "eader.h"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:

		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:

		AForm();
		AForm(int gradeToSign, int gradeToExec);
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm &obj);
		AForm &operator=(const AForm &obj);
		virtual ~AForm();
	
		const std::string	getName() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
		bool				getSignature() const;
		void				beSigned(const Bureaucrat &Bcrat);
		void				execute(const Bureaucrat &executor) const;
		virtual void		executeAction() const = 0;

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
		
		class FormNotSigned : public std::exception
		{
			private:
				std::string _msg;
			public:
				FormNotSigned(std::string msg) : _msg(msg) {};
				virtual const char *what() const throw() {return (this->_msg.c_str());};
				~FormNotSigned() throw() {};
		};

		class FileNotCreated : public std::exception
		{
			private:
				std::string _msg;
			public:
				FileNotCreated(std::string msg) : _msg(msg) {};
				virtual const char *what() const throw() {return (this->_msg.c_str());};
				~FileNotCreated() throw() {};
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);

#endif
