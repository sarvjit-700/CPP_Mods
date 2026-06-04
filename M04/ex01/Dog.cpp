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
    std::cout << YELLOW << "Dog Default constructor called with New Brain" << RESET << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other), _brain(NULL)
{
    std::cout << YELLOW << "Dog Copy constructor called" << RESET << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << YELLOW << "Dog assignment called" << RESET << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        if (this->_brain)
            delete this->_brain;
        if (other._brain)
            this->_brain = new Brain(*other._brain); //this creates a new heap memory
        else
            this->_brain = NULL;
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << YELLOW << "Dog Destructor called, Destory the Brain." << RESET << std::endl;
    delete this->_brain;
}

void Dog::makeSound() const
{
    std::cout << YELLOW << "Woof! Woof!" << RESET << std::endl;
}

Brain *Dog::getBrain() const
{
    return (this->_brain);
}