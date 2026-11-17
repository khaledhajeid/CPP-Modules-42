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

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- ScavTrap ---" << std::endl;
    {
        ScavTrap s("Scavy");
        s.attack("a target");
        s.guardGate();
    }
    std::cout << std::endl << "--- FragTrap (construction/destruction chain) ---" << std::endl;
    {
        FragTrap f("Fraggy");
        f.attack("a target");
        f.takeDamage(50);
        f.beRepaired(20);
        f.highFivesGuys();
    }
    std::cout << std::endl << "--- FragTrap copy ---" << std::endl;
    {
        FragTrap a("A");
        FragTrap b(a);
        b.highFivesGuys();
    }
    return 0;
}
