/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:58:50 by ssukhija          #+#    #+#             */
/*   Updated: 2026/03/29 18:58:50 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int                 _fpValue;
    static const int    _fractionalBits = 8;
    //last 8 bits of interger represent the decimal part

public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    //using const in getRawBits means this function 
    //will not change the state of the object
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

#endif