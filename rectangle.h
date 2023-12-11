#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <cmath>
#include "figure.h"
template <typename T>
class rectangle: public figure<T> {
private:
    point<T> A;
    point<T> B;
    point<T> C;
    point<T> D;
public:
    rectangle();
    rectangle(point<T> a, point<T> b, point<T> c, point<T> d);
    rectangle(rectangle<T>& other);

    point<T> get_a() const;
    point<T> get_b() const;
    point<T> get_c() const;
    point<T> get_d() const;
    void set_a(point<T> a);
    void set_b(point<T> b);
    void set_c(point<T> c);
    void set_d(point<T> d);
    
    point<T> geometric_centre();
    operator double() const; // находим площадь
};
template <typename T>
bool validate(const point<T>& a, const point<T>& b, const point<T>& c, const point<T>& d) noexcept;
template <typename T>
bool operator==(rectangle<T>& one_sq, rectangle<T>& two_sq);
template <typename T>
std::istream& operator>>(std::istream& is, rectangle<T>& rec);
template <typename T>
std::ostream& operator<<(std::ostream& os, rectangle<T>& rec);
template class rectangle<int>;
template class rectangle<double>;
template class rectangle<float>;
#endif 