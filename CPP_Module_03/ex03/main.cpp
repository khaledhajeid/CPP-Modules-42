/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-haj- <kal-haj-@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:20:48 by kal-haj-          #+#    #+#             */
/*   Updated: 2026/11/17 16:20:48 by kal-haj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- DiamondTrap (ClapTrap built only once) ---" << std::endl;
    {
        DiamondTrap d("Diamond");
        d.whoAmI();
        d.attack("a target");   // ScavTrap's attack, 30 damage
        d.takeDamage(40);
        d.beRepaired(10);
        d.guardGate();
        d.highFivesGuys();
    }
    std::cout << std::endl << "--- DiamondTrap copy ---" << std::endl;
    {
        DiamondTrap a("A");
        DiamondTrap b(a);
        b.whoAmI();
    }
    return 0;
}
