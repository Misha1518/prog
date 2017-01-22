#include"rational.h"
#include<iostream>
void check(int a, int b, int a1, int b1)
{
    Rational z(a, b);
    Rational rhs(a1, b1);
    std::cout << "z = " << z << "\nrhs = " << rhs << '\n';
    std::cout << "z==rhs, result = " << (z == rhs) << '\n';
    std::cout << "z!=rhs, result = " << (z != rhs) << '\n';
    std::cout << "z<rhs " << (z < rhs) << '\n';
    std::cout << "z>rhs " << (z > rhs) << '\n';
    std::cout << "z = " << z << "\nz+=8.0, z = " << z << '\n';
    z += rhs;
    std::cout << "z+=" << rhs << "\nz = " << z << '\n';
    z *= rhs;
    std::cout << "z*=" << rhs << "\nz = " << z << '\n';
    z -= rhs;
    std::cout << "z-=" << rhs << "\nz = " << z << '\n';
}
int main()
{
    check(2, 5, 4, 12);
    check(6, 7, 6, 7);
    check(-1, 4, -2, 7);
    check(0, 1, 5, 12);
    check(1, 1, 1, 1);
    try
    {
        std::cout << "Constructing rational with denominator 0\n";
        Rational b(0, 0);
    }
    catch (std::invalid_argument)
    {
        std::cout << "Exception catched!\n";
    }
}