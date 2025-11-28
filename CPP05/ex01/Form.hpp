/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:04:33 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/18 16:29:05 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define 	FORM_HPP

#include "Bureaucrat.hpp"
#include "eader.h"

class Form
{
	private:
		
		const std::string	name;
		bool				formSigned;
		const int			gradeToSign;
		const int			gradeToExec;
	
	public:

		Form();
		Form(std::string name);
		Form(std::string name, int gradeToSign);
		Form(std::string, int gradeToSign, int gradeToExec);
		Form(const Form &obj);
		Form &operator=(const Form &obj);
		~Form();

		std::string getName();
		bool		getStatus();
		int 		getGradeToSign();
		int 		getGradeToExec();
		void		beSigned();
		void		signForm();
		
		friend	std::ostream &operator<<(std::ostream &os, const Form &obj);
};

#endif