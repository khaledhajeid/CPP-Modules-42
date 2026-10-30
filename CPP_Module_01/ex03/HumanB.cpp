#include "HumanB.hpp"
#include <cstddef>
#include <iostream>

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB()
{

}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack() const
{
    if (weapon == NULL)
        std::cout << name << " has no weapon to attack with" << std::endl;
    else
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
