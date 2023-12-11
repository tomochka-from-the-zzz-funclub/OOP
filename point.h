#pragma once
#ifndef POINT_H
#define POINT_H

#include <iostream>
template <typename T>
class point {
protected:
    T X;
    T Y;
public:
    point();
    point(T x, T y);
    point(point<T>& other);
    point(const point<T>& other);

    T get_x() const;
    T get_y() const;
    void set_x(T x_);
    void set_y(T y_);

};
template<class T>
double dist(point<T> one, point<T> twe);
template<class T>
std::istream& operator>>(std::istream& is, point<T>& p);
template<class T>
std::ostream& operator<<(std::ostream& os, const point<T>& p);
template<class T>
bool operator==(const point<T>& one, const point<T>& two);
//template<class T>
/*
 template class point<int>;
 template class point<double>;
 template class point<float>;
*/
#endif 
