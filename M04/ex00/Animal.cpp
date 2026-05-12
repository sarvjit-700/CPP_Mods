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
    std::cout << "Animal Default construtor called" << std::endl;
}

Animal::Animal(std::string type)
{
    std::cout << "Animal Type constructor called for " << type << std::endl; 
    this->_type = type;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal Copy constructor called";
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal assigment operator called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "* Animal noise *" << std::endl;
}

std::string Animal::getType() const
{
    return this->_type;
}