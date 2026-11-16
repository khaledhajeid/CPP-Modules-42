/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-haj- <kal-haj-@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:51:31 by kal-haj-          #+#    #+#             */
/*   Updated: 2026/11/16 17:51:32 by kal-haj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << "--- arithmetic ---" << std::endl;
    Fixed x(10);
    Fixed y(2.5f);
    std::cout << "10 + 2.5 = " << x + y << std::endl;
    std::cout << "10 - 2.5 = " << x - y << std::endl;
    std::cout << "10 * 2.5 = " << x * y << std::endl;
    std::cout << "10 / 2.5 = " << x / y << std::endl;
    std::cout << "-3.5 * 2 = " << Fixed(-3.5f) * Fixed(2) << std::endl;
    std::cout << "-5.5 as integer = " << Fixed(-5.5f).toInt() << std::endl;

    std::cout << "--- comparison (1 is true, 0 is false) ---" << std::endl;
    std::cout << "10 > 2.5 : " << (x > y) << std::endl;
    std::cout << "10 < 2.5 : " << (x < y) << std::endl;
    std::cout << "10 >= 10 : " << (x >= Fixed(10)) << std::endl;
    std::cout << "10 <= 2.5 : " << (x <= y) << std::endl;
    std::cout << "10 == 10 : " << (x == Fixed(10)) << std::endl;
    std::cout << "10 != 2.5 : " << (x != y) << std::endl;

    std::cout << "--- decrement ---" << std::endl;
    Fixed z(1);
    std::cout << --z << std::endl;
    std::cout << z-- << std::endl;
    std::cout << z << std::endl;

    std::cout << "--- min and max ---" << std::endl;
    Fixed const p(1.5f);
    Fixed const q(-1.5f);
    std::cout << "min(10, 2.5) = " << Fixed::min(x, y) << std::endl;
    std::cout << "max(10, 2.5) = " << Fixed::max(x, y) << std::endl;
    std::cout << "const min(1.5, -1.5) = " << Fixed::min(p, q) << std::endl;
    std::cout << "const max(1.5, -1.5) = " << Fixed::max(p, q) << std::endl;

    return 0;
}
