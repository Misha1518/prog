#ifndef _HG_VECTOR_17102016
#define _HG_VECTOR_17102016

#include <iostream>
#include <fstream>

class Vector {
public:
    Vector() {}
    Vector(const Vector& a);
    ~Vector();
    Vector(const int& size);
    Vector& operator= (const Vector& rhs);
    int& operator[](const ptrdiff_t ind);
    const int& operator[](const ptrdiff_t ind) const;
    ptrdiff_t size() const { return s; }
    ptrdiff_t length() const { return l; }
    void resize(const int& a);
    void add(const int& a);
    void assign(const int& size, const int& a);
    void pop_back();
    void copy(const Vector& source, Vector& goal);
    void WriteBin(std::ofstream& out);
    void ReadBin(std::ifstream& to);
private:
    int* vec = nullptr;
    ptrdiff_t s = 0;
    ptrdiff_t l = 0;
};

#endif