/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:05:37 by ssukhija          #+#    #+#             */
/*   Updated: 2026/04/07 20:05:37 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name),  _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Clap Name constructor called " << name 
        << "\n--starts with hitPoints[10], energyPoints[10], attackDamage[0]" 
        << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << this->_name << " ClapTrap Destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string &target)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        this->_energyPoints--;
        std::cout << "ClapTrap " << this->_name << " attacks " << target 
                << ", causing " << this->_attackDamage << " points of damage!"
                << std::endl;
        
    }
    else if (!this->_hitPoints)
        std::cout << "ClapTrap " << this->_name 
                << " is unable to attack, no HP!" << std::endl;
    else
        std::cout << "ClapTrap " << this->_name 
                << " is unable to attack, no EP!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints == 0)
    {
        std::cout << _name << " is already dead!" << std::endl;
        return;
    }
    if (amount >= this->_hitPoints)
        this->_hitPoints = 0;
    else
        this->_hitPoints -= amount;

    std::cout << this->_name << " has ["
            << this->_hitPoints << "] hit points left.\n"
            << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (amount == 0) // Only used for status update
    {
        std::cout << this->_name << " has ["
                << this->_hitPoints << "] hit points and ["
                << this->_energyPoints << "] energy points.\n" 
                << std::endl;
    }
    else
    {
        if (this->_hitPoints == 0)
        {
            std::cout << _name << " is already dead!" << std::endl;
            return;
        }
        if (this->_energyPoints == 0)
        {
            std::cout << _name << " doesn't have enough energy to repair!" << std::endl;
            return; 
        }
        if (this->_hitPoints > 0 && this->_energyPoints > 0)
        {
            this->_hitPoints = this->_hitPoints + amount;
            this->_energyPoints--;
            std::cout << this->_name << " has ["
                    << this->_hitPoints << "] hit points and ["
                    << this->_energyPoints << "] energy points.\n" 
                    << std::endl;
        }
    }
}