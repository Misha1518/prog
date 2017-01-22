#ifndef _HG_VEC2D_H_03102016
#define _HG_VEC2D_H_03102016

#include <iostream>

struct Vec2d
{
    double x;
    double y;
    Vec2d() {}
    Vec2d(double x, double y) : x(x), y(y) {}
    Vec2d(const Vec2d& a) = default;
    ~Vec2d() = default;
    Vec2d& operator=(const Vec2d& a);
    double operator[](const int index) {
        switch (index)
        {
        case 0:return x;
        case 1:return y;
        default:throw std::out_of_range("Vec2d indexator out of range\n");
        }
    }
    Vec2d& operator+=(const Vec2d& a);
    Vec2d& operator-=(const Vec2d& a);
    Vec2d& operator*=(const double& a);
    bool operator==(const Vec2d& a);
    bool operator!=(const Vec2d& a) { return !operator==(a); }
    std::ostream& WriteTo(std::ostream& ostrm) const;
};
std::ostream& operator<<(std::ostream& ostrm, const Vec2d& a);
    Vec2d operator+(const Vec2d& a, const Vec2d& b);
    Vec2d operator-(const Vec2d& a, const Vec2d& b);
    double operator*(const Vec2d& a, const Vec2d& b);



#endif;