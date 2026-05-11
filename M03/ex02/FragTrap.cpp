/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 09:01:33 by ssukhija          #+#    #+#             */
/*   Updated: 2026/04/20 09:01:33 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragT Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragT Name constructor called for " << name
        << "\n--starts with hitPoints[100], energyPoints[100], attackDamage[30]" 
        << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragT copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragT assignment constructor called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << this->_name << " FragT Destructor called" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    if (this->_hitPoints > 0)
        std::cout << "highFivesGuys called by " << this->_name << std::endl;
    else
        std::cout << "highFivesGuys called by " << this->_name 
                << " but already dead!" << std::endl;
}