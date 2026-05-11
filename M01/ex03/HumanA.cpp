/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:44:45 by ssukhija          #+#    #+#             */
/*   Updated: 2026/03/26 14:44:45 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
    : name(name), weapon(weapon) 
{
    std::cout << "HumanA " << name << " created with "
            << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "HumanA " << this->name << " destroyed" << std::endl;
}

void    HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " 
            << this->weapon.getType() << std::endl; 
}