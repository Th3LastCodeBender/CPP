/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:54:22 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/29 17:47:41 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define 	SHRUBBERYCREATIONFORM_HPP

#include "eader.h"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		
		const std::string	_target;
	
	public:
		
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
		~ShrubberyCreationForm();

		const std::string	getTarget() const;
		void				executeAction();
};

#endif
