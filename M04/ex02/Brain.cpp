/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:42:15 by ssukhija          #+#    #+#             */
/*   Updated: 2026/05/15 22:42:15 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "BRAIN Default constructor called" << std::endl;
}


Brain::Brain(const Brain &other)
{
    std::cout << "BRAIN Copy constructor called" << std::endl;
    *this = other;
}

Brain &Brain::operator=(const Brain &other)
{
    int i = 0;

    std::cout << "BRAIN Assignment operator called" << std::endl;
    if (this != &other)
    {
        while (i < 100)
        {
            this->ideas[i] = other.ideas[i];
            i++;
        }
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "BRAIN Destructor called" << std::endl;
}

void    Brain::setIdea(int index, std::string idea)
{
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return (this->ideas[index]);
    return "";
}