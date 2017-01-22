#include "vector.h"
#include <iostream>

using namespace std;

void check(const Vector& a)
{
    std::cout << "Start of Test\n";
    std::cout << "Check = operator\n";
    std::cout << "Vector a = ";
    for (ptrdiff_t i(0); i < a.length(); i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
    std::cout << "test = a\n";
    Vector test(a);
    std::cout << "Vector test = ";
    for (ptrdiff_t i(0); i < test.length(); i++) {
        std::cout << test[i] << ' ';
    }
    std::cout << '\n';
    std::cout << "Check size() function -> test.size() = ";
    std::cout << test.size() << ", a.size() = " << a.size() << '\n';
    std::cout << "Check length() function -> test.length() = ";
    std::cout << test.length() << ", a.length() = " << a.length() << '\n';
    std::cout << "Check resize() function -> test.resize(1), test.size() = ";
    test.resize(1);
    std::cout << test.size() << ", a.size() = " << a.size() << '\n';
    test.resize(5);
    std::cout << "test.resize(5), test.size() = " << test.size() << '\n';
    std::cout << "Check add() function -> test.add(6)\ntest = ";
    test.add(6);
    for (ptrdiff_t i(0); i < test.length(); i++) {
        std::cout << test[i] << ' ';
    }
    std::cout << '\n';
    std::cout << "Check assign() function -> test.assign(3, 0)\ntest = ";
    test.assign(3, 0);
    for (ptrdiff_t i(0); i < test.length(); i++) {
        std::cout << test[i] << ' ';
    }
    std::cout << "Check pop_back() function -> test.pop_back()\ntest = ";
    test.pop_back();
    for (ptrdiff_t i(0); i < test.length(); i++) {
        std::cout << test[i] << ' ';
    }
    std::cout << "End of tests\n";
}

int main()
{
    Vector a = Vector(5);
    a.add(4);
    a.add(3);
    a.add(5);
    a.add(1);
    a.add(3);
    check(a);
    std::cout << "Try to construct Vector with wrong size\n";
    try {
        Vector b(-5);
    }
    catch (std::invalid_argument) {
        std::cout << "Exception catched!\n";
    }
    std::cout << "Try to use wrong operator[]\n";
    try {
        std::cout << a[-3];
    }
    catch (std::out_of_range) {
        std::cout << "Exception catched!\n";
    }
    try {
        std::cout << a[8];
    }
    catch (std::out_of_range) {
        std::cout << "Exception catched!\n";
    }
    std::cout << "Vector a = ";
    for (ptrdiff_t i(0); i < a.size(); i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
    std::cout << "Check operator a = a\n";
    std::cout << "Vector a = ";
    a = a;
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << ", a = a\n";
    std::cout << "Vector a = ";
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << "\nTry to Write and Read Binary Files\n";
    std::ifstream istrm("fstream.txt", std::ios::binary || std::ios::in);
    std::ofstream ostrm("fstream.txt", std::ios::binary || std::ios::out);
    a.WriteBin(ostrm);
    a.ReadBin(istrm);
    std::cout << "Vector a = ";
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << ' ';
    }
}