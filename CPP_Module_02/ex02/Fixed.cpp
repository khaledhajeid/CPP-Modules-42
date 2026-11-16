/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-haj- <kal-haj-@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:51:27 by kal-haj-          #+#    #+#             */
/*   Updated: 2026/11/16 17:51:28 by kal-haj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractionalBits = 8;

Fixed::Fixed()
{
    value = 0;
}

Fixed::Fixed(const int number)
{
    value = number * (1 << fractionalBits);
}

Fixed::Fixed(const float number)
{
    value = roundf(number * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        value = other.value;
    return *this;
}

Fixed::~Fixed()
{

}

int Fixed::getRawBits(void) const
{
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(value) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return value / (1 << fractionalBits);
}

bool Fixed::operator>(const Fixed &other) const
{
    return value > other.value;
}

bool Fixed::operator<(const Fixed &other) const
{
    return value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const
{
    return value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return value != other.value;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;

    result.value = value + other.value;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;

    result.value = value - other.value;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
    value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed old(*this);

    value++;
    return old;
}

Fixed &Fixed::operator--()
{
    value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed old(*this);

    value--;
    return old;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
