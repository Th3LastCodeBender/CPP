/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:47:50 by lparolis          #+#    #+#             */
/*   Updated: 2025/11/29 16:18:29 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
//	Bureaucrat	giorgio("giorgio", 75);
//	Form		pulizia_etnica("pulizia_etnica", 73, 75);

	Bureaucrat	giorgio("giorgio", 75);
	Form		pulizia_etnica("pulizia_etnica", 73, 75);
   
   giorgio.signForm(pulizia_etnica);
   
   return 0;
}