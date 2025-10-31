/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:24:49 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/31 16:41:24 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

// int main()
// {
//     std::cout << "=== INELUTTABILE TEST: ClapTrap ===\n\n";

//     ClapTrap crusher("CRUSHER");
//     ClapTrap copyCrusher = crusher;       // copy ctor
//     ClapTrap victim("VICTIM");
//     copyCrusher = victim;                 // operator=

//     std::cout << "\n--- Scarica energetica (attacchi continui) ---\n";
//     // 12 attacchi per spingere l'energia sotto zero (start 10)
//     for (int i = 1; i <= 12; ++i)
//         crusher.attack("un povero bersaglio");

//     std::cout << "\n--- Danni progressivi ---\n";
//     crusher.takeDamage(3);  // parziale
//     crusher.takeDamage(4);  // ancora
//     crusher.takeDamage(10); // colpo fatale probabile

//     std::cout << "\n--- Tentativi di riparazione ---\n";
//     // prova a riparare quando magari manca l'energia o i punti vita sono 0
//     crusher.beRepaired(5);
//     crusher.beRepaired(20);

//     std::cout << "\n--- Test estremi ---\n";
//     ClapTrap fragile("FRAGILE");
//     fragile.takeDamage(1000);   // danno enorme
//     fragile.beRepaired(1);      // tentativo di riparazione

//     std::cout << "\n--- Scope destructor test ---\n";
//     {
//         ClapTrap ephemeral("EPHEMERAL");
//         ephemeral.attack("qualsiasi cosa");
//     } // distruzione obbligata appena esce dallo scope

//     std::cout << "\n=== FINE DELLA DISTRUZIONE ===\n";
//     return 0;
// }

int main()
{
    ClapTrap s1("giorgio");

    s1.beRepaired(10);
    return (0);
}