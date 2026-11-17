/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-haj- <kal-haj-@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:20:48 by kal-haj-          #+#    #+#             */
/*   Updated: 2026/11/17 16:20:48 by kal-haj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

// ClapTrap is a virtual base, so DiamondTrap constructs it directly (only once).
DiamondTrap::DiamondTrap()
    : ClapTrap("default_clap_name"), ScavTrap(), FragTrap(), name("default")
{
    hitPoints = 100;    // FragTrap
    energyPoints = 50;  // ScavTrap
    attackDamage = 30;  // FragTrap
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &newName)
    : ClapTrap(newName + "_clap_name"), ScavTrap(newName), FragTrap(newName), name(newName)
{
    hitPoints = 100;    // FragTrap
    energyPoints = 50;  // ScavTrap
    attackDamage = 30;  // FragTrap
    std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    name = other.name;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << name << ", my ClapTrap name is "
              << ClapTrap::name << std::endl;
}
