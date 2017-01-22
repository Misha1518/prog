#include "matrix2d.h"
#include <iostream>

using namespace std;

void check(Matrix2d<int>& b, Matrix2d<int>& a)
{
    Matrix2d<int> z(b);
    Matrix2d<int> rhs(a);
    std::cout << "Start of test\n";
    std::cout << "z = \n" << z << "\nrhs = \n" << rhs << '\n';
    z += rhs;
    std::cout << "Check operator +=, z+=rhs\nz = \n" << z << '\n';
    z *= rhs;
    std::cout << "Check operator *=, z*=rhs\nz = \n" << z << '\n';
    z -= rhs;
    std::cout << "Check operator -=, z-=rhs\nz = \n" << z << '\n';
    std::cout << "End of tests\n";
}

int main()
{
    Matrix2d<int> checker(3, 3);
    checker.at(0, 0) = 1;
    checker.at(0, 1) = 2;
    checker.at(0, 2) = 3;
    checker.at(1, 0) = 4;
    checker.at(1, 1) = 5;
    checker.at(1, 2) = 6;
    checker.at(2, 0) = 7;
    checker.at(2, 1) = 8;
    checker.at(2, 2) = 9;
    check(checker, checker);
    Matrix2d<int> checker2(3, 1);
    checker2.at(0, 0) = -5;
    checker2.at(1, 0) = -6;
    checker2.at(2, 0) = -7;
    try {
        cout << "Try to use invalid element(in Matrix(3,1) use at(3,3))\n";
        cout << checker.at(3, 3);
    }
    catch (invalid_argument) {
        cout << "Exception catched!\n";
    }
    try {
        cout << "Try to use invalid element(in Matrix(3,1) use at(-5,0))\n";
        cout << checker.at(-5, 0);
    }
    catch (invalid_argument) {
        cout << "Exception catched!\n";
    }
    try {
        cout << "Try to use invalid constructor(Matrix2d(-5,3))\n";
        cout << checker.at(-5, 3);
    }
    catch (invalid_argument) {
        cout << "Exception catched!\n";
    }
    try {
        cout << "Try to use invalid constructor(Matrix2d(2,-5))\n";
        cout << checker.at(2, -5);
    }
    catch (invalid_argument) {
        cout << "Exception catched!\n";
    }
    cout << "Check operator* in Matrix2d with different types\n";
    cout << "of Matrix(Matrix2d(3, 3)*Matrix2d(3, 1))\n";
    cout << "Checker = \n" << checker;
    cout << "Rhs = \n" << checker2;
    Matrix2d<int> result = checker * checker2;
    cout << "Result = \n" << result;
    try {
        cout << "Try to use operator+= with different types\n";
        cout << "of Matrix2d(Matrix2d(3, 3) += Matrix2d(3, 1))\n";
        cout << "Checker = \n" << checker;
        cout << "Rhs = \n" << checker2;
        checker += checker2;
    }
    catch (invalid_argument) {
        cout << "Exception catched!\n";
    }
    int n;
    cin >> n;
}