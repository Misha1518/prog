#include<iostream>
#include <conio.h>
void output(int a, int b, int result)
{
    std::cout << "a = " << a << "\nb = " << b << '\n';
    std::cout << "gcd(a,b) = " << abs(result) << '\n';
}
void g(int a, int b)
{
    int a1;
    int b1;
    a1 = a;
    b1 = b;
    if (a == 0 || b == 0)
    {
        output(a, b, (abs(a) > abs(b)) ? abs(a) : abs(b));
        return;
    }
    while (a1%b1 != 0)
    {
        if (abs(a1) < abs(b1))
        {
            int temp = a1;
            a1 = b1;
            b1 = temp;
        }
        if (a1%b1 != 0) a1 = a1%b1;
    }
    output(a, b, abs(b1));
}
int main()
{
    g(18, 18);
    g(34, 17);
    g(1, 17);
    g(1000000005, 1000000009);
    g(-9, 3);
    g(6, -3);
    g(0, 8);
    _getch();
}