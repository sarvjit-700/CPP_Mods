/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:16:34 by ssukhija          #+#    #+#             */
/*   Updated: 2026/04/05 17:16:34 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <cmath>

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
    out << fixed.toFloat();
    return out;
}

Fixed::Fixed() : _fpValue(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) 
{
    // std::cout << "Int constructor called" << std::endl;
    this->_fpValue = n << _bits;
    //bit shifting for ints, faster 
}

Fixed::Fixed(const float n)
{
    // std::cout << "Float constructor called" << std::endl;
    this->_fpValue = roundf(n * (1 << _bits));
    //can't bit shift for float so 1 << bits = 256
}

Fixed::Fixed(const Fixed &other) 
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) 
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fpValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed() 
{
    // std::cout << "Destructor called" << std::endl;
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
    return ((float)this->_fpValue / (1 << _bits));
}

int Fixed::toInt(void) const 
{
    return ((this->_fpValue >> _bits));
}

bool    Fixed::operator>(const Fixed &f) const
{
    return (this->_fpValue > f._fpValue);
}

bool    Fixed::operator<(const Fixed &f) const
{
    return (this->_fpValue < f._fpValue);
}

bool    Fixed::operator>=(const Fixed &f) const
{
    return (this->_fpValue >= f._fpValue);
}

bool    Fixed::operator<=(const Fixed &f) const
{
    return (this->_fpValue <= f._fpValue);
}

bool    Fixed::operator==(const Fixed &f) const
{
    return (this->_fpValue == f._fpValue);
}

bool    Fixed::operator!=(const Fixed &f) const
{
    return (this->_fpValue != f._fpValue);
}

Fixed   Fixed::operator+(const Fixed &f) const
{
    Fixed num = Fixed();
    num.setRawBits(this->_fpValue + f._fpValue);
    return (num);
    //setRawBits: change the _fpValue to the result of the addition
}

Fixed   Fixed::operator-(const Fixed &f) const
{
    Fixed num = Fixed();
    num.setRawBits(this->_fpValue - f._fpValue);
    return (num);
}

Fixed   Fixed::operator*(const Fixed &f) const
{
    return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed   Fixed::operator/(const Fixed &f) const
{
    return (Fixed(this->toFloat() / f.toFloat()));
}

Fixed   &Fixed::operator++()
{
    this->_fpValue++;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->_fpValue++;
    return (tmp);
}

Fixed   &Fixed::operator--()
{
    this->_fpValue--;
    return (*this);
}

Fixed   Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->_fpValue--;
    return (tmp);
}


Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed&b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}