/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:24:49 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/31 17:07:54 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"


int main()
{
    std::cout << "=== TEST CATTIVO: FragTrap (esaustivo, borderline) ===\n\n";

    std::cout << "-- Costruzione / copia / assegnazione --\n";
    FragTrap f1("Fraggy");
    FragTrap f2(f1);               // copy ctor
    FragTrap assigned("Tmp");
    assigned = f1;                 // operator=
    // assigned = assigned;           // self-assign (should be safe)

    std::cout << "\n-- Funzione unica: highFivesGuys() --\n";
    f1.highFivesGuys();            // comportamento normale

    std::cout << "\n-- Attacchi ripetuti per stressare energia --\n";
    for (int i = 0; i < 52; ++i)   // numero volutamente grande per consumare EP
        f1.attack("the stubborn dummy");

    std::cout << "\n-- Danni progressivi e casi limite --\n";
    f1.takeDamage(2);
    f1.takeDamage(5);
    f1.takeDamage(1000);           // danno enorme -> HP a 0 senza underflow
    f1.attack("after fatal blow"); // non dovrebbe attaccare se HP == 0
    f1.highFivesGuys();            // comportamento quando HP==0 (se gestito)

    std::cout << "\n-- Tentativi di riparazione in condizioni avverse --\n";
    f1.beRepaired(5);              // se HP==0 o energia insufficiente, non deve funzionare

    std::cout << "\n-- Ripristino su nuovo oggetto e test overflow di riparazione --\n";
    FragTrap healer("HealerFrag");
    healer.beRepaired(2);
    healer.beRepaired(1000);       // non dovrebbe superare il max HP (se implementato)

    std::cout << "\n-- Stress test parallelo con scope (distruttori) --\n";
    {
        FragTrap swarm[3] = { FragTrap("A"), FragTrap("B"), FragTrap("C") };
        for (int i = 0; i < 10; ++i) {
            swarm[i % 3].attack("swarm target");
            swarm[i % 3].highFivesGuys();
        }
    } // distruttori obbligati qui

    std::cout << "\n-- Test combinati con takeDamage/beRepaired loop --\n";
    FragTrap loop("Looper");
    for (int i = 0; i < 20; ++i) {
        if (i % 3 == 0) loop.attack("combo target");
        if (i % 5 == 0) loop.takeDamage(3);
        if (i % 7 == 0) loop.beRepaired(2);
    }

    std::cout << "\n=== FINE TEST CATTIVO FragTrap ===\n";
    return 0;
}