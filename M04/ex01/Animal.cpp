/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 19:31:51 by ssukhija          #+#    #+#             */
/*   Updated: 2026/04/25 19:31:51 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << BLUE << "Animal Default construtor called" << RESET << std::endl;
}

Animal::Animal(std::string type)
{
    std::cout << BLUE  << "Animal Type constructor called for " << RESET << type << std::endl; 
    this->_type = type;
}

Animal::Animal(const Animal &other)
{
    std::cout << BLUE << "Animal Copy constructor called" << RESET << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << BLUE << "Animal assigment operator called" << RESET << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

Animal::~Animal()
{
    std::cout << BLUE << "Animal destructor called" << RESET << std::endl;
}

void Animal::makeSound() const
{
    std::cout << BLUE << "* Animal noise *" << RESET << std::endl;
}

std::string Animal::getType() const
{
    return this->_type;
}