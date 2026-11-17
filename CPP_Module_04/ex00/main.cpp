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
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Subject test ---" << std::endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << std::endl << "--- Wrong animals (no virtual) ---" << std::endl;
    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // outputs the WrongAnimal sound
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat;

    std::cout << std::endl << "--- WrongCat used directly ---" << std::endl;
    {
        WrongCat wc;
        wc.makeSound(); // here we get the WrongCat sound
    }

    std::cout << std::endl << "--- Copies ---" << std::endl;
    {
        Dog d1;
        Dog d2(d1);
        Cat c1;
        Cat c2;
        c2 = c1;
        d2.makeSound();
        c2.makeSound();
    }
    return 0;
}
