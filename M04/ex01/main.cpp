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
#include <iostream>

int main()
{
    std::cout << GREEN << "=========================================" << RESET << std::endl;
    std::cout << GREEN << "    TEST 1: MANDATORY ANIMAL ARRAY TEST  " << RESET << std::endl;
    std::cout << GREEN << "=========================================" << RESET << std::endl;
    
    const int arraySize = 4;
    Animal* animals[arraySize];

    std::cout << "\n--- Creating and filling the array (Half Dogs, Half Cats) ---" << std::endl;
    for (int i = 0; i < arraySize / 2; i++)
    {
        std::cout << "[Creating Dog at index " << i << "]" << std::endl;
        animals[i] = new Dog();
    }
    for (int i = arraySize / 2; i < arraySize; i++)
    {
        std::cout << "[Creating Cat at index " << i << "]" << std::endl;
        animals[i] = new Cat();
    }

    std::cout << "\n--- Testing Polymorphic Behavior on the Array ---" << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << "Animal index " << i << " is type: " << animals[i]->getType() << " and says: ";
        animals[i]->makeSound();
    }

    std::cout << "\n--- Deleting directly as Animals (Testing Virtual Destructor Chain) ---" << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << "[Deleting animal index " << i << "]" << std::endl;
        delete animals[i]; 
    }

    std::cout << "\n" << GREEN << "=========================================" << RESET << std::endl;
    std::cout << GREEN << "    TEST 2: DEEP COPY VERIFICATION (CONSTRUCTOR) " << RESET << std::endl;
    std::cout << GREEN << "=========================================" << RESET << std::endl;

    std::cout << "\n--- Creating Original Dog and setting an idea ---" << std::endl;
    Dog* originalDog = new Dog();
    std::cout << "Set Ideas: I want to chase that squirrel!, I love treats." << std::endl;
    originalDog->getBrain()->setIdea(0, "I want to chase that squirrel!");
    originalDog->getBrain()->setIdea(1, "I love treats.");

    std::cout << "\n--- Creating Clone Dog using Copy Constructor ---" << std::endl;
    Dog* cloneDog = new Dog(*originalDog);

    std::cout << "\n--- Changing Original Dog's ideas to test deep copy independence ---" << std::endl;
    std::cout << "Change Ideas: I am sleepy now..., No more treats." << std::endl;
    originalDog->getBrain()->setIdea(0, "I am sleepy now...");
    originalDog->getBrain()->setIdea(1, "No more treats.");

    std::cout << "\n--- Displaying ideas ---" << std::endl;
    std::cout << "Original Dog Idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Clone Dog Idea 0:    " << cloneDog->getBrain()->getIdea(0) << " <-- MUST BE CHASE SQUIRREL!" << std::endl;
    std::cout << "Original Dog Idea 1: " << originalDog->getBrain()->getIdea(1) << std::endl;
    std::cout << "Clone Dog Idea 1:    " << cloneDog->getBrain()->getIdea(1) << " <-- MUST BE LOVE TREATS!" << std::endl;

    std::cout << "\n--- Deleting Original and Clone (Verifying No Double-Frees) ---" << std::endl;
    delete originalDog;
    delete cloneDog;

    std::cout << "\n" << GREEN << "=========================================" << RESET << std::endl;
    std::cout << GREEN << "    TEST 3: DEEP COPY VERIFICATION (ASSIGNMENT)  " << RESET << std::endl;
    std::cout << GREEN << "=========================================" << RESET << std::endl;

    std::cout << "\n--- Creating two independent Cats ---" << std::endl;
    Cat catA;
    Cat catB;
    std::cout << "Set Idea for catA: Catch the red laser dot!" << std::endl;
    catA.getBrain()->setIdea(0, "Catch the red laser dot!");
    
    std::cout << "\n--- Assigning Cat A to Cat B ---" << std::endl;
    catB = catA;

    std::cout << "\n--- Changing Cat A's idea ---" << std::endl;
    std::cout << "Change catA Idea: I want to destroy the couch." << std::endl;
    catA.getBrain()->setIdea(0, "I want to destroy the couch.");

    std::cout << "\n--- Displaying Ideas ---" << std::endl;
    std::cout << "Cat A Idea 0: " << catA.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat B Idea 0: " << catB.getBrain()->getIdea(0) << " <-- MUST BE RED LASER DOT!" << std::endl;

    std::cout << "\n--- Exiting Program (Stack cleanup for Cat A and Cat B) ---" << std::endl;
    return 0;
}