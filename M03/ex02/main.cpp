#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void separator(std::string title)
{
    std::cout << "\n====================================\n";
    std::cout << title << std::endl;
    std::cout << "====================================\n";
}

    // A function that only knows about the base class
void fieldRepair(ClapTrap &target) 
{
    std::cout << "Repairs [5] from the base class: " << std::endl;
    target.beRepaired(5); 
}

int main()
{
    separator("CLAPTRAP TEST");

    ClapTrap clap("CL4P");

    std::cout << "\n[Initial ClapTrap Tests]" << std::endl;

    std::cout << "*** EXPECTED : attack does 0 damage, reduce EP [1] ***\n";
    clap.attack("target dummy");
    std::cout << "*** Current Status: ***\n";
    clap.beRepaired(0); //this helps output current status

    std::cout << "*** EXPECTED : CL4P takes damage[5], HP reduced then repaired[3]\n";
    clap.takeDamage(5);
    std::cout << "*** Current Status: ***\n";
    clap.beRepaired(0); //this helps output current status

    std::cout << "*** Expected :  HP repaired[3]\n";
    clap.beRepaired(3);

    separator("SCAVTRAP TEST");

    ScavTrap scav("SC4V");

    std::cout << "\n[Initial ScavTrap Tests]" << std::endl;

    std::cout << "*** EXPECTED : attack does damage[20], reduce EP [1] ***\n";
    scav.attack("intruder");
    std::cout << "*** Current Status: ***\n";
    scav.beRepaired(0);

    std::cout << "*** EXPECTED : SC4V takes damage[40], HP reduced ***\n";
    scav.takeDamage(40);
    std::cout << "*** Current Status: ***\n";
    scav.beRepaired(0);

    std::cout << "*** EXPECTED : HP repaired[20], reduce EP [1] ***\n";
    scav.beRepaired(20);

    std::cout << "*** EXPECTED : guardGate special ability message ***\n";
    scav.guardGate();
    std::cout << "*** Current Status: ***\n";
    scav.beRepaired(0);

    std::cout << "*** EXPECTED : SC4V takes massive damage[200], HP becomes 0 ***\n";
    scav.takeDamage(200);
    std::cout << "*** Current Status: ***\n";
    scav.beRepaired(0);

    std::cout << "*** EXPECTED : cannot attack because HP = 0 ***\n";
    scav.attack("ghost");

    std::cout << "*** EXPECTED : try to repair, cannot repair because HP = 0 ***\n";
    scav.beRepaired(10);

    separator("FRAGTRAP TEST");

    FragTrap frag("FR4G");

    std::cout << "\n[Initial FragTrap Tests]" << std::endl;

    std::cout << "*** EXPECTED : attack does damage[30], reduce EP [1] ***\n";
    frag.attack("enemy bot");
    std::cout << "*** Current Status: ***\n";
    frag.beRepaired(0);

    std::cout << "*** EXPECTED : FR4G takes damage[42], HP reduced ***\n";
    frag.takeDamage(42);
    std::cout << "*** Current Status: ***\n";
    frag.beRepaired(0);

    std::cout << "*** EXPECTED : HP repaired[25], reduce EP [1] ***\n";
    frag.beRepaired(25);

    std::cout << "*** EXPECTED : high five special message ***\n";
    frag.highFivesGuys();
    std::cout << "*** Current Status: ***\n";
    frag.beRepaired(0);

    std::cout << "*** EXPECTED : EP reduced after multiple attacks ***\n";

    for (int i = 0; i < 5; i++)
        frag.attack("training dummy");

    std::cout << "*** Current Status: ***\n";
    frag.beRepaired(0);

    std::cout << "*** EXPECTED : FR4G takes massive damage[150], HP becomes 0 ***\n";
    frag.takeDamage(150);
    std::cout << "*** Current Status: ***\n";
    frag.beRepaired(0);

    std::cout << "*** EXPECTED : cannot attack because HP = 0 ***\n";
    frag.attack("final boss");

    std::cout << "*** EXPECTED : cannot repair because HP = 0 ***\n";
    frag.beRepaired(50);

    std::cout << "*** EXPECTED : highFivesGuys called but dead ***\n";
    frag.highFivesGuys();

    separator("INHERITANCE COMPARISON");

    std::cout << "*** EXPECTED : ClapTrap weakest attack [0 damage] ***\n";
    clap.attack("enemy");

    std::cout << "*** EXPECTED : ScavTrap stronger attack [20 damage] ***\n";
    scav.attack("enemy");

    std::cout << "*** EXPECTED : FragTrap strongest attack [30 damage] ***\n";
    frag.attack("enemy");



    //add test
    separator("POLYMORPHISM TEST");

    std::cout << "*** EXPECTED : Base function repairs on FragTrap class ***" << std::endl;
    FragTrap polyFrag("PolyFrag");

    std::cout << "*** Current Status:  PolyFrag ***\n";
    polyFrag.beRepaired(0); //this helps output current status
    fieldRepair(polyFrag); // Passing a FragTrap to a ClapTrap reference
    std::cout << "*** Current Status:  PolyFrag (after repair) ***\n";
    polyFrag.beRepaired(0);

    std::cout << "*** EXPECTED : Base function repairs base class ***" << std::endl;
    std::cout << "*** Current Status:  CL4P ***\n";
    clap.beRepaired(0);
    fieldRepair(clap);
    std::cout << "*** Current Status:  CL4P (after repair) ***\n";
    clap.beRepaired(0);

    std::cout << "*** EXPECTED : Base function repairs on ScavTrap class ***" << std::endl;
    ScavTrap polyScav("PolyScav");

    std::cout << "*** Current Status:  PolyScav ***\n";
    polyScav.beRepaired(0); //this helps output current status
    fieldRepair(polyScav); // Passing a FragTrap to a ClapTrap reference


    separator("DESTRUCTOR TEST");

    std::cout << "*** EXPECTED : derived destructors called before ClapTrap destructor ***\n";

    return 0;
}