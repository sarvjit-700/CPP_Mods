/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 09:06:28 by ssukhija          #+#    #+#             */
/*   Updated: 2026/03/25 09:06:28 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str;
    str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Address of string: " << &str << std::endl;
    std::cout << "Address of pointer: " << stringPTR << std::endl;
    std::cout << "Address of reference: " << &stringREF << std::endl;

    std::cout << "Value of the string: " << str << std::endl;
    std::cout << "Value of the pointer: " << *stringPTR << std::endl;
    std::cout << "Value of the reference: " << stringREF << std::endl;
    return (0);
}