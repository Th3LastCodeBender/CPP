/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:54:15 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/29 18:07:07 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define 	PRESIDENTIALPARDONFORM_HPP

#include "eader.h"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		
		const std::string	_target;
	
	public:
		
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
		~PresidentialPardonForm();

		const std::string	getTarget() const;
		void				executeAction();
};
#endif
