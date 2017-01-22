#ifndef _HG_RATIONAL_H_26092016
#define _HG_RATIONAL_H_26092016
#include<iostream>
class Rational
{
public:
    Rational() {}
    explicit Rational(const int32_t val) :num_(val) {}
    Rational(const int32_t num, const int32_t denum);
    void Normalize(Rational& a);
    Rational& operator+=(const Rational& b);
    Rational& operator+(const Rational& b);
    Rational& operator-=(const Rational& b);
    Rational& operator-(const Rational& b);
    Rational& operator*=(const Rational& b);
    Rational& operator*(const Rational& b);
    Rational& operator=(const Rational& rhs) = default;
    bool operator<(const Rational& b);
    bool operator>(const Rational& b);
    bool operator==(const Rational& b);
    bool operator!=(const Rational& b) { return !operator==(b); }
    void Write()
    {
        std::cout << num_ << '/' << denum_ << '\n';
    }
    void WriteTo(std::ostream& out)
    {
        out << num_ << '/' << denum_ << '\n';
    }
private:
    int32_t num_{ 0 };
    int32_t denum_{ 1 };

};
std::ostream& operator<<(std::ostream& ostrm, Rational& b);
#endif //