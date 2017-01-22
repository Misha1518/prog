#include <iostream>
#include <cmath>
#include <sstream>
#include "Vec2d.h"

const double eps = 1.0e-7;

bool Vec2d::operator==(const Vec2d& a) { return (abs(x - a.x) < eps && abs(y - a.y) < eps); }

Vec2d operator+(const Vec2d& a, const Vec2d& b)
{
    Vec2d sum(a);
    sum += b;
    return sum;
}

Vec2d operator-(const Vec2d& a, const Vec2d& b)
{
    Vec2d con(a);
    con -= b;
    return con;
}

double operator*(const Vec2d& a, const Vec2d& b)
{
    return (a*b);
}

Vec2d& Vec2d::operator+=(const Vec2d& a)
{
    x += a.x;
    y += a.y;
    return *this;
}

Vec2d& Vec2d::operator-=(const Vec2d& a)
{
    x -= a.x;
    y -= a.y;
    return *this;
}

Vec2d& Vec2d::operator*=(const double& a)
{
    x *= a;
    y *= a;
    return *this;
}

Vec2d& Vec2d::operator=(const Vec2d& a)
{
    x = a.x;
    y = a.y;
    return *this;
}

std::ostream& Vec2d::WriteTo(std::ostream& ostrm) const
{
    ostrm << "x = " << x << ", y = " << y;
    return ostrm;
}

std::ostream& operator<<(std::ostream& ostrm, const Vec2d& a)
{
    return a.WriteTo(ostrm);
}