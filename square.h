#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <cmath>
#include <memory>
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
    static bool validate(const point<T>& a, const point<T>& b, const point<T>& c, const point<T>& d) noexcept;
};
    template<class T>
    bool operator==(square<T>& one_sq, square<T>& two_sq);
    template<class T>
    std::istream& operator>>(std::istream& is, square<T>& s);
    template<class T>
    std::ostream& operator<<(std::ostream& os, square<T>& s);
#endif 