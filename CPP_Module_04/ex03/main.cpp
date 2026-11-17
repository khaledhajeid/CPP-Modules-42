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

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
    // ---- Subject test ----
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    // ---- More tests ----
    std::cout << std::endl << "--- extra tests ---" << std::endl;
    MateriaSource source;
    source.learnMateria(new Ice());
    source.learnMateria(new Cure());

    std::cout << "unknown type gives: "
              << (source.createMateria("fire") == 0 ? "NULL" : "something") << std::endl;

    Character alice("alice");
    Character target("target");

    // fill all 4 slots
    for (int i = 0; i < 4; i++)
        alice.equip(source.createMateria(i % 2 == 0 ? "ice" : "cure"));

    // 5th one doesn't fit, so we delete it ourselves
    AMateria *extra = source.createMateria("ice");
    alice.equip(extra);
    delete extra;

    for (int i = 0; i < 4; i++)
        alice.use(i, target);

    std::cout << "use invalid slots (nothing happens):" << std::endl;
    alice.use(-1, target);
    alice.use(7, target);

    std::cout << "unequip slot 0, then use it (nothing happens):" << std::endl;
    alice.unequip(0);
    alice.use(0, target);
    alice.unequip(0); // already empty

    std::cout << "deep copy test:" << std::endl;
    Character copy(alice);
    alice.unequip(1);  // alice loses slot 1
    copy.use(1, target); // copy still has its own
    alice.use(1, target); // nothing

    Character assigned("assigned");
    assigned.equip(source.createMateria("cure"));
    assigned = copy; // old cure gets deleted, then copy's materias are cloned
    assigned.use(3, target);
    std::cout << "assigned name: " << assigned.getName() << std::endl;

    return 0;
}
