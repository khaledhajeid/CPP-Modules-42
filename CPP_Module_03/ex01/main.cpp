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
#include <iostream>

int main()
{
    std::cout << "--- ClapTrap ---" << std::endl;
    {
        ClapTrap c("Clappy");
        c.attack("a target");
    }
    std::cout << std::endl << "--- ScavTrap (construction/destruction chain) ---" << std::endl;
    {
        ScavTrap s("Scavy");
        s.attack("a target");
        s.takeDamage(30);
        s.beRepaired(10);
        s.guardGate();
    }
    std::cout << std::endl << "--- ScavTrap copy ---" << std::endl;
    {
        ScavTrap a("A");
        ScavTrap b(a);
        b.attack("someone");
    }
    return 0;
}
