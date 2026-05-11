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

void separator(std::string title)
{
    std::cout << "\n====================================\n";
    std::cout << title << std::endl;
    std::cout << "====================================\n";
}

int main()
{
    separator("CANONICAL FORM TEST");

    ClapTrap original("CL4P");
    ClapTrap copy(original);
    ClapTrap assigned("TEMP");

    assigned = original;

    std::cout << "\n*** EXPECTED : copy constructor + copy assignment called ***\n";

    separator("CLAPTRAP TEST");

    ClapTrap clap("BASIC");

    std::cout << "\n[Initial ClapTrap Tests]\n";

    std::cout << "*** EXPECTED : attack does 0 damage, reduce EP [1] ***\n";
    clap.attack("training dummy");

    std::cout << "*** Current Status: ***\n";
    clap.beRepaired(0);

    std::cout << "*** EXPECTED : BASIC takes damage[5], HP reduced ***\n";
    clap.takeDamage(5);

    std::cout << "*** Current Status: ***\n";
    clap.beRepaired(0);

    std::cout << "*** EXPECTED : HP repaired[3], reduce EP [1] ***\n";
    clap.beRepaired(3);

    separator("ENERGY DEPLETION TEST");
    std::cout << "*** Current Status: ***\n";
    clap.beRepaired(0);
    std::cout << "*** EXPECTED : BASIC eventually runs out of energy ***\n";

    for (int i = 0; i < 8; i++)
    {
        clap.attack("wall");
        clap.beRepaired(0);
    }

    std::cout << "*** EXPECTED : try to attack but cannot, no EP left ***\n";
    clap.attack("last wall");

    std::cout << "*** EXPECTED : try to repair but cannot, no EP left ***\n";
    clap.beRepaired(1);

    separator("DEATH TEST");

    ClapTrap doomed("DOOM");

    std::cout << "*** EXPECTED : try takeDamage [20]. HP gets set to  [0] ***\n";
    doomed.takeDamage(20);

    std::cout << "*** EXPECTED : cannot attack because dead ***\n";
    doomed.attack("ghost");

    std::cout << "*** EXPECTED : cannot repair because dead ***\n";
    doomed.beRepaired(5);

    separator("DESTRUCTOR TEST");

    std::cout << "*** EXPECTED : destructors called in reverse order ***\n";

    return 0;
}