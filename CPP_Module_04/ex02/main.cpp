/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-haj- <kal-haj-@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:26:00 by kal-haj-          #+#    #+#             */
/*   Updated: 2026/11/17 16:26:00 by kal-haj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Subject test ---" << std::endl;
    {
        const Animal *j = new Dog();
        const Animal *i = new Cat();

        delete j; // should not create a leak
        delete i;
    }

    // Animal is abstract now, so this line would NOT compile:
    // Animal a;

    std::cout << std::endl << "--- Array of animals (half dogs, half cats) ---" << std::endl;
    {
        const int size = 4;
        Animal *animals[size];

        for (int k = 0; k < size; k++)
        {
            if (k < size / 2)
                animals[k] = new Dog();
            else
                animals[k] = new Cat();
        }
        for (int k = 0; k < size; k++)
            animals[k]->makeSound();
        for (int k = 0; k < size; k++)
            delete animals[k];
    }

    std::cout << std::endl << "--- Deep copy (copy constructor) ---" << std::endl;
    {
        Dog a;
        a.getBrain()->setIdea(0, "chase the cat");
        Dog b(a);
        b.getBrain()->setIdea(0, "sleep");

        std::cout << "a idea: " << a.getBrain()->getIdea(0) << std::endl;
        std::cout << "b idea: " << b.getBrain()->getIdea(0) << std::endl;
        std::cout << "different brains: "
                  << (a.getBrain() != b.getBrain() ? "yes" : "no") << std::endl;
    }

    std::cout << std::endl << "--- Deep copy (assignment operator) ---" << std::endl;
    {
        Cat a;
        Cat b;
        a.getBrain()->setIdea(0, "eat fish");
        b = a;
        a.getBrain()->setIdea(0, "ignore humans");

        std::cout << "a idea: " << a.getBrain()->getIdea(0) << std::endl;
        std::cout << "b idea: " << b.getBrain()->getIdea(0) << std::endl;
    }
    return 0;
}
