#include "point.h"

#include <cmath>
using namespace std;
template <class T>
point<T>::point(): X(0), Y(0) {}

template <typename T>
point<T>::point(T x, T y) : X{x}, Y{y} {}

template <typename T>
point<T>::point(const point<T>& other) : X(other.get_x()), Y(other.get_y()) {}

template <typename T>
double dist(point<T> one, point<T> two) {
  double dx = (one.get_x() - two.get_x());
  double dy = (one.get_y() - two.get_y());
  return std::sqrt(dx*dx + dy*dy);
}

template <typename T>
T point<T>::get_x() const{
    return this->X;
}
template <typename T>

T point<T>::get_y() const{
    return this->Y;
}

template <typename T>
void point<T>::set_x(T x_){
    this->X = x_;
}

template <typename T>
void point<T>::set_y(T y_){
    this->Y = y_;
}

template <typename T>
std::istream& operator>>(std::istream& is, point<T>& p)  {
  T x, y;
  is >> x >> y;
  p.set_x(x);
  p.set_y(y);
  return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os,const point<T>& p) {
  os << "(" << p.get_x() << ", " << p.get_y() << ")";
  return os;
}

template <typename T>
bool operator==(const point<T>& one, const point<T>& two){
  if((one.get_x() == two.get_x()) && (one.get_y() == two.get_y())) {
    return true;
  }
  return false;
}