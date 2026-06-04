/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 18:36:21 by ssukhija          #+#    #+#             */
/*   Updated: 2026/04/25 18:36:21 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "- output type dog:" << std::endl;
    std::cout << j->getType() << std::endl;
    std::cout << "- output type cat:" << std::endl;
    std::cout << i->getType() << std::endl;
    std::cout << "- output cat noise:" << std::endl;
    i->makeSound();
    std::cout << "- output dog noise:" << std::endl;
    j->makeSound();
    std::cout << "- output animal noise:" << std::endl;
    meta->makeSound();
    std::cout << "Clean heap" << std::endl;
   
    delete meta;
    delete j;
    delete i;
    

    std::cout << "\n--- Testing Copy and Assignment ---" << std::endl;
    std::cout << "Create 2 more Dog objects, OG and CopyOG" << std::endl;
    Dog OG;
    Dog CopyOG;
    std::cout << "Dog tmp = OG\nInitializes tmp by using Animal Copy/Assign\n"
            << "and then using Dog Copy/Assign" << std::endl;
    Dog tmp = OG;
    std::cout << "Test just Assignment by Dog CopyOG = OG" << std::endl;
    CopyOG = OG; 
    //CopyOG already initialized so just need to change values to match Animal part of OG
    std::cout << "Destructors called at the end of program." << std::endl;
    std::cout << "--- Done Copy and Assignment ---\n" << std::endl;


    std::cout << "\n--- WRONG ANIMAL TEST ---" << std::endl;
    
    const WrongCat* directCat = new WrongCat();
    std::cout << "Direct WrongCat sound: \n";
    directCat->makeSound(); // Should output "WrongCat Meow!"
    std::cout << "\n";
    std::cout << "Clean heap" << std::endl;
    delete directCat;

    const WrongAnimal* wanml = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();

    std::cout << "- output type wrong cat:" << std::endl;
    std::cout << wc->getType() << " " << std::endl;
    std::cout << "- output wrong cat noise (will be incorrect):" << std::endl;
    wc->makeSound(); 
    std::cout << "- output wrong animal noise:" << std::endl;
    wanml->makeSound();

    std::cout << "- deleting wrong cat but WrongCat destructor not called:" << std::endl;
    std::cout << "Clean heap" << std::endl;
    delete wc; 
    delete wanml;

    std::cout << "\n\nCall Destructors for OG, CopyOG and tmp" << std::endl;
    return 0;
}