/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:24:49 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/31 16:32:18 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"


int main()
{
    std::cout << "=== TEST CATTIVO: ClapTrap / ScavTrap ===\n\n";

    std::cout << "-- Costruzione e copia/assegnazione --\n";
    ClapTrap a("Alpha");
    ClapTrap b("Beta");
    ClapTrap a_copy(a);            // copy ctor
    ClapTrap assigned("Tmp");
    assigned = b;                  // operator=
    // assigned = assigned;           // self-assign (should be safe)

    std::cout << "\n-- Attacchi ripetitivi per esaurire energia --\n";
    for (int i = 0; i < 52; ++i)   // oltre l'energia prevista
        a.attack("the relentless target");

    std::cout << "\n-- Danni progressivi e caso fatale --\n";
    a.takeDamage(30);
    a.takeDamage(40);
    a.takeDamage(100);              // probabile set HP a 0
    a.attack("after fatal blow");  // non dovrebbe attaccare se HP == 0

    std::cout << "\n-- Tentativi di riparazione in condizioni avverse --\n";
    a.beRepaired(5);               // se HP == 0 non dovrebbe riparare
    // ricrea un oggetto per testare riparazione con energia insufficiente
    ClapTrap fragile("Fragile");
    // scarica energia
    for (int i = 0; i < 52; ++i)
        fragile.attack("drain");
    fragile.beRepaired(3);         // energia 0 -> non può riparare

    std::cout << "\n-- Test bordo: danno enorme e riparazione eccessiva --\n";
    ClapTrap tank("Tank");
    tank.takeDamage(1000);         // deve portare HP a 0 senza underflow
    tank.beRepaired(1000);         // se distrutto non può riparare
    // nuovo oggetto per testare cap max HP (se implementato)
    ClapTrap healer("Healer");
    healer.beRepaired(5);
    healer.beRepaired(100);        // non deve superare max HP

    std::cout << "\n-- ScavTrap: costruttore, attack e guardGate --\n";
    ScavTrap s1("Scavvy");
    ScavTrap s2(s1);               // copy ctor
    s2 = s1;                       // operator=
    s1.attack("an unlucky dummy");
    s1.guardGate();

    std::cout << "\n-- ScavTrap stress: esaurimento e attacchi su 0 HP --\n";
    // esaurisci energia di s1
    for (int i = 0; i < 20; ++i)
        s1.attack("repeat target");
    s1.takeDamage(9999);           // distruggi
    s1.attack("should not work");

    std::cout << "\n-- Scope e distruttori (verifica chiamate) --\n";
    {
        ScavTrap temp("TempGuard");
        temp.guardGate();
        temp.attack("ephemeral");
    } // distruttore chiamato qui

    std::cout << "\n=== FINE TEST CATTIVO ===\n";
    return 0;
}

// int main()
// {
//    ClapTrap giorgino("giorgino");
//    ScavTrap gianmarco("gianmarco");
   
//    giorgino.attack("il nonno");
//    gianmarco.attack("la nonna");
//    return 0;
// }