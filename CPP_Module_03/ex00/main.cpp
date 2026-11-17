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

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Clappy");

    a.attack("a target");
    a.takeDamage(3);
    a.beRepaired(2);
    for (int i = 0; i < 9; i++)   // use up the remaining energy
        a.attack("a target");
    a.beRepaired(1);              // no energy left
    a.takeDamage(20);             // HP goes to 0
    a.takeDamage(1);              // already destroyed
    return 0;
}
