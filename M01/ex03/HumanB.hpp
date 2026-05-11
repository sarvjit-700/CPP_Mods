/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:44:40 by ssukhija          #+#    #+#             */
/*   Updated: 2026/03/26 14:44:40 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
private:
    std::string name;
    Weapon* weapon;

public:
    HumanB(std::string name);
    ~HumanB();

    void    setWeapon(Weapon& weapon);
    void    attack(void);

};

#endif
