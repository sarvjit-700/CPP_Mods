/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:55:50 by ssukhija          #+#    #+#             */
/*   Updated: 2026/03/27 16:55:50 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
    std::string filename;
    std::string s1;
    std::string s2;
    std::string line;
    size_t pos;
    

    if (argc != 4)
    {
        std::cout << "Error: 3 arguments expected!\n" << std::endl;
        return (1);
    }
    filename = argv[1];
    s1 = argv[2];
    s2 = argv[3];
    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cout << "Error opening file!\n" << std::endl;
        return (1);
    }
    if (s1.empty())
    {
        std::cout << "Error with s1!\n" << std::endl;
        return (1);
    }
    std::string outname = filename + ".replace";
    std::ofstream outfile(outname.c_str());
    if (!outfile)
    {
        std::cout << "Error creating output file!\n";
        return 1;
    }    
    while (std::getline(infile, line))
    {
        pos = line.find(s1);
        while (pos != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos = line.find(s1, pos + s2.length());
        }
        outfile << line;
        if (!infile.eof())
            outfile << '\n';
    }
    return (0);
}