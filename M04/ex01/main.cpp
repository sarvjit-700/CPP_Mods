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
    const Animal* anml = new Animal();
    const Animal* d = new Dog();
    const Animal* c = new Cat();
    std::cout << "- output type dog:" << std::endl;
    std::cout << d->getType() << std::endl;
    std::cout << "- output type cat:" << std::endl;
    std::cout << c->getType() << std::endl;
    std::cout << "- output cat noise:" << std::endl;
    c->makeSound();
    std::cout << "- output dog noise:" << std::endl;
    d->makeSound();
    std::cout << "- output animal noise:" << std::endl;
    anml->makeSound();
    
    delete anml;
    delete d;
    delete c;

    std::cout << "\n--- WRONG ANIMAL TEST ---" << std::endl;
    
    const WrongAnimal* wanml = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();
    std::cout << "- output type wrong cat:" << std::endl;
    std::cout << wc->getType() << " " << std::endl;
    std::cout << "- output wrong cat noise (will be incorrect):" << std::endl;
    wc->makeSound(); 
    std::cout << "- output wrong animal noise:" << std::endl;
    wanml->makeSound();

    std::cout << "- deleting wrong cat but WrongCat destructor not called:" << std::endl;
    delete wc; 
    delete wanml;

    return 0;
}