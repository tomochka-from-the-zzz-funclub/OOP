#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>
#include "figure.h"

class triangle: public figure {
private:
    point A;
    point B;
    point C;
public:
    triangle();
    triangle(const point& a, const point& b, const point& c);
    triangle(triangle& other);
    point geometric_centre();
    operator double() const; // находим площадь
    static bool validate(const point& a, const point& b, const point& c) noexcept;
    friend bool operator==(triangle& one_sq, triangle& two_sq);
    friend std::istream& operator>>(std::istream& is, triangle& s);
    friend std::ostream& operator<<(std::ostream& os, triangle& s);
};
#endif 