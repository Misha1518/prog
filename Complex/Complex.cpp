#include<iostream>
#include<cmath>
#include<cstdint>
#include<string>
#include<sstream>
#include"complex.h"
Complex& Complex::operator*=(const double rhs)
{
    im *= rhs;
    re *= rhs;
    return *this;
}
Complex& Complex::operator+=(const Complex& a)
{
    re += a.re;
    im += a.im;
    return *this;
}
Complex operator+(const Complex& a, const Complex& b)
{
    Complex sum(a);
    sum += b;
    return sum;
}
Complex operator-(const Complex& a, const Complex& b)
{
    Complex con(a);
    con -= b;
    return con;
}
std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}
std::istream& Complex::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    double real(0.0);
    char separator(0);
    double imag(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> separator >> imag >> rightBrace;
    if (istrm.good())
    {
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == separator) && (Complex::rightBrace == rightBrace))
        {
            re = real;
            im = imag;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}
inline std::istream& operator >> (std::istream& istrm, Complex& rhs)
{
    return rhs.readFrom(istrm);
}
inline std::ostream& operator<< (std::ostream& ostrm, const Complex& a)
{
    return a.writeTo(ostrm);
}
Complex& Complex::operator-=(const Complex& a)
{
    re -= a.re;
    im -= a.im;
    return *this;
}
Complex& Complex::operator*=(const Complex& a)
{
    re *= a.re;
    im *= a.im;
    return *this;
}
Complex::Complex(const double real) :Complex(real, 0) {}
bool testParse(const std::string& str)
{
    std::istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (istrm.good())
    {
        std::cout << "Read success: " << str << " -> " << z << '\n';
    }
    else
    {
        std::cout << "Read error : " << str << " -> " << z << '\n';
    }
    return istrm.good();
}