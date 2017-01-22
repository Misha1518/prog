#include<iostream>
#include<cmath>
#include<cstdint>
#include<string>
#include"rational.h"
int gcd(int a, int b)
{
    if (abs(a) > abs(b))
    {
        int temp = a;
        a = b;
        b = temp;
    }
    while (a%b != 0)
    {
        a = a%b;
        int temp = a;
        a = b;
        b = temp;
    }
    return abs(b);
}
void Rational::Normalize(Rational& a)
{
    int k = gcd(a.num_, a.denum_);
    a = Rational(a.num_ / k, a.denum_ / k);
}
std::ostream& operator<<(std::ostream& ostrm, Rational& b)
{
    b.WriteTo(ostrm);
    return ostrm;
}
Rational& Rational::operator*=(const Rational& b)
{
    num_ *= b.num_;
    denum_ *= b.denum_;
    Normalize(*this);
    return *this;
}
Rational& Rational::operator-=(const Rational& b)
{
    *this = Rational(num_*b.denum_ - b.num_*denum_, denum_*b.denum_);
    Normalize(*this);
    return *this;
}
Rational& Rational::operator+=(const Rational& b)
{
    *this = Rational(num_*b.denum_ + b.num_*denum_, denum_*b.denum_);
    Normalize(*this);
    return *this;
}
Rational& Rational::operator+(const Rational& b)
{
    Rational sum(num_, denum_);
    sum += b;
    return sum;
}
Rational& Rational::operator-(const Rational& b)
{
    Rational con(num_, denum_);
    con -= b;
    return con;
}
Rational& Rational::operator*(const Rational& b)
{
    Rational prod(num_, denum_);
    prod *= b;
    return prod;
}
bool Rational::operator<(const Rational& b)
{
    return (num_*b.denum_ < b.num_*denum_);
}
bool Rational::operator>(const Rational& b)
{
    return (!operator<(b) && !operator==(b));
}
bool Rational::operator==(const Rational& b)
{
    return (((num_ *b.denum_) / (denum_*b.num_)) == 1);
}
Rational::Rational(const int32_t num, const int32_t denum) :num_(num), denum_(denum)
{
    if (denum == 0)
    {
        throw std::invalid_argument("Construct error -> Zero division in Rational\n");
    }
}