/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 16:35:10 by ssukhija          #+#    #+#             */
/*   Updated: 2026/04/12 16:35:10 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage =20;
    std::cout << "ScavT Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage =20;
    std::cout << "ScavT Name constructor called for " << name
        << "\n--starts with hitPoints[100], energyPoints[50], attackDamage[20]" 
        << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << this->_name << " ScavTrap Destructor called" << std::endl;
}

void    ScavTrap::attack(const std::string &target)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        this->_energyPoints--;
        std::cout << "ScavTrap " << this->_name << " ferociously attacks " << target 
                << ", causing " << this->_attackDamage << " points of damage!"
                << std::endl;
    }
    else if (!this->_hitPoints)
        std::cout << "ScavTrap " << this->_name 
                << " is unable to attack, no HP!" << std::endl;
    else
        std::cout << "ScavTrap " << this->_name 
                << " is unable to attack, no EP!" << std::endl;
}

void    ScavTrap::guardGate()
{
    if (this->_hitPoints > 0)
        std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode."
            << std::endl;
    else
        std::cout << "guardGate called by " << this->_name 
                << ", but already DEAD!" << std::endl;
}