#include "vector.h"
#include <iostream>
#include <string>

Vector::Vector(const Vector& a)
{
    copy(a, *this);
}

Vector::~Vector()
{
    delete[] vec;
    vec = nullptr;
    s = 0;
    l = 0;
}

Vector::Vector(const int& size)
{
    if (size < 0) {
        throw std::invalid_argument("Invalid size of vector\n");
    }
    vec = new int[size];
    s = size;
}

Vector& Vector::operator=(const Vector& a)
{
    if (vec == a.vec
        && a.size() == s
        && a.length() == l) return *this;
    copy(a, *this);
    return *this;
}

void Vector::copy(const Vector& source, Vector& goal)
{
    delete[] goal.vec;
    goal.vec = new int[source.size()];
    for (ptrdiff_t i(0); i < source.length(); i++) {
        goal.vec[i] = source[i];
    }
    goal.s = source.size();
    goal.l = source.length();
}

void Vector::add(const int& a)
{
    if (l < s && s != 0) {
        vec[l++] = a;
        return;
    }
    else if (s == 0) {
        *this = Vector(1);
        vec[0] = a;
        l++;
        return;
    }
    else if (l >= s) {
        int *newvec = new int[s * 2];
        for (ptrdiff_t i(0); i < l; i++) {
            newvec[i] = vec[i];
        }
        newvec[l++] = a;
        delete[] vec;
        vec = newvec;
        s = s * 2;
    }
}

void Vector::resize(const int& a)
{
    if (l < a) {
        int *newvec = new int[a];
        for (ptrdiff_t i(0); i < l; i++) {
            newvec[i] = vec[i];
        }
        delete[] vec;
        vec = newvec;
        s = a;
    }
    else {
        int *newvec = new int[a];
        for (ptrdiff_t i(0); i < a; i++) {
            newvec[i] = vec[i];
        }
        delete[] vec;
        vec = newvec;
        s = a;
        l = a;
    }
}

void Vector::assign(const int& size, const int& a)
{
    delete[] vec;
    vec = new int[size];
    s = size;
    l = size;
    for (ptrdiff_t i(0); i < s; i++) {
        vec[i] = a;
    }
}

int& Vector::operator[](const ptrdiff_t ind)
{
    if (ind < 0 || ind >= l) {
        throw std::out_of_range("Vector out of range\n");
    }
    return vec[ind];
}

const int& Vector::operator[](const ptrdiff_t ind) const
{
    if (ind < 0 || ind >= l) {
        throw std::out_of_range("Vector out of range\n");
    }
    return vec[ind];
}

void Vector::pop_back()
{
    if (l != 0) l--;
    return;
}

void Vector::WriteBin(std::ofstream& ostrm)
{
    if (!ostrm.is_open()) {
        throw std::invalid_argument("Can't open file to write");
    }
    std::string siz = std::to_string(s);
    std::string len = std::to_string(l);
    for (ptrdiff_t i(0); i < siz.length(); ++i) {
        ostrm.put(static_cast<char>(siz[i]));
    }
    ostrm.put(' ');
    for (ptrdiff_t i(0); i < siz.length(); ++i) {
        ostrm.put(static_cast<char>(len[i]));
    }
    ostrm.put('\n');
    for (ptrdiff_t i(0); i < l; ++i) {
        std::string element = std::to_string(vec[i]);
        for (ptrdiff_t j(0); j < element.length(); ++j) {
            ostrm.put(static_cast<char>(element[j]));
        }
        ostrm.put(' ');
    }
}

void Vector::ReadBin(std::ifstream& istrm)
{
    if (!istrm.is_open()) {
        throw std::invalid_argument("Can't open file to read");
    }
    s = 0;
    char ch = '\n';
    while (istrm.get(ch)) {
        if (ch == ' ') break;
        s = s * 10 + (ch - '0');
    }
    l = 0;
    while (istrm.get(ch)) {
        if (ch == '\n') break;
        l = l * 10 + (ch - '0');
    }
    if (vec != nullptr) {
        delete[]vec;
    }
    vec = new int[s];
    for (ptrdiff_t i(0); i < l; ++i) {
        vec[i] = 0;
        while (istrm.get(ch)) {
            if (ch == ' ') break;
            vec[i] = vec[i] * 10 + (ch - '0');
        }
    }
}