/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:15:59 by ssukhija          #+#    #+#             */
/*   Updated: 2026/04/05 17:15:59 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int                 _fpValue;
    static const int    _bits = 8;

public:
    Fixed();
    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;

    bool    operator>(const Fixed &f) const;
    bool    operator<(const Fixed &f) const;
    bool    operator>=(const Fixed &f) const;
    bool    operator<=(const Fixed &f) const;
    bool    operator==(const Fixed &f) const;
    bool    operator!=(const Fixed &f) const;

    Fixed   operator+(const Fixed&f) const;
    Fixed   operator-(const Fixed&f) const;
    Fixed   operator*(const Fixed&f) const;
    Fixed   operator/(const Fixed&f) const;
    Fixed   &operator++();
    Fixed   operator++(int);
    Fixed   &operator--();
    Fixed   operator--(int);

    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b); 
    static Fixed &max(Fixed &a, Fixed&b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif