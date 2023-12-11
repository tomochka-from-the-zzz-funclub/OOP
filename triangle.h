#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>
#include "figure.h"

template <typename T>
class triangle: public figure<t> {
private:
    point<T> A;
    point<T> B;
    point<T> C;
public:
    triangle();
    triangle(point<T> a, point<T> b, point<T> c);
    triangle(triangle<T>& other);

    point<T> get_a() const;
    point<T> get_b() const;
    point<T> get_c() const;
    void set_a(point<T> a);
    void set_b(point<T> b);
    void set_c(point<T> c);

    point<T> geometric_centre();
    operator double() const; // находим площадь
};
template <typename T>
bool validate(const point<T>& a, const point<T>& b, const point<T>& c) noexcept;
template <typename T>
bool operator==(triangle<T>& one_sq, triangle<T>& two_tri);
template <typename T>
std::istream& operator>>(std::istream& is, triangle<T>& tri);
template <typename T>
std::ostream& operator<<(std::ostream& os, triangle<T>& tri);
template class triangle<int>;
template class triangle<double>;
template class triangle<float>;
#endif 