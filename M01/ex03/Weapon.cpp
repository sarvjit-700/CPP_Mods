/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:44:55 by ssukhija          #+#    #+#             */
/*   Updated: 2026/03/26 14:44:55 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}
Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon(){}

void    Weapon::setType(std::string type)
{
    this->type = type;
}

const std::string& Weapon::getType() const
{
    return (this->type);
}
