
#ifndef SQUARE_H
#define SQUARE_H
#pragma once

#include <iostream>
#include <cmath>
#include "figure.h"

template <typename T>
class square: public figure<T> {
private:
    point<T> A;
    point<T> B;
    point<T> C;
    point<T> D;
public:
    square();
    square(point<T> a, point<T> b, point<T> c, point<T> d);
    square(square<T>& other);
    point<T> geometric_centre();
    operator double() const; // находим площадь

    point<T> get_a() const;
    point<T> get_b() const;
    point<T> get_c() const;
    point<T> get_d() const;
    void set_a(point<T> a);
    void set_b(point<T> b);
    void set_c(point<T> c);
    void set_d(point<T> d);
};
template<typename T>
bool validate( point<T>& a,  point<T>& b,  point<T>& c,  point<T>& d) noexcept;
template<typename T>
bool operator==(square<T>& one_sq, square<T>& two_sq);
template<typename T>
std::istream& operator>>(std::istream& is, square<T>& s);
template<typename T>
std::ostream& operator<<(std::ostream& os, square<T>& s);
template class square<int>;
template class square<double>;
template class square<float>;
#endif 