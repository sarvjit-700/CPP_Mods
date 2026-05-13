/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:30:09 by ssukhija          #+#    #+#             */
/*   Updated: 2026/04/05 17:30:09 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}

// int main( void ) {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//      Fixed x = 10, y = 5;

//     std::cout << "--- Subject Tests ---" << std::endl;
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;

//     std::cout << "\n--- Comparison Tests ---" << std::endl;
//     Fixed c(10);
//     Fixed d(20);
//     std::cout << "c < d : " << (c < d) << std::endl;
//     std::cout << "c > d : " << (c > d) << std::endl;
//     std::cout << "c == c: " << (c == c) << std::endl;

    // std::cout << "\n--- Arithmetic Tests ---" << std::endl;

    // std::cout << "x = 10, y = 5" << std::endl;
    // std::cout << "x + y = " << Fixed(x) + Fixed(y) << std::endl;
    // std::cout << "x = " << Fixed(x) << std::endl;
    // std::cout << "10 - 5 = " << (Fixed(10) - Fixed(5)) << std::endl;
    // std::cout << "10 * 2 = " << (Fixed(10) * Fixed(2)) << std::endl;
    // std::cout << "10 / 2 = " << (Fixed(10) / Fixed(2)) << std::endl;

//     std::cout << "\n--- Min/Max Tests ---" << std::endl;
//     Fixed e(42);
//     Fixed f(24);
//     std::cout << "Min of 42 and 24: " << Fixed::min(e, f) << std::endl;

//     return 0;
// }