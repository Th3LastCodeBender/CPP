/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:39:35 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/10 17:22:07 by lparolis         ###   ########.fr       */
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
		
		std::string			getName();
		int					getGrade();
		void				incrementGrade();
		void				decrementGrade();
		friend std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);
		
};

#endif