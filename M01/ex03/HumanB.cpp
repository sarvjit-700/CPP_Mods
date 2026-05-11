/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:44:53 by ssukhija          #+#    #+#             */
/*   Updated: 2026/03/26 14:44:53 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
    std::cout << "HumanB " << name 
            << " created with no weapon" << std::endl;
}
HumanB::~HumanB()
{
    std::cout << "HumanB " << this->name << " destroyed" << std::endl;
}

void    HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void    HumanB::attack(void)
{
    if (weapon)
    {
        std::cout << this->name << " attacks with their " 
            << this->weapon->getType() << std::endl;
    }
    else
        std::cout << this->name << " is unarmed" << std::endl;
}