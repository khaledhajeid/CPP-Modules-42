/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-haj- <kal-haj-@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:51:55 by kal-haj-          #+#    #+#             */
/*   Updated: 2026/11/16 17:51:56 by kal-haj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    Fixed const x;
    Fixed const y;

public:
    Point();
    Point(const float x, const float y);
    Point(const Point &other);
    Point &operator=(const Point &other);
    ~Point();

    const Fixed &getX() const;
    const Fixed &getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
