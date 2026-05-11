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

#include "DiamondTrap.hpp"

void separator(std::string title)
{
    std::cout << "\n====================================\n";
    std::cout << title << std::endl;
    std::cout << "====================================\n";
}

int main()
{
    separator("DIAMONDTRAP CONSTRUCTION");

    std::cout << "*** EXPECTED : Clap(once) -> Frag -> Scav -> Diamond ***" << std::endl;
    DiamondTrap monster("DI4-M0ND");

    separator("IDENTITY AND ATTRIBUTES");

    std::cout << "*** EXPECTED : Both names (DI4-M0ND and DI4-M0ND_clap_name) ***" << std::endl;
    monster.whoAmI();

    std::cout << "\n*** EXPECTED stats: HP[100](Frag), EP[50](Scav), AD[30](Frag) ***" << std::endl;
    monster.beRepaired(0);

    separator("DIAMOND ACTION TEST");

    std::cout << "*** EXPECTED : ScavTrap attack message (ferociously) but FragTrap damage (30) ***" << std::endl;
    monster.attack("a challenger");

    std::cout << "\n*** EXPECTED : Access to FragTrap special ability ***" << std::endl;
    monster.highFivesGuys();

    std::cout << "\n*** EXPECTED : Access to ScavTrap special ability ***" << std::endl;
    monster.guardGate();

    separator("CANONICAL FORM (DIAMOND)");

    std::cout << "Creating a clone of the monster..." << std::endl;
    DiamondTrap clone(monster);
    clone.whoAmI();

    std::cout << "\n*** EXPECTED : Independence Test (Original takes damage, Clone stays healthy) ***" << std::endl;
    monster.takeDamage(50);
    
    std::cout << "--- Status: Original ---" << std::endl;
    monster.beRepaired(0);
    std::cout << "--- Status: Clone ---" << std::endl;
    clone.beRepaired(0);

    separator("DIAMOND SLICING / POLYMORPHISM");

    std::cout << "*** EXPECTED : Treat Diamond as its grandparents and parents ***" << std::endl;
    
    ClapTrap &baseRef = monster;
    FragTrap &fragRef = monster;
    ScavTrap &scavRef = monster;

    std::cout << "Calling beRepaired via ClapTrap reference:" << std::endl;
    baseRef.beRepaired(10);

    std::cout << "Calling highFivesGuys via FragTrap reference:" << std::endl;
    fragRef.highFivesGuys();

    std::cout << "Calling guardGate via ScavTrap reference:" << std::endl;
    scavRef.guardGate();

    separator("DESTRUCTOR TEST");
    std::cout << "*** EXPECTED : Diamond -> Scav -> Frag -> Clap ***" << std::endl;

    return 0;
}