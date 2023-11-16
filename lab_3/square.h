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
    square(std::istream &is);
    point geometric_center();
    operator double() const; // находим площадь
    friend std::istream& operator>>(std::istream& is, square& s);
    friend std::ostream& operator<<(std::ostream& os, square& s);
};
square check_point(point a, point b, point c, point d);
#endif 