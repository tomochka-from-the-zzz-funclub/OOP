#include "point.h"

#include <cmath>

template <class T>
point<T>::point(): X(0), Y(0) {}

template <typename T>
point<T>::point(T x, T y) : X{x}, Y{y} {}

template <typename T>
point<T>::point(point<T>& other) : X(other.X), Y(other.Y) {}

template <typename T>
point<T>::point(const point<T>& other) : X(other.X), Y(other.Y) {}

template <typename T>
double dist(point<T>& one, point<T>& two) {
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
std::istream& operator>>(std::istream& is, point<T>& p)  {
  is >> p.X >> p.Y;
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