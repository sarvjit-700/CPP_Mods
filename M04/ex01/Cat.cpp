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
    std::cout << GREEN << "Cat Default constructor called with New Brain" << RESET << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();

}

Cat::Cat(const Cat &other) : Animal(other), _brain(NULL)
{
    std::cout << GREEN << "Cat Copy constructor called" << RESET << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << GREEN << "Cat assignment called with deep logic" << RESET << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        if (this -> _brain)
            delete this->_brain;
        if (other._brain)
            this->_brain = new Brain(*other._brain);
        else
            this->_brain = NULL;
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << GREEN << "Cat Destructor called. Destory the Brain." << RESET << std::endl;
    delete this->_brain;
}

void    Cat::makeSound() const
{
    std::cout << GREEN << "Meow! Meow!" << RESET << std::endl;
}

Brain *Cat::getBrain() const
{
    return (this->_brain);
}