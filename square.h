#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <cmath>
#include "figure.h"

class square: public figure {
private:
    point A;
    point B;
    point C;
    point D;
public:
    square();
    square(point a, point b, point c, point d);
    square(square& other);

    point get_a() const;
    point get_b() const;
    point get_c() const;
    point get_d() const;
    void set_a(point a);
    void set_b(point b);
    void set_c(point c);
    void set_d(point d);

    point geometric_centre();
    operator double() const; // находим площадь
    static bool validate(const point& a, const point& b, const point& c, const point& d) noexcept;
    friend bool operator==(square& one_sq, square& two_sq);
    friend std::istream& operator>>(std::istream& is, square& s);
    friend std::ostream& operator<<(std::ostream& os, square& s);
};
#endif 