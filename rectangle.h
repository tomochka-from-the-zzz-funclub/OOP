#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <cmath>
#include "figure.h"

class rectangle: public figure {
private:
    point A;
    point B;
    point C;
    point D;
public:
    rectangle();
    rectangle(point a, point b, point c, point d);
    rectangle(rectangle& other);

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
    friend bool operator==(rectangle& one_sq, rectangle& two_sq);
    friend std::istream& operator>>(std::istream& is, rectangle& rec);
    friend std::ostream& operator<<(std::ostream& os, rectangle& rec);
};
#endif 