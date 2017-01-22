#ifndef _HG_MATRIX2D_24102016
#define _HG_MATRIX2D_24102016
#include <iostream>

template<class T>
class Matrix2d {
public:
    Matrix2d() = default;
    Matrix2d(const Matrix2d<T>& a);
    Matrix2d(const int& n, const int& m);
    ~Matrix2d();
    const int& columnsize() const { return n; }
    const int& rowsize() const { return m; }
    Matrix2d<T>& operator=(const Matrix2d<T>& a);
    Matrix2d<T>& operator*=(const Matrix2d<T>& a);
    Matrix2d<T>& operator+=(const Matrix2d<T>& a);
    Matrix2d<T>& operator-=(const Matrix2d<T>& a);
    void copy(const Matrix2d<T>& source, Matrix2d<T>& goal);
    T& at(const ptrdiff_t ind1, const ptrdiff_t ind2);
    const T& at(const ptrdiff_t ind1, const ptrdiff_t ind2) const;
    std::ostream& writeTo(std::ostream& ostrm) const;
private:
    T* matr = nullptr;
    ptrdiff_t n = 0;
    ptrdiff_t m = 0;
};
template<class T>
Matrix2d<T> operator*(const Matrix2d<T>& a, const Matrix2d<T>& b);

template<class T>
Matrix2d<T> operator+(const Matrix2d<T>& a, const Matrix2d<T>& b);

template<class T>
Matrix2d<T> operator-(const Matrix2d<T>& a, const Matrix2d<T>& b);

template<class T>
std::ostream& operator<<(std::ostream& ostrm, const Matrix2d<T>& a);

template<class T>
Matrix2d<T>::Matrix2d(const int& n, const int& m) :n(n), m(m)
{
    if (n < 0 || m < 0) {
        throw std::invalid_argument("Invalid size of matrix\n");
    }
    matr = new int[n*m];
}

template<class T>
Matrix2d<T>::~Matrix2d()
{
    delete[] matr;
    matr = nullptr;
    n = 0;
    m = 0;
}

template<class T>
void Matrix2d<T>::copy(const Matrix2d<T>& source, Matrix2d<T>& goal)
{
    goal.matr = new int[source.rowsize()*source.columnsize()];
    int newsize = source.n*source.m;
    for (ptrdiff_t i(0); i < newsize; i++) {
        goal.matr[i] = source.matr[i];
    }
    goal.n = source.n;
    goal.m = source.m;
}

template<class T>
Matrix2d<T>::Matrix2d(const Matrix2d<T>& a)
{
    copy(a, *this);
}

template<class T>
T& Matrix2d<T>::at(const ptrdiff_t ind1, const ptrdiff_t ind2)
{
    if (ind1 < 0 || ind2 < 0 || ind1 >= n || ind2 >= m) {
        throw std::invalid_argument("Invalid index in operator[][]\n");
    }
    return matr[ind1*m + ind2];
}

template<class T>
const T& Matrix2d<T>::at(const ptrdiff_t ind1, const ptrdiff_t ind2) const
{
    if (ind1 < 0 || ind2 < 0 || ind1 >= n || ind2 >= m) {
        throw std::invalid_argument("Invalid index in operator[][]\n");
    }
    return matr[ind1*m + ind2];
}

template<class T>
Matrix2d<T>& Matrix2d<T>::operator=(const Matrix2d<T>& a)
{
    if (a.matr == matr && a.n == n && a.m == m) return *this;
    copy(a, *this);
    return *this;
}

template<class T>
Matrix2d<T>& Matrix2d<T>::operator*=(const Matrix2d<T>& a)
{
    if (m != a.columnsize()) {
        throw std::invalid_argument("Invalid use of operator*= in Matrix2d\n");
    }
    Matrix2d<T> result(n, a.rowsize());
    for (ptrdiff_t i(0); i < n; i++) {
        for (ptrdiff_t j(0); j < a.rowsize(); j++) {
            double sum = 0.0;
            for (int z = 0; z < n; z++) {
                sum += ((at(i, z)) * (a.at(z, j)));
            }
            result.at(i, j) = sum;
        }
    }
    delete[] matr;
    matr = new int[result.rowsize()*result.columnsize()];
    n = result.columnsize();
    m = result.rowsize();
    copy(result, *this);
    return *this;
}

template<class T>
Matrix2d<T> operator*(const Matrix2d<T>& a, const Matrix2d<T>& b)
{
    if (a.rowsize() != b.columnsize()) {
        throw std::invalid_argument("Invalid use of operator* in Matrix2d\n");
    }
    Matrix2d<T> result(a);
    result *= b;
    return result;
}

template<class T>
Matrix2d<T>& Matrix2d<T>::operator+=(const Matrix2d<T>& a)
{
    if (n != a.columnsize() || m != a.rowsize()) {
        throw std::invalid_argument("Invalid use of operator +=\n");
    }
    for (ptrdiff_t i(0); i < n; i++) {
        for (ptrdiff_t j(0); j < m; j++) {
            at(i, j) += a.at(i, j);
        }
    }
    return *this;
}

template<class T>
Matrix2d<T> operator+(const Matrix2d<T>& a, const Matrix2d<T>& b)
{
    if (b.columnsize() != a.columnsize() || b.rowsize() != a.rowsize()) {
        throw std::invalid_argument("Invalid use of operator +\n");
    }
    Matrix2d<T> result(a);
    result += b;
    return result;
}

template<class T>
Matrix2d<T>& Matrix2d<T>::operator-=(const Matrix2d<T>& a)
{
    if (n != a.columnsize() || m != a.rowsize()) {
        throw std::invalid_argument("Invalid use of operator -=\n");
    }
    for (ptrdiff_t i(0); i < n; i++) {
        for (ptrdiff_t j(0); j < m; j++) {
            at(i, j) -= a.at(i, j);
        }
    }
    return *this;
}

template<class T>
Matrix2d<T> operator-(const Matrix2d<T>& a, const Matrix2d<T>& b)
{
    if (b.rowsize() != a.rowsize() || b.columnsize() != a.columnsize()) {
        throw std::invalid_argument("Invalid use of operator -\n");
    }
    Matrix2d<T> result(a);
    result -= b;
    return result;
}

template<class T>
std::ostream& Matrix2d<T>::writeTo(std::ostream& ostrm) const {
    for (ptrdiff_t i(0); i < n; i++) {
        for (ptrdiff_t j(0); j < m; j++) {
            ostrm << at(i, j) << ' ';
        }
        ostrm << '\n';
    }
    return ostrm;
}

template<class T>
std::ostream& operator<<(std::ostream& ostrm, const Matrix2d<T>& a)
{
    return a.writeTo(ostrm);
}

#endif