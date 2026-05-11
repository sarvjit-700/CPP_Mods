/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 21:48:32 by ssukhija          #+#    #+#             */
/*   Updated: 2026/04/23 21:48:32 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
// #include "FragTrap.hpp"
// #include "ScavTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap()
{
    this->_name = "Default";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DT Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) 
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    this->_name = name;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DT Name constructor called for " << name << std::endl;

}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    this->_name = other._name;
    std::cout << "DT Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->ClapTrap::_name = other.ClapTrap::_name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << this->_name << " Diamond Destructor called" << std::endl;
}

void    DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap: " << this->_name 
            << " and my ClapTrap name is: " << ClapTrap::_name 
            << std::endl; 
}
