#include<iostream>
#include"complex.h"
void check(double real, double imaginary, double rhsreal, double rhsimaginary)
{
    Complex z(real, imaginary);
    Complex rhs(rhsreal, rhsimaginary);
    std::cout << "z = " << z << "\nrhs = " << rhs << '\n';
    std::cout << "z==rhs, result = " << (z == rhs) << '\n';
    std::cout << "z!=rhs, result = " << (z != rhs) << '\n';
    z += 8.0;
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
    check(0, 0, 4, 3);
    check(5, 0, 5, 0);
    check(4, 3, 100.9, 100.4);
    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9,9");
}