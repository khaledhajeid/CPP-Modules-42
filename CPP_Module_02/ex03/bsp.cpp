#include "Point.hpp"

static long cross(Point const &a, Point const &b, Point const &p)
{
    long abX = (b.getX() - a.getX()).getRawBits();
    long abY = (b.getY() - a.getY()).getRawBits();
    long apX = (p.getX() - a.getX()).getRawBits();
    long apY = (p.getY() - a.getY()).getRawBits();

    return abX * apY - abY * apX;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    long side1 = cross(a, b, point);
    long side2 = cross(b, c, point);
    long side3 = cross(c, a, point);

    if (side1 > 0 && side2 > 0 && side3 > 0)
        return true;
    if (side1 < 0 && side2 < 0 && side3 < 0)
        return true;
    return false;
}
