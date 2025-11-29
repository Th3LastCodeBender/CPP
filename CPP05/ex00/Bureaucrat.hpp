/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:39:35 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/29 15:01:46 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define		BUREAUCRAT_HPP

#include "eader.h"

class Bureaucrat
{
	private:

		const std::string	name;
		int					grade;

	public:	

		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		~Bureaucrat();
		
		const std::string			getName() const;
		int							getGrade() const;
		void						incrementGrade();
		void						decrementGrade();
	
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