/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:33:29 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/02 17:40:22 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"
#include "Harl.hpp"

int main ( void )
{
	Harl scassacazzi;
	
	scassacazzi.complain("debug");
	scassacazzi.complain("info");
	scassacazzi.complain("warning");
	scassacazzi.complain("error");
	scassacazzi.complain("tuamadre");
	scassacazzi.complain("");
	scassacazzi.complain(" ");
}