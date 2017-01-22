#ifndef _HG_COMPLEX_H_26092016
#define _HG_COMPLEX_H_26092016
#include<iostream>
class Complex
{
private:
    double re{ 0.0 };
    double im{ 0.0 };
public:
    Complex() {}
    Complex& operator+=(const Complex& a);
    Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
    Complex& operator-=(const Complex& a);
    Complex& operator*=(const Complex& a);
    Complex& operator*=(const double rhs);
    bool operator==(const Complex& a) const { return (abs(re - a.re)<1e-7) && (abs(im - a.im)<1e-7); };
    bool operator!=(const Complex& b) const { return !operator==(b); };
    std::ostream& writeTo(std::ostream& ostrm)const;
    std::istream& readFrom(std::istream& istrm);
    explicit Complex(const double real);
    Complex(const double re, const double im) :re(re), im(im) {};
    static const char leftBrace{ '{' };
    static const char rightBrace{ '}' };
    static const char separator{ ',' };
};
bool testParse(const std::string& str);
inline std::istream& operator >> (std::istream& istrm, Complex& rhs);
inline std::ostream& operator<< (std::ostream& ostrm, const Complex& a);
#endif //