/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:54:19 by lparolis          #+#    #+#             */
/*   Updated: 2025/12/02 17:17:39 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define 	ROBOTOMYREQUESTFORM_HPP

#include "eader.h"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		
		const std::string	_target;
	
	public:
		
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
		~RobotomyRequestForm();
		
		const std::string	getTarget() const;
		void				executeAction() const;
};

#endif
