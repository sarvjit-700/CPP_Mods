/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 21:21:32 by ssukhija          #+#    #+#             */
/*   Updated: 2026/04/25 21:21:32 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << YELLOW << "Dog Default constructor called" << RESET << std::endl;
    this->_type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << YELLOW << "Dog Copy constructor called" << RESET << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << YELLOW << "Dog assignment called" << RESET << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    std::cout << YELLOW << "Dog Destructor called" << RESET << std::endl;
}

void Dog::makeSound() const
{
    std::cout << YELLOW << "Woof! Woof!" << RESET << std::endl;
}