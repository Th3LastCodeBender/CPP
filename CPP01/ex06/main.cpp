/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:33:29 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/03 12:17:50 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eader.h"
#include "Harl.hpp"

int main ( int argc, char **argv )
{
	Harl scassacazzi;
	
	if (argc < 2)
	{
		std::cout << "Belin che affare, ma li sai passare gli argomenti ad un programma o l'unica cosa che hai passato era la giornata in cui hanno pubblicato l'aggiornamento per farti funzionare il cervello?" << std::endl;
		return (0);
	}
	scassacazzi.complain(argv[1]);
	// scassacazzi.complain("info");
	// scassacazzi.complain("warning");
	// scassacazzi.complain("error");
	// scassacazzi.complain("tuamadre");
	// scassacazzi.complain("");
	// scassacazzi.complain(" ");
}