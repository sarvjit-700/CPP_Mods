/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 22:11:03 by ssukhija          #+#    #+#             */
/*   Updated: 2026/03/23 22:11:03 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
    int N = 5;
    int i = 0;

    Zombie* horde = zombieHorde(N, "ZombieHorde");
    while (i < N)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde;
    return (0);
}