/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:29:57 by ssukhija          #+#    #+#             */
/*   Updated: 2026/03/23 12:29:57 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() 
{
    std::cout << "Zombie created\n";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "Zombie : " << this->name << " created\n";
}

Zombie::~Zombie()
{
    std::cout << "Zombie : " << this->name << " is destroyed\n";
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}
