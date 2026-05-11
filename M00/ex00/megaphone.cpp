/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:50:36 by ssukhija          #+#    #+#             */
/*   Updated: 2026/02/05 08:50:36 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    int i, j;

    i = 1;
    j = 0;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (i < argc)
        {

            while(argv[i][j])
            {
                std::cout << (char)std::toupper(argv[i][j]);
                j++;
            }
            j = 0;
            if (i < argc -1)
                std::cout << " ";
            i++;
        }
    }
    std::cout << std::endl;
    return (0);
}