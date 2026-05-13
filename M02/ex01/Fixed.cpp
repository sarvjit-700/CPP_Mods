/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 08:07:05 by ssukhija          #+#    #+#             */
/*   Updated: 2026/04/02 08:07:05 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
    out << fixed.toFloat();
    return out;
}

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) 
{
    std::cout << "Int constructor called" << std::endl;
    this->_fpValue = n << _bits;
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fpValue = roundf(n * (1 << _bits));
}

Fixed::Fixed(const Fixed &other) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fpValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const 
{
    return this->_fpValue;
}
void    Fixed::setRawBits(int const raw) 
{
    this->_fpValue = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->_fpValue / (1 << _bits);
}

int Fixed::toInt(void) const 
{
    return this->_fpValue >> _bits;
}