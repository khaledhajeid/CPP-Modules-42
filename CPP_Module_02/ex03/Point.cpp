/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-haj- <kal-haj-@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:51:53 by kal-haj-          #+#    #+#             */
/*   Updated: 2026/11/16 17:51:54 by kal-haj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{

}

Point::Point(const float x, const float y) : x(x), y(y)
{

}

Point::Point(const Point &other) : x(other.x), y(other.y)
{

}

Point &Point::operator=(const Point &other)
{
    (void)other;
    return *this;
}

Point::~Point()
{

}

const Fixed &Point::getX() const
{
    return x;
}

const Fixed &Point::getY() const
{
    return y;
}
