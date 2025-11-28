/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:25:13 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/18 16:29:45 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), formSigned(false), gradeToExec(75), gradeToSign(75)
{	
	DBG_MSG("Form Constructor called!");
}

Form::Form(std::string name)
{
	
}

