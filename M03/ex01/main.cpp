/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:01:50 by ssukhija          #+#    #+#             */
/*   Updated: 2026/04/07 19:01:50 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void separator(std::string title)
{
    std::cout << "\n====================================\n";
    std::cout << title << std::endl;
    std::cout << "====================================\n";
}

int main()
{
    separator("CLAPTRAP VS SCAVTRAP");

    ClapTrap clap("CL4P");
    std::cout << "Now create a SCAVTRAP: " << std::endl;
    ScavTrap scav("SC4V");

    std::cout << "\n*** EXPECTED : ClapTrap attack [0] damage] ***\n";
    clap.attack("enemy");

    std::cout << "*** Current Status: ***\n";
    clap.beRepaired(0);

    std::cout << "\n*** EXPECTED : ScavTrap stronger overridden attack [20] damage ***\n";
    scav.attack("enemy");

    std::cout << "*** Current Status: ***\n";
    scav.beRepaired(0);

    separator("SCAVTRAP SPECIAL TEST");

    std::cout << "*** EXPECTED : guardGate mode message ***\n";
    scav.guardGate();

    separator("SCAVTRAP DAMAGE TEST");

    std::cout << "*** EXPECTED : SC4V takes damage[40] ***\n";
    scav.takeDamage(40);

    std::cout << "*** Current Status: ***\n";
    scav.beRepaired(0);

    std::cout << "*** EXPECTED : HP repaired[20], reduce EP [1] ***\n";
    scav.beRepaired(20);

    separator("SCAVTRAP ENERGY DEPLETION");

    std::cout << "*** EXPECTED : SC4V eventually runs out of EP ***\n";
    std::cout << "*** EXPECTED : SC4V will FEROCIOUSLY ATTACK, therefore using its own attack ***\n" << std::endl;

    for (int i = 0; i < 49; i++)
        scav.attack("training bot");

    std::cout << "*** EXPECTED : cannot attack, no EP left ***\n";
    scav.attack("last target");

    std::cout << "*** EXPECTED : cannot repair, no EP left ***\n";
    scav.beRepaired(1);

    separator("SCAVTRAP DEATH TEST");

    std::cout << "*** Current Status: ***\n";
    scav.beRepaired(0);
    std::cout << "*** EXPECTED : take damage [200] will result HP [0] ***\n";
    scav.takeDamage(200);

    std::cout << "*** Current Status: ***\n";
    scav.beRepaired(0);
    std::cout << "*** EXPECTED : take damage [10] but already dead. ***\n";
    scav.takeDamage(200);

    std::cout << "*** EXPECTED : cannot attack because dead ***\n";
    scav.attack("ghost");

    std::cout << "*** EXPECTED : guardGate blocked because dead ***\n";
    scav.guardGate();

    std::cout << "*** EXPECTED : cannot repair because dead ***\n";
    scav.beRepaired(5);
//-- added tests
    separator("CANONICAL INDEPENDENCE TEST");

    std::cout << "Creating 'Original' ScavTrap..." << std::endl;
    ScavTrap original("Original");
    
    std::cout << "\n*** EXPECTED : ScavTrap Copy constructor called ***" << std::endl;
    ScavTrap clone(original);

    std::cout << "\n*** EXPECTED : Original takes 50 damage, Clone remains at 100 HP ***" << std::endl;
    original.takeDamage(50);

    std::cout << "--- Status: Original ---" << std::endl;
    original.beRepaired(0);
    
    std::cout << "--- Status: Clone ---" << std::endl;
    clone.beRepaired(0);

    separator("POINTER / REFERENCE SLICING TEST");

    std::cout << "*** EXPECTED : A ClapTrap reference can point to a ScavTrap ***" << std::endl;
    // ClapTrap &slicingRef = original; does not change any data. It simply tells the compiler: 
    //"Look at the memory location of original, but only use the 'instruction manual' for a ClapTrap". 
    // When you call slicingRef.attack(), the ClapTrap manual says: "Print the message 'ClapTrap...' 
    //and then look in the memory box labeled _attackDamage to see what number is there".
    
    ClapTrap &slicingRef = original;
    std::cout << "--- Status: Original ---" << std::endl;
    slicingRef.beRepaired(0);
    slicingRef.attack("the Slicing Dummy");

    std::cout << "\n*** EXPECTED : Calling status via Base reference still shows Scav stats ***" << std::endl;
    slicingRef.beRepaired(0);

    separator("DESTRUCTOR TEST");

    std::cout << "*** EXPECTED : ScavTrap destructor before ClapTrap destructor ***\n";

    return 0;
}