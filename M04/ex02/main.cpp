/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 10:22:36 by ssukhija          #+#    #+#             */
/*   Updated: 2026/05/17 10:22:36 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Creating Derived Classes ---" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    j->makeSound();
    i->makeSound();
    
    delete j;
    delete i;

    std::cout << "\n--- Trying to Instantiate Abstract Class ---" << std::endl;
    // UNCOMMENTING THE LINE BELOW MUST CAUSE A COMPILATION ERROR!
    //const Animal* testAbstract = new Animal(); 

    return 0;
}