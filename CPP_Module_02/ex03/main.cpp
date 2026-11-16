/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-haj- <kal-haj-@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:51:46 by kal-haj-          #+#    #+#             */
/*   Updated: 2026/11/16 17:51:47 by kal-haj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
#include <string>

static int g_failed = 0;

static void check(std::string name, Point a, Point b, Point c, Point p, bool expected)
{
    bool result = bsp(a, b, c, p);

    if (result == expected)
        std::cout << "[OK]   " << name << std::endl;
    else
    {
        std::cout << "[FAIL] " << name << std::endl;
        g_failed++;
    }
}

int main(void)
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    check("inside", a, b, c, Point(2, 2), true);
    check("inside, other vertex order", c, b, a, Point(2, 2), true);
    check("inside, close to an edge", a, b, c, Point(4.9f, 4.9f), true);
    check("outside", a, b, c, Point(20, 20), false);
    check("outside, negative side", a, b, c, Point(-1, 2), false);
    check("on vertex a", a, b, c, a, false);
    check("on vertex b", a, b, c, b, false);
    check("on vertex c", a, b, c, c, false);
    check("on edge ab", a, b, c, Point(5, 0), false);
    check("on edge ac", a, b, c, Point(0, 5), false);
    check("on edge bc", a, b, c, Point(5, 5), false);

    Point d(-5.5f, -3.25f);
    Point e(4.5f, -3.25f);
    Point f(-0.5f, 6.75f);
    check("negative coordinates, inside", d, e, f, Point(-0.5f, 0), true);
    check("negative coordinates, outside", d, e, f, Point(-5, 5), false);

    check("small triangle, inside", Point(0, 0), Point(0.1f, 0), Point(0, 0.1f), Point(0.02f, 0.02f), true);
    check("flat triangle", Point(0, 0), Point(5, 5), Point(10, 10), Point(5, 5), false);
    check("flat triangle, point off the line", Point(0, 0), Point(5, 5), Point(10, 10), Point(1, 2), false);

    Point copy(b);
    Point assigned;
    assigned = b;
    check("copy of a vertex works", a, copy, c, Point(2, 2), true);
    std::cout << "assignment keeps x at " << assigned.getX() << " because x is const" << std::endl;

    if (g_failed == 0)
    {
        std::cout << "All tests passed" << std::endl;
        return 0;
    }
    std::cout << g_failed << " tests failed" << std::endl;
    return 1;
}
