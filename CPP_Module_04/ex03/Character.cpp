/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-haj- <kal-haj-@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:26:00 by kal-haj-          #+#    #+#             */
/*   Updated: 2026/11/17 16:26:00 by kal-haj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() : name("default"), floorCount(0)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
}

Character::Character(std::string const &name) : name(name), floorCount(0)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
}

// Deep copy: clone every materia
Character::Character(const Character &other) : name(other.name), floorCount(0)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = 0;
    }
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        name = other.name;
        clearInventory(); // delete our old materias first
        for (int i = 0; i < 4; i++)
        {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    clearInventory();
    clearFloor();
}

void Character::clearInventory()
{
    for (int i = 0; i < 4; i++)
    {
        delete inventory[i];
        inventory[i] = 0;
    }
}

void Character::clearFloor()
{
    for (int i = 0; i < floorCount; i++)
        delete floor[i];
    floorCount = 0;
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == m) // already equipped
            return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
}

// Does NOT delete the materia: it is dropped on the floor
void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !inventory[idx])
        return;
    if (floorCount >= FLOOR_SIZE)
        return; // floor is full, keep it equipped
    floor[floorCount++] = inventory[idx];
    inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4 || !inventory[idx])
        return;
    inventory[idx]->use(target);
}
