#include "vec2d.h"
#include<iostream>

void check(double lhsx, double lhsy, double rhsx, double rhsy)
{
    Vec2d a(lhsx, lhsy);
    Vec2d b(rhsx, rhsy);
    std::cout << "Vector a = " << a << '\n';
    std::cout << "Vector b = " << b << '\n';
    std::cout << "a==b, result " << (a == b) << '\n';
    std::cout << "a!=b, result " << (a != b) << '\n';
    std::cout << "a+b, result " << (a + b) << '\n';
    std::cout << "a-b, result " << (a - b) << '\n';
    a *= 8.0;
    std::cout << "a*=double(8.0), result " << a << '\n';
    b = a;
    std::cout << "b = a, result " << b << '\n';
    std::cout << "now a -> " << a << '\n';
    std::cout << "now b -> " << b << '\n';
    a += b;
    std::cout << "a+=b, result " << a << '\n';
    a -= b;
    std::cout << "a-=b, result " << a << '\n';
    std::cout << "End of tests\n";
}
int main()
{
    check(0.0, 1.0, 1.0, 0.0);
    check(2.0, -2.0, -2.0, 2.0);
    check(5.0, 5.0, 5.0, 5.0);
    check(7.0, 0.0, 0.0, 7.0);
    Vec2d a(5, 4);
    std::cout << "Test with == operator\n";
    check(0.0000001, 0.00000001, 0.0, 0.0);
    check(0.004, 0.004, 0.0, 0.0);
    try {
        std::cout << "Try to call indexator more than 2\n";
        std::cout << a[3];
    }
    catch (std::out_of_range)
    {
        std::cout << "Exception catched!\n";
    }
}