/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 21:38:23 by ssukhija          #+#    #+#             */
/*   Updated: 2026/04/25 21:38:23 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << GREEN << "Cat Default constructor called" << RESET << std::endl;
    this->_type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << GREEN << "Cat Copy constructor called" << RESET << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << GREEN << "Cat assignment called" << RESET << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::~Cat()
{
    std::cout << GREEN << "Cat Destructor called" << RESET << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << GREEN << "Meow! Meow!" << RESET << std::endl;
}