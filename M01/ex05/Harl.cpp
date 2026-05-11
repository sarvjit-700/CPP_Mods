/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 11:09:15 by ssukhija          #+#    #+#             */
/*   Updated: 2026/03/29 11:09:15 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() 
{
    std::cout << "HARL is created:" << std::endl;
}
Harl::~Harl()
{
    std::cout << "HARL is destroyed.." << std::endl;
}

void    Harl::complain(std::string level)
{
    int i = 0;

    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    while (i < 4)
    {
        if (levels[i] == level)
        {
            (this->*functions[i])();
            return ;
        }
        i++;
    }
    std::cout << "Unknown level\n";
}

void    Harl::debug(void)
{
    std::cout << "DEBUG: I love having extra bacon for my "
                "7XL-double-cheese-triple-pickle-specialketchup "
                "burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "INFO: I cannot believe adding extra "
                "bacon costs more money. You didn’t put enough bacon "
                "in my burger! If you did, I wouldn’t be asking for more!" 
                << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. "
                "I’ve been coming for years, whereas you started working here "
                "just last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now."
            << std::endl;
}
