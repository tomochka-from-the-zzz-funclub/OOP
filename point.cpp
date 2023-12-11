#include "point.h"

#include <cmath>


point::point(): X(0), Y(0) {}
point::point(double x, double y) : X(x), Y(y) {}

point::point(point& other) : X(other.X), Y(other.Y) {}

point::point(const point& other) : X(other.X), Y(other.Y) {}

double dist(point one, point two) {
  double dx = (one.get_x() - two.get_x());
  double dy = (one.get_y() - two.get_y());
  return std::sqrt(dx*dx + dy*dy);
}

double point::get_x() const{
    return this->X;
}

double point::get_y() const{
    return this->Y;
}

std::istream& operator>>(std::istream& is, point& p)  {
  is >> p.X >> p.Y;
  return is;
}

std::ostream& operator<<(std::ostream& os,const point& p) {
  os << "(" << p.X << ", " << p.Y << ")";
  return os;
}

bool operator==(const point& one, const point& two){
  if((one.get_x() == two.get_x()) && (one.get_y() == two.get_y())) {
    return true;
  }
  return false;
}

