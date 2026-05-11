/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wepaon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:44:58 by ssukhija          #+#    #+#             */
/*   Updated: 2026/03/26 14:44:58 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
    std::string type;

public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();

    void    setType(std::string type); 
    const std::string&    getType() const;
};

#endif