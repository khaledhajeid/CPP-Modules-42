/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-haj- <kal-haj-@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:26:00 by kal-haj-          #+#    #+#             */
/*   Updated: 2026/11/17 16:26:00 by kal-haj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &other) : AMateria(other)
{
}

Ice &Ice::operator=(const Ice &other)
{
    AMateria::operator=(other);
    return *this;
}

Ice::~Ice()
{
}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
